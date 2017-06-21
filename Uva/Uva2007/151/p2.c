// @JUDGE_ID:  17051CA  151  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<iostream.h>

int read();
void init();
void work();

int N;

int check[101];
vector<int> v;

void init(){
  v.clear();
  check[0] = 1;
  for(int i=1; i<=N; i++){
    check[i] = 0;
  }
}

int read(){
  scanf("%d", &N);
  if(N == 0 ) return 0;
  else return 1;
}

int parse(int m){
  init();
  int p = 1;

  for(int j=0; j<N-1; j++){
    v.push_back(p); check[p] = 1;
    int count = 0;
    while( count < m ){
      p++;
      if( p > N ) p = 2;
      if(check[p] == 0 ){
	count++;
      }
    }
  }
  
  int a;
  while( check[a] == 1 ){
    a++;
  }
  return a;
}

void work(){
  int last;
  int m =0;
  while(1){
    m++;
    last = parse(m);
    if(last == 13){
      cout << m << endl;
      break;
    }
  }
  cout << "error" << endl;
}
main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
