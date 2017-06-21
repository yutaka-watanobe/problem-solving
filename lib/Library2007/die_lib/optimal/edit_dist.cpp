#include <iostream>
#include <string>
#include <climits>
#include <cstdio>

using namespace std;

const int STR_SIZE = 100;
enum Path{
  NONE, DELETE, INSERT, MATCH, CONVERT
};

int table[STR_SIZE+1][STR_SIZE+1];
Path path[STR_SIZE+1][STR_SIZE+1];
// string str1, str2;

void init(int r, int c){
  for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j)
      table[i][j] = INT_MAX;
  for(int i = 0; i <= r; ++i){
    table[i][0] = i;
    path[i][0] = DELETE;
  }
  for(int j = 0; j <= c; ++j){
    table[0][j] = j;
    path[0][j] = INSERT;
  }
  path[0][0] = NONE;
}

void set(int row, int col, int value, Path dir){
  if(table[row][col] > value){
    table[row][col] = value;
    path[row][col] = dir;
  }
}

void editDistance(const string &str1, const string &str2){
  int len1 = str1.size();
  int len2 = str2.size();
  init(len1, len2);
  
  int curr;
  for(int i = 1; i <= len1; ++i){
    for(int j = 1; j <= len2; ++j){
      curr = table[i][j];
      if(str1[i-1] == str2[j-1])
        set(i, j, table[i-1][j-1], MATCH);
      else
        set(i, j, table[i-1][j-1] + 1, CONVERT);
      set(i, j, table[i][j-1] + 1, INSERT);
      set(i, j, table[i-1][j] + 1, DELETE);
    }
  }
}

int del, ins;
void outputPath(int r, int c, const string &str1, const string &str2){
  if(path[r][c] == MATCH){
    outputPath(r-1, c-1, str1, str2);
  }
  else if(path[r][c] == CONVERT){
    outputPath(r-1, c-1, str1, str2);
    if(str1[r-1] != str2[c-1])
      printf("Convert %c at %02d\n", str2[c-1], r + ins - del);
  }
  else if(path[r][c] == INSERT){
    outputPath(r, c-1, str1, str2);
    printf("Insert %c at %02d\n", str2[c-1], (r + 1) + ins - del);
    ++ins;
  }
  else if(path[r][c] == DELETE){
    outputPath(r-1, c, str1, str2);
    printf("Delete %c at %02d\n", str1[r-1], r + ins - del);
    ++del;
  }
}

int main(void){
  string str1, str2;
  while(cin >> str1 >> str2){
    if(str1[0] == '#')
      break;

    editDistance(str1, str2);

    del = ins = 0;
    outputPath(str1.size(), str2.size(), str1, str2);
  }

  return 0;
}
