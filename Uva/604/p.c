// @JUDGE_ID:  17051CA  604  C++
// @begin_of_source_code
/* DFS */
/* √Ÿ§π§Æ§Î */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stl.h>

#define MODE_A 0
#define MODE_B 1

char A[4][4], B[4][4];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

string line;
set<string> wordA, wordB;
int mode;

int read(){
  for(int i=0; i<4; i++){
    getline(cin, line);
    sscanf(line.c_str(), "%c %c %c %c    %c %c %c %c", &A[i][0], &A[i][1], &A[i][2], &A[i][3], 
	   &B[i][0], &B[i][1], &B[i][2], &B[i][3]);
    if(line=="#") return 0;
  }
  getline(cin, line);
  return 1;
}

bool isVowel(char c){
  return (c=='A' || c=='I' || c=='U' || c=='E' || c=='O' || c=='Y');
}

void dfsA(vector<bool> used, int i, int j, string path, int cnt){

  used[i*4+j] = true;
  char c;
  c = A[i][j];

  path += c;
  if(isVowel(c)) cnt++;

  if(cnt > 2 || path.size()-cnt>=3) return;
  if(path.size()==4){
    if(cnt==2){
   //   cout << path << endl;
      wordA.insert(path);
    }
    return ;
  }

  int ni, nj;
  for(int d=0; d<8; d++){
    ni = i + dx[d];
    nj = j + dy[d];
    if(0<=ni && 0<=nj && ni<4 && nj<4 && !used[ni*4+nj]){
      dfsA(used, ni, nj, path, cnt);
    }
  }
}

void dfsB(vector<bool> used, int i, int j, string path, int cnt){
  used[i*4+j] = true;
  char c;
  c = B[i][j];

  path += c;
  if(isVowel(c)) cnt++;

  if(cnt > 2 || path.size()-cnt>=3) return;
  if(path.size()==4){
    if(cnt==2){
      wordB.insert(path);
    }
    return ;
  }

  int ni, nj;
  for(int d=0; d<8; d++){
    ni = i + dx[d];
    nj = j + dy[d];
    if(0<=ni && 0<=nj && ni<4 && nj<4 && !used[ni*4+nj]){
      dfsB(used, ni, nj, path, cnt);
    }
  }
}

void work(){
  wordA.clear(); wordB.clear();

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      vector<bool> used(16, false);
      dfsA(used, i, j, "", 0);
    }
  }

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      vector<bool> used(16, false);
      dfsB(used, i, j, "", 0);
    }
  }

  vector<string> a, b, c;
  a.resize(wordA.size());
  b.resize(wordB.size());
  copy(wordA.begin(), wordA.end(), a.begin());
  copy(wordB.begin(), wordB.end(), b.begin());
 
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<b.size(); j++){
      if(a[i]==b[j]){
	c.push_back(a[i]);
	goto next;
      }
    }
  next:;
  } 
  
  if(c.size()==0) cout << "There are no common words for this pair of boggle boards." << endl;
  else{
    for(int i=0; i<c.size(); i++){
      cout << c[i] << endl;
    }
  }
}

main(){
  for(int i=0; read(); i++){
    if(i) cout << endl;
    work();
  }
}
// @end_of_source_code
