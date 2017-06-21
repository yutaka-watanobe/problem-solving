// @JUDGE_ID:  17051CA  151  C++
// @begin_of_source_code
#include<stdio.h>
#include<stdio.h>
#include<vector>
#include<iostream.h>

int read();
void init();
void work();
int parse(int);

int N;
vector<int> v;


void init(){
  v.clear();
  for(int i=0; i<N; i++){
    v.push_back(i+1);
  }
}

void work(){
  int m;

  if( N == 13 ){
    cout << 1 << endl;
    return ;
  }

  for(m=1; ;m++){
    init();
    if(parse(m)) break;
  }

  cout << m+1 << endl;
  
  
}

int parse(int m){
  int i=0;
  while( v.size() > 1 ){
    if( v[i] == 13 ) return 0;
    v.erase(v.begin()+i);
    i += m;
    if( i >= v.size() ) i = i % v.size();
  }
  return 1;
}

int read(){
  scanf("%d", &N);
  if(N == 0 ) return 0;
  else return 1;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
