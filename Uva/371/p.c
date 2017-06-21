// @JUDGE_ID:  17051CA  371  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 100001

int read();
void work();
void init();
int getV(unsigned long);
unsigned int v[MAX];

void init(){
  v[0] = 0;
  unsigned int count = 0;
  unsigned int n;
  for(int i=1; i<MAX; i++){
    n = i;
    count = 0;
    while( n != 1 ){
      if(n%2==0){
	n = n/2;
      }else{
	n = 3*n+1;
      }
      count++;
    }
    v[i] = count;
  }
  v[1] = 3;
}

int getV(unsigned long n){
  int count = 0;
  while( n != 1 ){
    if(n%2==0){
      n = n/2;
    }else{
      n = 3*n+1;
    }
    count++;
  }
  return count;
}

unsigned long L, H;
int read(){
  cin >> L >> H;
  if( L == 0 && H == 0 ) return 0;
  if ( H < L ) swap(H, L);
  else return 1;
}

void work(){
  unsigned int maxV = 0;
  unsigned int maxI = 0;

  for(unsigned long i=L; i<=H; i++){
    if( i >= MAX){
      int m = getV(i);
      if( m > maxV){
	maxV = m;
	maxI = i;
      }
    }else{
      if( v[i] > maxV ){
	maxV = v[i];
	maxI = i;
      }
    }
  }
  cout << "Between " << L << " and " << H << ", " << maxI << " generates the longest sequence of " << maxV << " values." << endl;
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code
