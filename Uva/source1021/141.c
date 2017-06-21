// @JUDGE_ID:  17051CA  141  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<stl.h>

int read();
void init();
void work();

int n;
bool grid[60][60];
set<string> pattern;

int read(){
  cin >> n;
  if( n==0 ) return 0;
  return 1;
}

void init(){
  pattern.clear();

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      grid[i][j] = false;
    }
  }
}

void work(){
  init();
  int i, j;
  char com;
  string p;
  int size;
  int move = 0;
  bool isDraw = true;

  for(int k=0; k<n*2; k++){
    move++;
    cin >> i >> j >> com;
    if(com=='+') grid[i-1][j-1] = true;
    else grid[i-1][j-1] = false;
    
    size = pattern.size();
    if( !isDraw ) continue;
    /* 0 */
    p = "";
    for(int a=0; a<n; a++){
      for(int b=0; b<n; b++){
	if(grid[a][b] ) p = p+"1";
	else p = p+"0";
      }
    }
    pattern.insert(p);
    /* 90 */
    p = "";
    for(int b=0; b<n; b++){
      for(int a=n-1; a>=0; a--){
	if(grid[a][b] ) p = p+"1";
	else p = p+"0";
      }
    }
    pattern.insert(p);
    /* 180 */
    p = "";
    for(int a=n-1; a>=0; a--){
      for(int b=n-1; b>=0; b--){
	if(grid[a][b] ) p = p+"1";
	else p = p+"0";
      }
    }
    pattern.insert(p);
    /* 270 */
    p = "";
    for(int b=n-1; b>=0; b--){
      for(int a=0; a<n; a++){
	if(grid[a][b] ) p = p+"1";
	else p = p+"0";
      }
    }
    pattern.insert(p);
    
    /* no change */
    if( pattern.size() == size ){
      if(move%2==0){
	cout << "Player 1 wins on move " << move << endl;
      }else{
	cout << "Player 2 wins on move " << move << endl;
      }
      isDraw = false;
    }
  }
  
  if(isDraw) cout << "Draw" << endl;
  
  /*
  vector<string> v;
  v.resize(pattern.size());
  copy(pattern.begin(), pattern.end(), v.begin());
  for(int i=0; i<v.size(); i++){
    cout << v[i] << endl;
  }
  */
}

main(){
  while(read()){
    work();
  }
}s
// @end_of_source_code
