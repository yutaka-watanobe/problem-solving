// @JUDGE_ID:  17051CA  10105  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int n, k;

int read(){
  cin >> n >> k;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  int fuc = 1;
  for(int i=2; i<=n; i++) fuc *= i;
  
  int nn;
  for(int i=0; i<k; i++){
    cin >> nn;
    for(int j=nn; j>1; j--){
      fuc = fuc/j;
    }
  }

  cout << fuc << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
