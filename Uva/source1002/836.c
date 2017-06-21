// @JUDGE_ID:  17051CA  836  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<iostream>
#define MAX 30

int read();
void work();

int n;
string line;
unsigned char grid[MAX][MAX];

int read(){
  cin >> n;
  return 1;
}

void work(){
  int N, max;
  int i1, i2, j1, j2, a, b, c, d, i, j;
  bool one;
  /* read */
  cin >> line;
  N = line.size();
  for(j=0; j<line.size(); j++){
    grid[0][j] = line[j];
  }
  for( i=1; i<N; i++){
    cin >> line;
    for(j=0; j<N; j++){
      grid[i][j] = line[j];
    }
  }
  max = 0;
  for(a=0; a<N; a++){
    for(b=a+1; b<=N; b++){
      for(c=0; c<N; c++){
	for(d=c+1; d<=N; d++){
	  i1 = c; j1 = a;
	  i2 = d-1; j2 = b-1;
	  one = true;
	  for(i=i1; i<=i2; i++){
	    for(j=j1; j<=j2; j++){
	      if( grid[i][j] == '0' ){
		one = false;
		goto next;
	      }
	    }
	  }
	next:;
	  if(one){
	    if( max < (i2-i1+1)*(j2-j1+1) ){
	      max = (i2-i1+1)*(j2-j1+1);
	    }
	  }
	}
      }
    }
  }
  cout << max << endl;
}

main(){
  read();
  for(int i=0; i<n; i++){
    if( i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
