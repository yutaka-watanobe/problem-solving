// @JUDGE_ID:  17051CA  403  C++
// @begin_of_source_code
/* Simulation */

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

/*
 * Split a string object by a delimiter( default = ' ')
 * requirement: #include <string>, #include <stl.h>
 */
void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

void trim(string &s){
  int l, r;

  l = s.find_first_not_of(" \n\r");
  r = s.find_last_not_of(" \n\r");

  if(l==string::npos) s = "";
  else  s = s.substr(l, r-l+1);
}


string alpha = ".***..****...****.****..*****.*****..****.*...*.*****.*...*.*...*.*...*.*...*.*.....*.....*.....*...*...*...*****.****..*.....*...*.***...***...*..**.*****...*...*...*.*...*.*.....*...*.*.....*.....*...*.*...*...*...*...*.****...****.****..*****.*......***..*...*.*****...***.*...*.*.....*...*.*...*..***..****...***..****.....*..*..*..*.....**.**.**..*.*...*.*...*.*...*.*...*....*..***...*.....*.*.*.*.*.*.*...*.****..*...*.****..*..*..*..*..*.....*...*.*..**.*...*.*.....*..**.*..*...**...*...*.*****.*...*.*...*..***..*......****.*...*..****.*****.*...*.*...*.*...*.*...*.*...*.*****.......*.....*.*.*.*...*.*...*.*...*..*.*...*.*.....*.........***....*...*...*..*.*..*.*.*...*.....*.....*.............*...*...*...*..*.*..**.**..*.*....*....*..........****...***...***....*...*...*.*...*...*...*****.......";

char grid[60][60];
vector<string> com;
string line, command, font, text;
int row, col;

void write();
void work();

void init(){
  for(int i=0; i<60; i++){
    for(int j=0; j<60; j++){
      grid[i][j] = '.';
    }
  }
}

int read(){
  while(1){
    com.clear();
    getline(cin, line);
    if(cin.eof()) return 0;
    trim(line);
    if(line.size()==0) continue;

    if(line==".EOP"){
      write();
      init();
    }
    
    string str = "";
    int i=0;
    while(line[i]!='|'){
      str += line[i++];
    }
    
    split(com, str);
    
    if(com[0]==".P"){
      command = com[0];
      font = com[1];
      row = atoi(com[2].c_str());
      col = atoi(com[3].c_str());
    }else if(com[0]==".C"){
      command = com[0];
      font = com[1];
      row = atoi(com[2].c_str());
    }else if(com[0]==".L"){
      command = com[0];
      font = com[1];
      row = atoi(com[2].c_str());
    }else if(com[0]==".R"){
      command = com[0];
      font = com[1];
      row = atoi(com[2].c_str());
    }
    text = "";
    for(int s=i; s<line.size()-1; s++){
      if(line[s]==' ') line[s]='.';
      text += line[s];
    }
    text.erase(text.begin()+0);
    work();
  }
}

void work(){
  int size;
  int s_col;
  row--;
  col--;
  if(font=="C1"){
    size = text.size();
  }else if(font=="C5"){
    size = text.size()*6;
  }
  
  if(command==".C"){
    s_col = 30 - size/2;
  }else if(command==".P"){
    s_col = col;
  }else if(command==".L"){
    s_col = 0;
  }else if(command==".R"){
    s_col = 60 - size;
  }

  if(font=="C1"){
    int j = s_col;
    for(int s=0; s<size; s++){
      if(0 <= j && j < 60 ){
	if(text[s]!='.') grid[row][j] = text[s];
      }
      j++;
    }
    return;
  }

  int s_j = s_col;
  int index, ii, jj;

  for(int s=0; s<text.size(); s++){
    if(text[s]=='.') index = 26;
    else index = text[s] - 65;

    ii = (index/9) * 5;
    jj = (index%9) * 6;

    for(int i=row; i<row+5; i++){
      for(int j=s_j; j<s_j+6; j++){
	if(0<=i && i<60 && 0<=j && j<60){
	  char c = alpha[ii*54 + jj];
	  if(c!='.') grid[i][j] = c;
	}
	jj++;
      }
      ii++;
      jj = (index%9) * 6;
    }
    s_j += 6;
  }
}

void write(){
 for(int i=0; i<60; i++){
   for(int j=0; j<60; j++){
     cout << grid[i][j];
   }
   cout << endl;
 }
 cout << endl;
 cout << "------------------------------------------------------------" <<endl;
 cout << endl;
}

main(){
  for(int i=0; i<60; i++){
    for(int j=0; j<60; j++){
      grid[i][j] = '.';
    }
  }
  while(read()){

  }
}
//@end_of_source_code
