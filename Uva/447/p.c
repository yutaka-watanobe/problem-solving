// @JUDGE_ID:  17051CA  447  C++
// @begin_of_source_code
/* シミュレーション */
/* 初期の人口から年々どう人口（？）が変化してくか */
#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 22

char map[MAX][MAX];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

string line;
int year;

void init(){
  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      if(i==0 || i==MAX-1 || j==0 || j==MAX-1) map[i][j]='X'; /* 番兵 */
      else map[i][j] = ' ';
    }
  }
}

void read(){
  init();
  getline(cin, line);
  year = atoi(line.c_str());
  int x, y;
  while(1){
    getline(cin, line);
    if(cin.eof() || line.size()==0) return ;
    sscanf(line.c_str(), "%d %d", &x, &y);
    map[x][y] = 'O';
  }
}

void print(){
  cout << "********************" << endl;
  int index[MAX];
  for(int i=1; i<MAX-1; i++){
    index[i] = 0;
    for(int j=1; j<MAX-1; j++){
      if(map[i][j]=='O') index[i] = j;
    }
  }

  for(int i=1; i<MAX-1; i++){
    for(int j=1; j<=index[i]; j++){
      cout << map[i][j];
    }
    cout << endl;
  }
}

void explode(){
  
  int cnt, ni, nj;
  char tmp[MAX][MAX];
  tmp = map;

  for(int i=1; i<=20; i++){
    for(int j=1; j<=20; j++){
      cnt = 0;
      if(map[i][j]=='O'){
	for(int r=0; r<8; r++){
	  ni = i + dx[r];
	  nj = j + dy[r];
	  if(map[ni][nj]=='O') cnt++;
	}
	if(cnt==2 || cnt==3){
	  tmp[i][j] = 'O';
	}else{
	  tmp[i][j] = ' ';
	}
      }else{
	for(int r=0; r<8; r++){
	  ni = i + dx[r];
	  nj = j + dy[r];
	  if(map[ni][nj]=='O') cnt++;
	}
	if(cnt==3){
	  tmp[i][j] = 'O';
	}else{
	  tmp[i][j] = ' ';
	}
      }
    }
  }

  map = tmp;

}


void work(){
  print();
  for(int i=1; i<year; i++){

    explode();
    print();
  }

  cout << "********************" << endl;
}

main(){
  getline(cin, line);
  int testCase = atoi(line.c_str());
  getline(cin, line);
  for(int i=0; i<testCase; i++){
 
    read();
    work();
    cout << endl;
  }
}
// @end_of_source_code
