// @JUDGE_ID:  17051CA  10267  C++
// @begin_of_source_code
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

/*
 * stringオブジェクトを1文字のデリミタ(デフォルトは空白)で区切る
 * 要件: #include <string>, #include <stl.h>
 */
void split(vector<string> &d, string &s, char c=' '){
  string t = "";

  d.clear();
  for(int i=0; i<s.size(); i++){
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

#define MAX 300

char grid[MAX][MAX];
int n, m;
bool visited[MAX][MAX];

void work();
void setCommand(vector<string> &v, string);
void fill(int, int, char, char);

void work(){
  char buf[1000];
  string str;
  vector<string> command;

  int x, y, x1, x2, y1, y2;
  string color;

  while(1){
    cin.getline(buf, 1000);
    str = buf;
    split(command, str);
    
    string c = command[0];

    if(c=="X") break;

    if(c=="I"){
      if(command.size()!=3) continue;
      m = atoi(command[1].c_str()); n = atoi(command[2].c_str());
      for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
	  grid[i][j] = 'O';
	}
      }
    }else if(c=="C"){
      if(command.size()!=1) continue;
      for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
	  grid[i][j] = 'O';
	}
      }
    }else if(c=="L"){
      if(command.size()!=4) continue;
      x = atoi(command[1].c_str())-1;
      y = atoi(command[2].c_str())-1;
      color = command[3];
      grid[y][x] = color[0];
    }else if(c=="V"){
      if(command.size()!=5) continue;
      x = atoi(command[1].c_str())-1;
      y1 = atoi(command[2].c_str())-1;
      y2 = atoi(command[3].c_str())-1;
      color = command[4];
      for(int y=min(y1, y2); y<=max(y1,y2); y++){
	grid[y][x] = color[0];
      }
    }else if(c=="H"){
      if(command.size()!=5) continue;
      x1 = atoi(command[1].c_str())-1;
      x2 = atoi(command[2].c_str())-1;
      y = atoi(command[3].c_str())-1;
      color = command[4];
      for(int x=min(x1,x2); x<=max(x1,x2); x++){
	grid[y][x] = color[0];
      }
    }else if(c=="K"){
      if(command.size()!=6) continue;
      x1 = atoi(command[1].c_str())-1;
      y1 = atoi(command[2].c_str())-1;
      x2 = atoi(command[3].c_str())-1;
      y2 = atoi(command[4].c_str())-1;
      color = command[5];
      for(int i=min(y1,y2); i<=max(y1,y2); i++){
	for(int j=min(x1,x2); j<=max(x1,x2); j++){
	  grid[i][j] = color[0];
	}
      }
    }else if(c=="F"){
      if(command.size()!=4) continue;
      x = atoi(command[1].c_str())-1;
      y = atoi(command[2].c_str())-1;
      color = command[3];
      for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
	  visited[i][j] = false;
	}
      }
      fill(x, y, color[0], grid[y][x]);
    }else if(c=="S"){
      if(command.size()!=2) continue;
      cout << command[1] << endl;
      for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
	  cout << grid[i][j];
	}
	cout << endl;
      }
    }
  }  

}

void fill(int x, int y, char color, char org){
  grid[y][x] = color;
  visited[y][x] = true;
  int ii, jj, nx, ny;
  for(int d=0; d<4; d++){
    ii = jj = 0;
    if(d==0) ii++;
    if(d==1) ii--;
    if(d==2) jj++;
    if(d==3) jj--;
    nx = ii+x; ny = jj+y;
    if(nx >=0 && ny>=0 && nx<m && ny<n ){
      if( !visited[ny][nx] && grid[ny][nx]==org){
	fill(nx, ny, color, org);
      } 
    }
  }
}
  
void setCommand(vector<string> &v, string line){
  v.clear();
  string com="";
  bool isSpace = false;
  for(int i=0; i<line.size(); i++){
    if( i!=0 && !isSpace && line[i]==' '){
      v.push_back(com);
      com = "";
      isSpace = true;
    }else{
      com = com + line[i];
      isSpace = false;
    }
  }
  v.push_back(com);
}



main(){
  work();
}
// @end_of_source_code
