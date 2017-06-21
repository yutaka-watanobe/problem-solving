// @JUDGE_ID:  17051CA  10154  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

vector<pair<int, int> > T;

int read(){
  int a, b;
  while(1){
    cin >> a >> b;
    if(cin.eof()) break;
    T.push_back(pair<int, int>(b-a, a));
  }
  sort(T.begin(), T.end());

}

void work(){
  if(T.size()==1){ cout << 1 << endl; return; }
  int max_len = 0;
  vector<int> W, L;

  W.resize(T.size(), 0);
  L.resize(T.size(), 1);

  for ( int i = 0; i < T.size(); i++ ){
    W[i] = T[i].second;
  }
  
  for(int i=0; i<T.size(); i++){
    int MI = -1;
    int M = 0;
    int w = 0;
    for(int j=0; j<T.size(); j++){
      if(i != j && W[j] <= T[i].first){
	if(M<L[j]) {M = L[j]; MI = j; w = W[j];}
      }
    }

    if(MI != -1){
      W[i] += W[MI];
      L[i] += L[MI];
    }
    if ( max_len < L[i] ) max_len = L[i];
  }

  cout << max_len << endl;
}

main(){
  read();
  work();
}
// @end_of_source_code
