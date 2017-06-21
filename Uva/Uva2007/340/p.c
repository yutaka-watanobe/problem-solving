// @JUDGE_ID:  17051CA  340  C++
// @begin_of_source_code
/* Simulation */
/* Master Mind Hints */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

int n;
vector<int> code;
int strong, weak;

int read(){
  cin >> n;
  if(n==0) return 0;
  code.clear();
  code.resize(n);
  for(int i=0; i<n; i++){
    cin >> code[i];
  }
  return 1;
}

void work(){
  vector<int> c;
  vector<int> guess;

  int k;
  while(1){
    c = code;
    strong = 0;
    weak = 0;
    int sum = 0;
    guess.clear();
    guess.resize(n);
    for(int i=0; i<n ;i++){
      cin >> guess[i];
      sum += guess[i];
      if(c[i]==guess[i]){
	strong++;
	c[i] = -1;
	guess[i] = 10;
      }
    }
    if(sum==0) return;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
	if(c[j]==guess[i]){
	  weak++;
	  c[j] = -1;
	  guess[i] = 10;
	}
      }
    }

    cout << "    (" << strong << "," << weak << ")" << endl;
  }
}

main(){
  for(int i=1; read(); i++){
    cout << "Game " << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
