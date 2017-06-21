// @JUDGE_ID:  17051CA  10365  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#define MAX 100000;
void work();

int n;

void work(){
  int m, l, k;
  int min = MAX;
  int area;
  cin >> m;
  for(int i=1; i<=m; i++){
    if(m%i==0){
      l = m/i;
      for(int j=i; j<=l; j++){
	if(l%j==0){
	  k = l/j;
	  /* cout << i << " " << j << " " << k << endl; */
	  area = 2*(i*j+i*k+j*k);
	  if( min > area ) min = area;
	}
      }
    }
  }
  cout << min << endl;
}

main(){
  cin >> n;
  for(int i=0; i<n; i++) work();
}
// @end_of_source_code
