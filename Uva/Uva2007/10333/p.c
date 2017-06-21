// @JUDGE_ID:  17051CA  10333  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>

#define MAX_H 512
#define MAX_V 512

void init();
void initG();
int read();
void work();
void render();
void divH(int, int);
void divH2(int, int);

int H;
vector<int> v1;
vector<int> v2;
char grid[MAX_H][MAX_V];
int index;

void init(){
  v1.clear();
  v2.clear();
}

void initG(){
  for(int i=0; i<MAX_H; i++){
    for(int j=0; j<MAX_V; j++){
      grid[i][j] = ' ';
    }
  }
}

int read(){
  if( scanf("%d", &H) == EOF ) return 0;
  else return 1;
}

void work(){

  init();
  divH(0, H);
  divH2(0, H);

  initG();
  render();

  int count = 0;
  for(int i=index; i>=0; i--){
    count = 0;
    for(int j=0; j<MAX_V; j++){
      if( count == 0 ){
	if( grid[i][j] == '#'){
	  printf("#");
	  count++;
	}else printf(" ");
      }else if( count == 1 ){
	if( grid[i][j] == '#'){
	  printf("#\n");
	  j = MAX_V;
	}else if( grid[i][j] == '*'){
	  printf("*");
	}else printf(".");
      }
    }
  }
}

void render(){
  int i, j;
  i = 0; j = 0;
  for(int a = v1.size()-1; a >= 0; a--){
    for(int b = 0; b < v1[a]; b++){
      grid[i][j] = '#';
      i++;
    }
    i--;
    j++;
    grid[i][j] = '*';
    j++;
    grid[i][j] = '*';

    if( a != 0)i++;
    else j++;
  }
  index = i;
  for(int a = 0; a < v2.size(); a++){
    grid[i][j] = '*';
    j++;
    grid[i][j] = '*';
    j++;
    for(int b = 0; b < v2[a]; b++){
      grid[i][j] = '#';
      i--;
    }
  }
}

void divH(int i, int k){
  int a, b;
  a = i+1;
  b = k-a;
  if( a >= b){
    v1.push_back(k);
  }else{
    v1.push_back(a);
    divH(a, b);
  }
}

void divH2(int i, int k){
  int a, b;
  a = i+1;
  b = k-a;
  if( v1.size()-1 == v2.size()+1 ){
    v2.push_back(k);
    return;
  }
  if( a >= b){
    v2.push_back(k);
  }else{
    v2.push_back(a);
    divH2(a, b);
  }
}

main(){
  for(int i=1; read(); i++){
    printf("Tower #%d\n", i );
    work();
    printf("\n");
  }
}
// @end_of_source_code
