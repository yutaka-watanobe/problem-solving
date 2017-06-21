// @JUDGE_ID:  17051CA  101  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>

#define EMPTY -1
int getPosition(int);
void remove(int);
void add(int, int);
void moveOnto(int, int);
void moveOver(int, int);
void pileOnto(int, int);
void pileOver(int, int);
void returning(int);
void printResult();

int space[30][30];
int N;

main(){

  scanf("%d", &N);

  for(int i=0; i<30; i++){
    for(int j=0; j<30; j++){
      space[i][j] = EMPTY;
    }
  }

  for(int i=0; i<N; i++){
    space[i][0] = i;
  }

  while(1){
    char c1[10], c2[10];
    int  i1, i2;
    scanf("%s", c1);

    if ( !strcmp(c1, "quit" ) ) break;

    scanf("%d", &i1);
    scanf("%s", c2);
    scanf("%d", &i2);

    string com1 = c1;
    string com2 = c2;
    /*if( com1 == "quit") break;*/
    
    if( i1 == i2 || getPosition(i1) == getPosition(i2) || i1 < 0 || i2 < 0 || i1 >= N || i2 >= N){
      /* ignore */
    }else{
      if( com1 == "move" && com2 == "onto"){
	moveOnto(i1, i2);
      }else if( com1 == "move" && com2 == "over"){
	moveOver(i1, i2);
      }else if( com1 == "pile" && com2 == "onto"){
	pileOnto(i1, i2);
      }else if( com1 == "pile" && com2 == "over"){
	pileOver(i1, i2);
      }
      /*cout << "command error " << "com1 " << com1 << " com2 " << com2 << endl; */
    }
  }

  printResult();
  return 0;
}

void printResult(){
  for(int i=0; i<N; i++){
    printf("%d:", i);
    int j=0;
    while( space[i][j] != EMPTY){
      printf(" %d", space[i][j]);
      j++;
    }
    printf("\n");
  }
  /*
  for(int i=0; i<N; i++){
    printf("%d:", i);
    for(int j=0; j<N; j++){
      printf(" %d", space[i][j]);
    }
    printf("\n");
  }
  */
}
void moveOnto(int a, int b){
  returning(a);
  returning(b);
  remove(a);
  add(getPosition(b), a);
}

void moveOver(int a, int b){
  returning(a);
  remove(a);
  add(getPosition(b), a);
}

void pileOnto(int a, int b){
  returning(b);
  int i = getPosition(a);
  int j = 0;
  while( space[i][j] != a ) j++;
  while( space[i][j] != EMPTY){
    int mBlock = space[i][j];
    remove( space[i][j] );
    add(getPosition(b), mBlock);
    j++;
  }
}

void pileOver(int a, int b){
  int i = getPosition(a);
  int j = 0;
  while( space[i][j] != a ) j++;
  while( space[i][j] != EMPTY){
    int mBlock = space[i][j];
    remove( mBlock );
    add(getPosition(b), mBlock);
    j++;
  }
}

void returning(int a){ /* return blocks that are stacked on top of block a*/
  int i = getPosition(a);
  int j = 0;
  while( space[i][j] != a) j++;
  j++;
  while( space[i][j] != EMPTY){
    int b = space[i][j];
    remove(b);
    add(b, b);
    j++;
  }
}
 
int getPosition(int a){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( space[i][j] == a) return i;
    }
  }
}

void add(int i, int a){
  int j=0;
  while(space[i][j] != EMPTY){
    j++;
  }
  space[i][j] = a;
}

void remove(int a){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( space[i][j] == a) {
	space[i][j] = EMPTY;
	break;
      }
    }
  }
}
// @end_of_source_code
