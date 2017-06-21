// @JUDGE_ID: 17051CA 830 C++
#include<stdio.h>
#include<set>
#include<iostream>
#include<vector>
#include<string>

void work();
void init();
void clear();
void search(int, int, char);
void check();

vector<int> vi, vj;
set<int> si, sj;
char sea[70][70];
int row, col;

int sha, dol, whe, mac, sal, gro, tur, sar;

void init(){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      sea[i][j] = '.';
    }
  }
}

void work(){
  cin >> row >> col;
  string line;
  sha = dol = whe = mac = sal = gro = tur = sar = 0;

  /* read */
  for(int i=0; i<row; i++){
    cin >> line;
    for(int j=0; j<col; j++){
      sea[i][j] = line[j];
    }
  }

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(sea[i][j] != '.'){
	clear();
	search(i, j, sea[i][j]);
	check();
      }
    }
  }
  
  cout << sar << " " << mac << " " << sal << " " << gro << " " << tur << " " <<dol << " " << whe << " " << sha << endl;
  
}

void clear(){
  vi.clear();
  vj.clear();
  si.clear();
  sj.clear();
}

void check(){
  
  if(si.size()==1 && sj.size()==1){
    sar++; return;
  }

  if(si.size()==1){
    if( sj.size()==2 ){
      mac++; return;
    }else if(sj.size()>2){
      sal++; return;
    }
  }
  if(sj.size()==1){
    if( si.size()==2 ){
      mac++; return;
    }else if(si.size()>2){
      sal++; return;
    }
  }

  if( (si.size() == sj.size()) && si.size() >=2){
    tur++; return;
  }

  if(si.size()==2){
    if(sj.size() > 2 ){
      gro++; return;
    }
  }
  if(sj.size()==2){
    if(si.size() > 2){
      gro++; return;
    }
  }

  if(si.size()==4){
    if(sj.size() > 4 ){
      whe++; return;
    }
  }
  if(sj.size()==4){
    if(si.size() > 4){
      whe++; return;
    }
  }

  if(si.size()==3){
    if(sj.size() > 3 ){
      if( vi.size()%si.size()==0 && vj.size()%si.size()==0 ){
	dol++; return;
      }else{
	sha++; return;
      }
    }
  }
  if(sj.size()==3){
    if(si.size() > 3 ){
      if( vi.size()%si.size()==0 && vj.size()%si.size()==0 ){
	dol++; return;
      }else{
	sha++; return;
      }
    }
  }

}

void search(int i, int j, char c){
  
  vi.push_back(i); vj.push_back(j);
  si.insert(i); sj.insert(j);

  sea[i][j] = '.';
  
  int ii, jj, ni, nj;
  for(int d=0; d<4; d++){
    ii = jj = 0;
    if(d==0) ii++;
    if(d==1) ii--;
    if(d==2) jj++;
    if(d==3) jj--;
    ni = ii+i; nj = jj + j;
    if( ni >=0 && nj >=0 && ni < row && nj < col){
      if( sea[ni][nj] == c) search(ni, nj, c);
    }
   }
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    if(i!=0 ) cout << endl;
    work();
  }
}
