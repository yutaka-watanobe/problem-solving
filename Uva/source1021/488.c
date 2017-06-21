// @JUDGE_ID:  17051CA  488  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>

void work();
int h, n;

void work(){
  for(int i=1; i<=h; i++){
    for(int j=1; j<=i; j++){
      cout << i;
    }
    cout << endl;
  }
  for(int i=h-1; i>=1; i--){
    for(int j=1; j<=i; j++){
      cout << i;
    }
    cout << endl;
  }
}

main(){
  int testC;
  cin >> testC;
  for(int t=0; t<testC; t++){
    if(t!=0) cout << endl;
    cin >> h >> n;
    for(int i=0; i<n; i++){
      if(i!=0) cout << endl;
      work();
    }
  }
}
// @end_of_source_code
