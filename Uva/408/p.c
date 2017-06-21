// @JUDGE_ID:  17051CA  408  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int step, mod;

int read(){
  cin >> step >> mod;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  int seed = 0;
  bool isGood = true;
  for(int i=0; i<mod-1; i++){
    seed = (seed+step)%mod;
    if(seed==0){
      isGood = false;
      break;
    }
  }

  printf("%10d", step);
  printf("%10d", mod);

  if( isGood ){
    cout << "    Good Choice" << endl;
  }else{
    cout << "    Bad Choice" << endl;
  }
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
