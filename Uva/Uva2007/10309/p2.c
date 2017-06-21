// @JUDGE_ID:  17051CA  10309  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<stl.h>

#define ROW 10
#define COL 10

typedef vector<vector<int> > Grid;

Grid  grid;
vector<int> goal;

void work();
void press(Grid &g, int); /* pos */
void parse(Grid g, int, int); /* pos, cost */
int testcount;
void work(){
  string line;
  /*init*/
  for(int i=0; i<grid.size(); i++){
    grid[i].clear();
  }
  grid.clear();
  grid.resize(ROW);
  for(int i=0; i<ROW; i++){
    grid[i].resize(COL);
  }

  for(int i=0; i<ROW; i++){
    cin >> line;
    for(int j=0; j<COL; j++){
      grid[i][j] = line[j]=='O';
    }
  }
  testcount = 0;
  goal.clear();
  parse(grid, 0, 0);
  cout << testcount << endl;
  if( goal.size() == 0 ) cout << "-1" << endl;
  else{
    sort(goal.begin(), goal.end());
    cout << goal[0] << endl;
  }
}


void parse(Grid gr, int pos, int cost){
  Grid tmpG;

  /* first Row */
  if( pos < COL ){
    /* press */
    tmpG = gr;
    press(tmpG, pos);
    parse(tmpG, pos+1, cost+1);
    /* no press */
    tmpG = gr; 
    parse(tmpG, pos+1, cost);
    return;
  }
  
  /* cut */
  for(int i=pos/COL-2; i>=0; i--){
    for(int j=0; j<COL; j++){
      if(gr[i][j]) {
	//cout << "cut" << endl; 
	return;
      }
    }
  }
  /*
  for(int i=0; i<gr.size(); i++){
    for(int j=0; j<gr[i].size(); j++){
      cout << gr[i][j];
    }
    cout << endl;
  }*/

  /* finished */
  if(pos == ROW*COL){
    /* check */
    bool valid = true;
    for(int i=0; i<ROW; i++){
      for(int j=0; j<COL; j++){
	if(gr[i][j]){ valid = false; goto next;}
      }
    }
  next:;
    if(valid) goal.push_back(cost);
    return;
  }
  /*
  int i = pos/COL;
  int j = pos%COL;
  if( gr[i-1][j] ){
    tmpG = gr; 
    press(tmpG, pos);
    parse(tmpG, pos+1, cost+1);
  }else{
    tmpG = gr; 
    parse(tmpG, pos+1, cost);
  }
  */
  int i, j;
  for(int p=pos; p<100; p++){
    i=p/COL; j=p%COL;
    if( gr[i-1][j] ){
      press(gr, p);
      cost++;
    }else{
  
    }
  }

  bool valid = true;
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COL; j++){
      if(gr[i][j]){ valid = false; goto next2;}
    }
  }
 next2:;
  if(valid) goal.push_back(cost);
  return;
  
}

void press(Grid &gr, int pos){
  int i = pos/COL;
  int j = pos%COL;
  int ii, jj, ni, nj;
  for(int d=0; d<5; d++){
    ii = jj = 0;
    if(d==0){;}
    if(d==1){ii++;}
    if(d==2){ii--;}
    if(d==3){jj++;}
    if(d==4){jj--;}
    ni = i+ii; nj = j+jj;
    if( ni >=0 && nj >=0 && ni < ROW && nj < COL){
      gr[ni][nj] = (gr[ni][nj]^1);
    }
  }
}

main(){
  string case_str;
  while(1){
    cin >> case_str;
    if(case_str == "end") break;
    cout << case_str << " ";
    work();
  }
}
// @end_of_source_code

