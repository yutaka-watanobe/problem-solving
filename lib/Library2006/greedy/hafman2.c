#include<stdio.h>
#include<string>
#include<iostream>
#include<queue>
#include<stl.h>

#define MAX 512

string line;

int letterCnt[MAX];

main(){
  cin >> line;

  fill(letterCnt, letterCnt + MAX, 0);

  for(int i=0; i<line.size(); i++){
    char ch = line[i];
    letterCnt[ch]++;
  }

  priority_queue<pair<int, char>, vector<pair<int, char> >, less<pair<int, char> > > q;

  for(int i=0; i<MAX; i++){
    if(letterCnt[i]>0){
      q.push(pair<int, char>(letterCnt[i], i));
    }
  }

  pair<int, char> p;
  while(!q.empty()){
    p = q.top();
    cout << p.first << " " << p.second << endl;
    q.pop();
  }
  
  
  int new = MAX + 1;

  while(!q.emtpy()){


  }



}
