#include<stdio.h>
#include<stdlib.h>

void doFlip(int *p, int );
void flip(int *p, int size, int n);
int getMaxP(int *p, int index);

main(){
  FILE *fp;
  char c;
  int pan[30]= {};
  int i = 0;
  fp = fopen( "stacks.in", "r");
  while(!feof(fp)){
    fscanf(fp, "%d", &pan[i]);
    c = fgetc(fp); i++;
    if(c=='\n'){
      doFlip(pan, i);
      i=0;
    }
  }
}

void doFlip(int *p, int s){
  int *pan, i;
  int point = s-1;
  pan = (int *)malloc(s*sizeof(int));
  for(i=0; i<s ; i++){
    pan[i] = p[i];
  }
  for(i=0; i<s ; i++){
    printf("%d ", pan[i]);
  }
  printf("\n");
  for(i=0 ; i<s ; i++){
    if( getMaxP(pan, point) == point){
      break;
    }else if( getMaxP(pan, point) == 0){
      flip(pan, s, point);
    }else{
      flip(pan, s, getMaxP(pan, point));
      flip(pan, s, point);
    }
    point--;
  }
  printf("0\n");
}

void flip(int *p, int size, int point){
  int *tmp, i;
  int tmps = point+1;
  tmp = (int *)malloc( tmps*sizeof(int));
  for(i=0 ; i<tmps ; i++){
    tmp[i] = p[i];
  }
  for(i=0 ; i<tmps ; i++){
    p[i] = tmp[tmps-i-1];
  }
  printf("%d ", size-point);
}

int getMaxP(int *p, int point){
  int i;
  int maxP = 0;
  int max = 0;
  for(i=0 ; i<=point ; i++){
    if(p[i] > max){
      max = p[i];
      maxP = i;
    }
  }
  return maxP;
}

