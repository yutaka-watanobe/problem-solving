// @JUDGE_ID:  17051CA  229  C++
// @begin_of_source_code
#include<stdio.h>
#define EMPTY -1
#define SPACE 0
#define OBJ   1

int a1[10];
int a2[24];
int a3[15];
int a4[24];
int a1t[10];
int a2t[24];
int a3t[15];
int a4t[24];
int max1[10];
int max2[24];
int max3[15];
int max4[24];
int grid[10][15];
int sgrid[10][15];

void init();
int scan();
int check();

void search(int ,int);

void init(){
  int a = 0;
  for(int i=0; i<10; i++) max1[i] = 15;
  for(int i=0; i<24; i++) {
    if( i <=9 ) a++;
    else if( 9 < i && i < 14 ) ;
    else if( i >= 15 )a--;
    max2[i] = a;
    max4[i] = a;
  }
  for(int i=0; i<15; i++) max3[i] = 10;
  
  for(int i=0; i<10; i++){
    for(int j=0; j<15; j++){
      grid[i][j] = EMPTY;
    }
  }
  
  for(int i=0; i<10; i++){
    for(int j=0; j<15; j++){
      grid[i][j] = EMPTY;
    }
  }

}

main(){
  int n;
  scanf("%d", &n);
  int result = 0;

  for(int i=0; i<n; i++){
    init();
    for(int j=0; j<10; j++) scanf("%d", &a1[j]);
    for(int j=0; j<24; j++) scanf("%d", &a2[j]);
    for(int j=0; j<15; j++) scanf("%d", &a3[j]);
    for(int j=0; j<24; j++) scanf("%d", &a4[j]);
    
    memcpy(a1t, a1, sizeof(a1t));
    memcpy(a2t, a2, sizeof(a2t));
    memcpy(a3t, a3, sizeof(a3t));
    memcpy(a4t, a4, sizeof(a4t));

    result = scan();

    if( i != 0 )  printf("\n");
    
    if(result && check()){
      for(int i=0; i<10; i++){
	for(int j=0; j<15; j++){
	  if( grid[i][j] ) printf("#");
	  else printf(".");
	}
	printf("\n");
      }
    }else{
      for(int i=0; i<10; i++){
	for(int j=0; j<15; j++){
	  printf(".");
	}
	printf("\n");
      }
    }
  }
}

int scan(){
  int isChange = 0;
  int doCount = 0;

  while(1){
    isChange = 0;
    int t1, t2;
    for(int i=0; i<10; i++){
      for(int j=0; j<15; j++){
	
	if(grid[i][j] == EMPTY){
	  t1 = i+j;
	  t2 = j-i+9;
	  if( a1[i] == 0 || a2[t1] == 0 || a3[j] == 0 || a4[t2] == 0){
	    grid[i][j] = SPACE;
	    max1[i]--;
	    max2[t1]--;
	    max3[j]--;
	    max4[t2]--;
	    isChange = 1; doCount++;
	  }
	}

	if( grid[i][j] == EMPTY){
	  t1 = i+j;
	  t2 = j-i+9;
	  if( a1[i] == max1[i] || a2[t1] == max2[t1] || a3[j] == max3[j] || a4[t2] == max4[t2]){
	    grid[i][j] = OBJ;
	    a1[i]--;
	    a2[t1]--;
	    a3[j]--;
	    a4[t2]--;
	    max1[i]--;
	    max2[t1]--;
	    max3[j]--;
	    max4[t2]--;
	    isChange = 1; doCount++;
	  }
	}
      }
    }
    
    if( doCount >= 150 ) return 1;
    if( isChange == 0 && doCount < 150) return 0;
  }
  
}

int check(){

  for(int i=0; i<10; i++){
    int count = 0;
    for(int j=0; j<15; j++){
      if(grid[i][j] == OBJ) count++;
    }
    if(a1t[i] != count) {
      return 0;
    }
  }

  for(int j=0; j<15; j++){
    int count = 0;
    for(int i=0; i<10; i++){
      if(grid[i][j] == OBJ) count++;
    }
    if(a3t[j] != count) {
      return 0;
    }
  }

  for(int i=0; i<=9; i++){
    int count = 0;
    int j = 0;
    for(int ii = i; ii>=0 ; ii--){
      if(grid[ii][j] == OBJ ) count++;
      j++;
    }
    if(a2t[i] != count){
      return 0;
    }
  }
  for(int j=0; j<=14; j++){
    int count = 0;
    int i=9;
    for(int jj=j; jj<=14 && i>=0; jj++){
      if(grid[i][jj] == OBJ ) count++;
      i--;
    }
    if(a2t[j+9] != count){
      return 0;
    }
  }

  for(int j=0; j<=14; j++){
    int count = 0;
    int i = 9;
    for(int jj=j; jj>=0 && i>=0; jj--){
      if( grid[i][jj] == OBJ ) count++;
      i--;
    }
    if(a4t[j] != count){
      return 0;
    }
  }
  for(int i=9; i>=0; i--){
    int count = 0;
    int j = 14;
    for(int ii=i; ii>=0 && j>=0; ii--){
      if(grid[ii][j] == OBJ) count++;
      j--;
    }
    if(a4t[23-i] != count){ // a4t[14+(9-i)]
      return 0;
    }
  }

  return 1;
}
void search(int i, int j){

  int x, y;
  x = i; y = j+1;
  sgrid[i][j] = SPACE;
  if( x >=0 && y>=0 && x<10 && y<15) {
    if(sgrid[x][y] == OBJ){
      sgrid[x][y] = SPACE;
      search(x, y);
    }
  }
  x = i+1; y = j;
  if( x >=0 && y>=0 && x<10 && y<15) {
    if(sgrid[x][y] == OBJ){
      sgrid[x][y] = SPACE;
      search(x, y);
    }
  }
  x = i; y = j-1;
  if( x >=0 && y>=0 && x<10 && y<15) {
    if(sgrid[x][y] == OBJ){
      sgrid[x][y] = SPACE;
      search(x, y);
    }
  }
  x = i-1; y = j;
  if( x >=0 && y>=0 && x<10 && y<15) {
    if(sgrid[x][y] == OBJ){
      sgrid[x][y] = SPACE;
      search(x, y);
    }
  }

}

// @end_of_source_code
