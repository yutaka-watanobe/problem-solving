// @JUDGE_ID:  17051CA  2433  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int coin[10] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000};
long long T[5001];
int doll, cent;
string line;

int read(){
  cin >> line;
  if(line=="0.00") return 0;
  return 1;
}

void work(){
  sscanf(line.c_str(), "%d.%d", &doll, &cent);
  int money = 100*doll + cent;
  printf("%5s%12lld\n", line.c_str(), T[money]);
}

void init(){
  for(int i=0; i<=5000; i++) T[i] = 1;
  for(int k=1; k<10; k++){
    for(int n=coin[k]; n<=5000; n++){
      T[n] += T[n-coin[k]];
    }
  }
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code


