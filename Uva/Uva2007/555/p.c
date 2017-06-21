// @JUDGE_ID:  17051CA  555  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<map>

int getI(char);

string line;
char c;

int read(){
  getline(cin, line);
  if(line=="#") return 0;

  c = line[0];

  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);

  line = str1 + str2;

  return 1;
}

void work(){
  vector<vector<int> > dec;
  map<int, string> mp;

  int start;
  if( c == 'S') start = 1;
  else if( c=='W' ) start = 2;
  else if( c=='N' ) start = 3;
  else if( c=='E' ) start = 0;

  dec.resize(4);

  int k;
  string s;
  for(int i=0; i<line.size()-1; i+=2){
    k = getI( line[i] ) + getI( line[i+1] );
    s = line.substr(i, 2);
    mp[ k ] = s;
    dec[start].push_back(k);
    if( start == 3 ){
      start = 0;
    }else start++;
  }

  sort(dec[0].begin(), dec[0].end());
  sort(dec[1].begin(), dec[1].end());
  sort(dec[2].begin(), dec[2].end());
  sort(dec[3].begin(), dec[3].end());

  for(int i=0; i<4; i++){
    if( i==0 ) cout << "S:";
    if( i==1 ) cout << "W:";
    if( i==2 ) cout << "N:";
    if( i==3 ) cout << "E:";
    for(int j=0; j<dec[i].size(); j++) cout << " " << mp[ dec[i][j] ];
    cout << endl;
  }
}

int getI(char c){
  if( isdigit(c) ){
    return c - '0';
  }

  switch(c){
  case 'T':
    return 10;
  case 'J':
    return 11;
  case 'Q':
    return 12;
  case 'K':
    return 13;
  case 'A':
    return 14;
  case 'C':
    return 100;
  case 'D':
    return 200;
  case 'S':
    return 300;
  case 'H':
    return 400;
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
