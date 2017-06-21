// @JUDGE_ID:  17051CA  10025  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

void work(){
  long long k, sub;
  int n;
  int sk;


  cin >> k;
  
  k = (k > 0) ? k : -k;

  if(k==1) {
    cout << 1 << endl;
    return;
  }

  if(k==0) {
    cout << 3 << endl;
    return;
  }

  float fn = (1 + sqrt(1+8*k))/2;
  long ln = (long)fn;
  if(fn - ln == 0) n = ln - 1;
  else n = ln;

  while(1){
    sub = k - n*(n+1)/2;
    if(sub%2==0){
      cout << n << endl;
      return ;
    }else{
      n++;
    }
  }

}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
