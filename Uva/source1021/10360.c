// @JUDGE_ID:  17051CA  10360  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

void work(){
  int grid[1025][1025] = {0};
  int d, k, ii, jj, r;
  int si, sj, ei, ej;
  cin >> d >> k;

  int max, mi, mj;
  max = 0;
  for(int i=0; i<k; i++){
    cin >> ii >> jj >> r;
    si = ii - d;
    sj = jj - d;
    ei = ii + d;
    ej = jj + d;
    if( si < 0 ) si = 0;
    if( sj < 0 ) sj = 0;
    if( ei >= 1025 ) ei = 1024;
    if( ej >= 1025 ) ej = 1024;
    for(int a=si; a<=ei; a++){
      for(int b=sj; b<=ej; b++){
	grid[a][b] += r;
	
	if(max < grid[a][b]){
	  max = grid[a][b];
	  mi = a; mj = b;
	}else if(max==grid[a][b]){
	  if(mi > a ){
	    max = grid[a][b];
	    mi = a; mj = b;
	  }else if(mi==a){
	    if(mj > b){
	      max = grid[a][b];
	      mi = a; mj = b;
	    }
	  }
	}

      }
    }
  }

  cout << mi << " " << mj << " " << max << endl;
  
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}

// @end_of_source_code
