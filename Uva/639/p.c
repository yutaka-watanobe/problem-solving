// @JUDGE_ID:  17051CA  639  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n;
char grid[5][5];

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

vector<bool> tused;
int mr;

void rec(int p, vector<bool> used, int r){
  if(p >= n*n){
    if(mr < r) mr = r;
    return;
  }

  int pi, pj;
  pi = p/n;
  pj = p%n;
  /* put */
  tused = used;
  bool able = true;
  for(int i=pi; i<n; i++){
    if(grid[i][pj]=='X') break;
    if(used[i*n+pj]) { able=false; break;}
  }
  for(int i=pi; i>=0; i--){
    if(grid[i][pj]=='X') break;
    if(used[i*n+pj]) { able=false; break;}
  }
  for(int j=pj; j<n; j++){
    if(grid[pi][j]=='X') break;
    if(used[pi*n+j]) { able=false; break;}
  }
  for(int j=pj; j>=0; j--){
    if(grid[pi][j]=='X') break;
    if(used[pi*n+j]) { able=false; break;}
  }
  if(grid[pi][pj]=='X') able = false;
  if(able){
    tused[pi*n+pj] = true;
    rec(p+1, tused, r+1);
  }
  
  /* not put */
  rec(p+1, used, r);

}

void work(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> grid[i][j];
    }
  }

  vector<bool> used;
  used.resize(n*n, false);
  mr = 0;
  rec(0, used, 0);
  cout << mr << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
