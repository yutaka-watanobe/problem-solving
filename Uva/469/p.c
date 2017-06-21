// @JUDGE_ID:  17051CA  469  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

string line;
char grid[100][100];
bool used[100][100];
int r, c;
int count;

void rec(int i, int j);
void work(int i, int j);
void read(){
  int i;
  i = 0;
  r = c = 0;
  while(1){
    getline(cin, line);
    if(line.size()==0) break;
    if(isalpha(line[0])){
      for(int j=0; j<line.size(); j++){
	grid[i][j] = line[j];
	c = line.size();
      }
      i++;
    }else{
      r = i;
      string str1, str2;
      bool first = true;
      str1 = str2 = "";
      for(int j=0; j<line.size(); j++){
	if(line[j]==' '){
	  first = false;
	}else{
	  if(first) str1 += line[j];
	  else str2 += line[j];
	}
      }
      work(atoi(str1.c_str())-1, atoi(str2.c_str())-1);
    }
  }
}

void work(int i, int j){

  /* init */
  for(int a=0; a<r; a++){
    for(int b=0; b<c; b++){
      used[a][b] = false;
    }
  }
  count = 0;
  if(grid[i][j]!='W'){
    count = 0;
  }else{
    rec(i, j);
  }
  cout << count << endl;
}

bool check(int i, int j){
  if(i>=0 && j>=0 && i<r && j<c && !used[i][j]) {
    return true;
  }
  return false;
}

void rec(int i, int j){
  used[i][j] = true;
  if(grid[i][j]=='W') count++;
  else return;

  int ii, jj;
  
  ii = i; jj = j+1;
  if(check(ii, jj)) rec(ii, jj);
  ii = i; jj = j-1;
  if(check(ii, jj)) rec(ii, jj);
  ii = i-1; jj = j;
  if(check(ii, jj)) rec(ii, jj);
  ii = i+1; jj = j;
  if(check(ii, jj)) rec(ii, jj);
  ii = i+1; jj = j+1;
  if(check(ii, jj)) rec(ii, jj);
  ii = i+1; jj = j-1;
  if(check(ii, jj)) rec(ii, jj);
  ii = i-1; jj = j+1;
  if(check(ii, jj)) rec(ii, jj);
  ii = i-1; jj = j-1;
  if(check(ii, jj)) rec(ii, jj);
}

main(){
  int testCase;
  char buf[10000];
  cin.getline(buf, 10000);
  testCase = atoi(buf);

  /* first line */
  getline(cin, line);

  for(int i=0; i<testCase; i++){
    read();
    cout << endl;
  }
}
// @end_of_source_code
