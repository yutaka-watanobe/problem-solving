// @JUDGE_ID: 17051CA 824 C++
#include<stdio.h>
#include<iostream>

int grid[8];

void work(){
  int x, y, i, j, d, si, sj, state;

  while(1){
    cin >> x >> y >> d;
    if(x==-1) return;
    
    for(int a=0; a<8; a++){
      cin >> i >> j >> state;
      si = i - x; sj = j - y;
      
      /* set grid */
      if(si==-1){
	if(sj==-1){
	  grid[3] = state;
	}else if(sj==0){
	  grid[2] = state;
	}else if(sj==1){
	  grid[1] = state;
	}
      }else if(si==0){
	if(sj==-1){
	  grid[4] = state;
	}else if(sj==1){
	  grid[0] = state;
	}
      }else if(si==1){
	if(sj==-1){
	  grid[5] = state;
	}else if(sj==0){
	  grid[6] = state;
	}else if(sj==1){
	  grid[7] = state;
	}
      }
    }
    
    int start;
    if(d==0) start = 6;
    else if(d==1) start = 7;
    else start = d - 2;
    
    int k = start;
    while(1){
      if(grid[k]==1){
	cout << k << endl;
	goto next;
      }
      if(k==7) k=0;
      else k++;
    }
  next:;
  }

}

main(){
  work();
}
