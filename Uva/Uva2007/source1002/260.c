// @JUDGE_ID:  17051CA  260  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>

#define MAX 210

int read();
void init();
void work();
void parse(int, int);

int n;
unsigned char grid[MAX][MAX];
unsigned int check[MAX][MAX];
int black_win;

int read(){
  cin >> n;
  if( n == 0 ) return 0;
  
  string line;
  for(int i=0; i<n; i++){
    cin >> line;
    for(int j=0; j<n; j++){
      grid[i][j] = line[j];
    }
  }
  return 1;
}

void init(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      check[i][j] = 0;
    }
  }
}

void work(){

  black_win = 0;
  init();

  for(int j=0; j<n; j++){
    if(grid[0][j] == 'b'){
      parse(0, j);
    }
  }
  
  if( black_win ) cout << "B" << endl;
  else cout << "W" << endl;

}

void parse(int i, int j){
  
  if( i == n-1 ){
    black_win = 1;
    return;
  }
  
  check[i][j] = 1;
  int x, y;
  x = i-1; y = j-1;
  if( x>=0 && y>=0 && x<n && y<n && grid[x][y] == 'b' && check[x][y] == 0){
    parse(x, y);
  }
  x = i-1; y = j;
  if( x>=0 && y>=0 && x<n && y<n && grid[x][y] == 'b' && check[x][y] == 0 ){
    parse(x, y);
  }
  x = i; y = j-1;
  if( x>=0 && y>=0 && x<n && y<n && grid[x][y] == 'b' && check[x][y] == 0 ){
    parse(x, y);
  }
  x = i; y = j+1;
  if( x>=0 && y>=0 && x<n && y<n && grid[x][y] == 'b' && check[x][y] == 0 ){
    parse(x, y);
  }
  x = i+1; y = j;
  if( x>=0 && y>=0 && x<n && y<n && grid[x][y] == 'b' && check[x][y] == 0 ){
    parse(x, y);
  }
  x = i+1; y = j+1;
  if( x>=0 && y>=0 && x<n && y<n && grid[x][y] == 'b' && check[x][y] == 0 ){
    parse(x, y);
  }
}

main(){
  for(int i=1; read(); i++){
    cout << i << " ";
    work();
  }
}
// @end_of_source_code
