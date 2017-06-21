// @JUDGE_ID:  17051CA  10014  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

float val[3010];
float C[3010];

void work(){
  int n;
  float a0, a1, an, a, c, b;
  int k;

  cin >> n;
  cin >> a0;
  cin >> an;

  val[0] = a0;
  val[n] = an;

  b = val[n];
  k = 1;

  for(int i=1; i<=n; i++){
    cin >> C[i];
  }

  for(int i=n; i>=1; i--){
    b = ((float)k/(k+1))*b - ((float)k*2/(k+1))*C[i];
    k++;
  }
  k--;
  a1 = ((float)k/(k+1))*a0 + b;

  printf("%.2f\n", a1);
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
