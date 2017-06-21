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
void press(Grid &g, int, int); /* pos */
void parse();
void createBit( int a, vector<int> &bit, int l );

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
  goal.clear();
  parse();
  if( goal.size() == 0 ) cout << "-1" << endl;
  else{
    sort(goal.begin(), goal.end());
    cout << goal[0] << endl;
  }
}


void parse(){
  Grid tmpG;
  int cost, i, j;
  vector<int> bit;

  for(int b=0; b<1024; b++){
    createBit(b, bit, 10);
    tmpG = grid; cost = 0;
    for(int k=0; k<10; k++){
      if(bit[k]) {press(tmpG, 0, k ); cost++;}
    }
    /*
    for(int p=10; p<100; p++){
      i=p/COL; j=p%COL;
      if( tmpG[i-1][j] ){
	press(tmpG, p);
	cost++;
      }
    }*/
    for(int i=1; i<10; i++){
      for(int j=0; j<10; j++){
	if( tmpG[i-1][j] ){
	  press(tmpG, i, j);
	  cost++;
	}
      }
    }
    
    bool valid = true;
    for(int i=ROW-1; i>=0; i--){
      for(int j=COL-1; j>=0; j--){
	if(tmpG[i][j]){ valid = false; goto next2;}
      }
    }
  next2:;
    if(valid) goal.push_back(cost);
  }
    
}

void press(Grid &gr, int i, int j){
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
      /*gr[ni][nj] = (gr[ni][nj]^1);*/
      if(gr[ni][nj]) gr[ni][nj] = 0;
      else gr[ni][nj]=1;
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

void createBit( int a, vector<int> &bit, int l ){
  bit.clear();
  int next;
  while( 1 ){
    bit.push_back( a%2 );
    next = a/2;
    a = next;
    if(next==0 ) break;
  }

  while( bit.size() < l ){
    bit.push_back(0);
  }
}

// @end_of_source_code

