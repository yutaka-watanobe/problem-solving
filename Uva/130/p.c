// @JUDGE_ID:  17051CA  130  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<int> v;
int pos;

int n, k;
int read(){
  cin >> n >> k;
  if(n==0 && k==0) return 0;
  return 1;
}

void move(int n){
  pos = pos + n -1;
  pos = pos%v.size();
}

int parse(){

  int killed = -1;
  pos = 0;
  int r = n;
  while(r>1){
    
    move(k);
    killed = pos;
    r--;
    
    pos = (killed+k-1)%r;
    if(killed<=pos) pos++;

    v[killed] = v[pos]; /* swap */
    
    v.erase(v.begin()+pos);

    if(pos<killed) killed--;
    pos = (killed+1)%v.size();
  }

  if(v[0]==1) return 1;
  else return n-v[0]+2; /* 1+n-v[0]+1;*/
}

void work(){
  v.clear();
  v.resize(n);
  for(int i=0; i<n; i++) v[i] = i+1;
  cout << parse() << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
