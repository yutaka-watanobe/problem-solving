// @JUDGE_ID:  17051CA  10327  C++
// @begin_of_source_code
/* Bubble Sort !!! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

#define MAX 1001
int n;

int V[MAX];

int read(){
  cin >> n;
  if( cin.eof() ) return 0;

  for( int i = 0; i < n; i++ ){
    cin >> V[i];
  }

  return 1;
}

void work(){
  int step = 0;

  for ( int j = 0; j < n-1; j++ ){
    for ( int i = 0; i < n-j-1; i++ ){
      if ( V[i] > V[i+1] ){
	int tmp = V[i];
	V[i] = V[i+1];
	V[i+1] =  tmp;
	step++;
      }
    }
  }

  cout << "Minimum exchange operations : " << step << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
