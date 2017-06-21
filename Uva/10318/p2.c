// @JUDGE_ID:  17051CA  10318  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<math.h>

#define MAX 5
typedef vector<vector<int> > Grid;

int r, c;
int pattern[3][3];
vector<vector<int> > grid;
vector<vector<int> > goal;

int read();
void work();
void init();
void createP( int, vector<int> &bit, int l );
void press( vector<vector<int> > &gr, int, int);
void parse( vector<vector<int> > gr, int, vector<int> p);


void work(){
  
  vector<int> p; /* bit pattern */
  int n_p = (int)pow(2, c);

  for(int i=0; i<n_p; i++){
    createP( i, p, c);
    init();
    vector<int> pass;
    for(int pp=0; pp<p.size(); pp++){
      if(p[pp]){
	pass.push_back(pp);
	press(grid, 0, pp);
      }
    }
    
    Grid tmp = grid;
    if( r>1 ) parse( tmp, c, pass );
  }
  
}

void parse( Grid gr, int pos, vector<int> p){
  /*  cout << "parse " << pos << endl; */
  for(int x=0; x<gr.size(); x++){
    for(int y=0; y<gr[x].size(); y++){
      cout << gr[x][y];
    }
    cout << endl;
  }

 
  Grid tmpG;
  vector<int > tmpP;
  int i= pos/c;
  int j= pos%c;

  /* no button */
  if( pos == r*c ){
    /* check */
    bool light = true;
    for(int a=0; a<gr.size(); a++){
      for(int b=0; b<gr[a].size(); b++){
	if( gr[a][b]==0 ) {
	  light = false;
	  goto next;
	}
      }
    }
  next:;
    if(light){
      for(int a=0; a<p.size(); a++) cout << "pass " << p[a] << " ";
      cout << endl;
    }
    return ;
  }

  /* press */
  tmpG = gr; tmpP = p;
  press(tmpG, i, j);
  tmpP.push_back(pos); parse(tmpG, pos+1, tmpP);
  /* not press */
  tmpG = gr; tmpP = p;
  parse(tmpG, pos+1, tmpP);

}

void press(vector<vector<int> > &gr, int i, int j){
  /* cout << " press " << i << ", " << j << endl; */
  int ii, jj, ni, nj;
  for(int a=0; a<9; a++){
    ii = jj = 0;
    if( a==0 ) ii++;
    if( a==1 ) jj++;
    if( a==2 ) ii--;
    if( a==3 ) jj--;
    if( a==4 ){ jj++; ii++; }
    if( a==5 ){ jj--; ii++; }
    if( a==6 ){ jj++; ii--; }
    if( a==7 ){ jj--; ii--; }
    if( a==8 ){ ;}
    ni = i+ii; nj = j+jj;
    if( ni >=0 && nj >=0 && ni < r && nj < c ){
      if( grid[ni][nj] == 0 ){
	if( pattern[1+ii][1+jj] ) grid[ni][nj] = 1;
      }else{
	if( pattern[1+ii][1+jj] ) grid[ni][nj] = 0;
      }
    }
  }
}

main(){
  for(int i=1; read(); i++){
    cout << "Case #" << i << endl;
    work();
  }
}

int read(){
  cin >> r >> c;
  if( c==0 && r==0 ) return 0;
  string line;
  for(int i=0; i<3; i++){
    cin >> line;
    for(int j=0; j<3; j++){
      if( line[j]=='*' ) pattern[i][j] = 1;
      else pattern[i][j] = 0;
    }
  }
  return 1;
}

void init(){
  for(int i=0; i< grid.size(); i++){
    grid[i].clear();
  }
  grid.clear();
  grid.resize(r);
  for(int i=0; i< grid.size(); i++){
    grid[i].resize(c);
  }
}

void createP( int a, vector<int> &bit, int l ){
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
