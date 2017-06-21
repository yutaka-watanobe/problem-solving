// @JUDGE_ID:  17051CA  305  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n;
vector<int> v;

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

void work(){
  cout << v[n-1] << endl;
}

void init(){
  v.resize(14);
  int m, f;

  for(int k=1; k<14; k++){
    m = k+1;
    f = 0;
    while(1){
      int tmp = 0;
      
      for(int j=2*k; j>k; j--){
        tmp = (tmp+m-1)%j;
        if(tmp<k) goto fail;
      }
      
      v[k-1] = m;
      goto next;

    fail:;
      if(f) m += k;
      else  m++;

      f = !f;
    }
    
  next:;
  }
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code
