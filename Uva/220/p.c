// @JUDGE_ID:  17051CA  220  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

char board[8][8];
int used[8][8];
char current;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int read(){
  char c;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      cin >> c;
      board[i][j] = c;
    }
  }
}

void changePlayer(){
  if(current == 'W') current = 'B';
  else current = 'W';
}

void flip(int x, int y){ 
  if(board[x][y]=='B') board[x][y]='W';
  else board[x][y] = 'B';
}

bool check(int x, int y, char c, bool isDo){
  int other_cnt = 0;
  vector<int> f;
  vector<int> v;
  char l;

  int nx, ny;
  for(int r=0; r<8; r++){
    nx = x + dx[r];
    ny = y + dy[r];
    other_cnt = 0;
    f.clear();
    l = ' ';
    while(nx>=0 && ny>=0 && nx<8 && ny<8){
      if(board[nx][ny]=='-' || board[nx][ny]==c) { l = board[nx][ny]; break;}
      else {other_cnt++; f.push_back(nx*8+ny);}
      nx = nx + dx[r];
      ny = ny + dy[r];
    }
    if(other_cnt>0 && l==c){
      if(!isDo){
	return true;
      }
      else{
	for(int i=0; i<f.size(); i++) v.push_back(f[i]);
      }
    }

  }

  if(isDo){
    for(int i=0; i<v.size(); i++){
      flip(v[i]/8, v[i]%8);
    }
  }

  return false;
}

int listUp(){
  vector<pair<int, int> > v;
  pair<int, int> p;

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      used[i][j] = false;
    }
  }

  int nx, ny;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      
      if(board[i][j]!='-'){
	for(int r=0; r<8; r++){
	  nx = i + dx[r];
	  ny = j + dy[r];
	  if(nx >=0 && ny >=0 && nx < 8 && ny < 8 && !used[nx][ny] && board[nx][ny]=='-'){
	    if(check(nx, ny, current, false)){
	      p.first = nx+1; p.second = ny+1;
	      v.push_back(p);
	    }
	    used[nx][ny] = true;
	  }
	}
      }
    }
  }

  if(v.size()==0) cout << "No legal move." << endl;
  else{
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
      if(i!=0) cout << " ";
      p = v[i];
      cout << "(" << p.first << "," << p.second << ")";
    }
    cout << endl;
  }
}

void displayCount(){
  int w, b;
  w = b = 0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(board[i][j]=='B') b++;
      if(board[i][j]=='W') w++;
    }
  }

  cout << "Black -";
  printf("%3d", b);
  cout << " White -";
  printf("%3d", w);
  cout << endl;
}

void move(int i, int j){
  check(i, j, current, true);
  board[i][j] = current;
  displayCount();
}

void work(){
  cin >> current;
  string line;
  cin >> line;
  while(line!="Q"){
    if(line=="L"){
      listUp();
    }else{
      int x = line[1]-48-1;
      int y = line[2]-48-1;

      if(!check(x, y, current, false)){
	changePlayer();
	move(x, y);
	changePlayer();
      }else{
	move(x, y);
	changePlayer();
      }
    }
    cin >> line;
  }

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
