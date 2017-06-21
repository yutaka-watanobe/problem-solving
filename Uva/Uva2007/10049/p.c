// @JUDGE_ID:  17051CA  10049  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int n, size;
int A[1000000];

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void init(){
  A[0] = 0;
  A[1] = 1;
  A[2] = 2;
  A[3] = 4;
  A[4] = 6;

  int index = 5;
  int w;

  while(A[index-1]<2000000000){
    int *p = upper_bound(A, A+index, index-1);
    w = distance(A, p)-1;

    for(int i=0; i<*p-*(p-1); i++){
      A[index] = A[index-1] + w;
      index++;
    }
  }
  
  size = index;
}

void work(){
  cout << distance(A, upper_bound(A, A+size, n)) -1 << endl;
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code
