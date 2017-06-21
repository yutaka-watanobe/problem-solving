// @JUDGE_ID:  17051CA  10493  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
/* 数論 */
/* H + M = H*N + 1 */
/* これを解くと H = (M-1)/(N-1) となる */
/* 上記Hが整数となれば H + M が猫の数である */
/* 帽子が一つの時に限り, Multiple である */
int H, N, M;

int read(){
  cin >> N >> M;
  if(N==0 && M==0) return 0;
  return 1;
}

void work(){
  cout << N << " " << M << " ";
  if(N==1 && M==1){
    cout << "Multiple" << endl;
    return;
  }
  if(N==1 && M!=1){
    cout << "Impossible" << endl;
    return;
  }

  if( (M-1)%(N-1)==0 ){
    cout << (M-1)/(N-1) + M << endl;
  }else{
    cout << "Impossible" << endl;
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
