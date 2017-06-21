// @JUDGE_ID:  17051CA  395  C++
// @begin_of_source_code
/* シミュレーション(ゲーム）*/
/* プレイヤーがコマを置けるすべてのパタンを表示する */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

char B[8][8];
int S[8][8][8];

string alpha;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int read(){
  string line;
  for(int i=0; i<8; i++){
    cin >> line;
    if(cin.eof()) return 0;
    for(int j=0; j<8; j++){
      B[i][j] = line[j];
    }
  }
  cin >> line;
  
  if(line=="X"){
    /* reverse */
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
	if(B[i][j]=='O') B[i][j]='X';
	else if(B[i][j]=='X') B[i][j]='O';
      }
    }
  }
  
  return 1;
}

void setStep(){
  int ST[8][8][8];
  int ni, nj;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      for(int t=0; t<8; t++) S[i][j][t] = 0;
      if(B[i][j]!='.'){
	for(int d=0; d<8; d++){
	  S[i][j][d] = 0;
	  for(int c=0; true; c++){
	    ni = i + c*dx[d];
	    nj = j + c*dy[d];
	    if(!(0<=ni && 0<=nj && ni<8 && nj<8) ) goto next;
	    if(B[ni][nj]!='.') S[i][j][d]++;
	  }
	next:;
	}
      }

      ST= S;
      for(int d=0; d<8; d++){
	int t = d+4; t = t%8;
	S[i][j][d] = S[i][j][d] + ST[i][j][t] - 1;
      }
    }
  }

}

bool hasX(int i, int j, int ni, int nj, int d){
  while(1){
    if(i==ni && j==nj) break;
    if(B[i][j]=='X') return true;
    i += dx[d];
    j += dy[d];
  }
  return false;
}

void work(){
  setStep();
  vector<string> move;
  string str = "";
  int ni, nj;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(B[i][j]=='O'){
	
	for(int d=0; d<8; d++){
	  ni = i + dx[d]*S[i][j][d];
	  nj = j + dy[d]*S[i][j][d];
	  if(0<=ni && 0<=nj && ni<8 && nj<8){

	    if(B[ni][nj]!='O' && !hasX(i, j, ni, nj, d)){
	      
	      str = "";
	      str += alpha[i]; 
	      str += (j+1)+'0';
	      str += '-';
	      str += alpha[ni];
	      str += (nj+1)+'0';
	      move.push_back(str);
	    }
	  }
	}
	
      }
    }
  }
  
  if(move.size()==0){
    cout << "No moves are possible" << endl;
  }else{
    sort(move.begin(), move.end());
    for(int i=0; i<move.size(); i++){
      cout << move[i] << endl;
    }
  }


}

main(){
  alpha = "ABCDEFGH";
  for(int i=0; read(); i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
