// 0001
#include<stdio.h>

void printMax(int M[]){
  int i, m = 0;
  for ( i = 0; i < 10; i++ ){
    if ( M[m] < M[i] ) m = i;
  }
  printf("%d\n", M[m]);
  M[m] = -1;
}

int main(){
  int M[10], i;
  for ( i = 0; i < 10; i++ ) scanf("%d", &M[i]);
  for ( i = 0; i < 3; i++ ) printMax(M);
}
