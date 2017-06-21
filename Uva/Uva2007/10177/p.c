// @JUDGE_ID:  17051CA  10177  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
typedef unsigned long long ullong;

int n;
int sum[101];

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

void init(){
  sum[0] = 0;
  for(int i=1; i<=100; i++){
    sum[i] = sum[i-1] + i;
  }
}

ullong pow(int x, int e){
  ullong v =1;
  for(int i=0; i<e; i++) v *= x;
  return v;
}
void work(){
  ullong square, rectangle;

  for(int d=2; d<=4; d++){
    if(d!=2) cout << " ";
    square = rectangle = 0;    
    for(int i=1; i<=n; i++){
      square += pow(i, d);
      rectangle += i * pow(sum[n], d-1);
    }
    rectangle -= square;
    cout << square << " " << rectangle;
  }
  cout << endl;



}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code
