// @JUDGE_ID:  17051CA  10077  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int read();
void work();
int M, N;


int read(){
  cin >> M >> N;
  if(M==1&&N==1) return 0;
  return 1;
}


void work(){
  vector<char> path;
  path.clear();
  
  int lm, rm, ln, rn, m, n;
  lm = 0; rm = 1;
  ln = 1; rn = 0;
    
  while(1){
    m = lm+rm; n = ln+rn;

    if( M==m && N==n ){
      cout << endl;
      return;
    }

    if( (float)M/N < (float)m/n ){ /* to left */
      cout << 'L';
      rm = m; rn = n;
    }else if( (float)M/N > (float)m/n ){ /* to right */
      cout << 'R';
      lm = m; ln = n;
    }
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
