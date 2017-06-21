// @JUDGE_ID:  17051CA  350  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#define MAX 10000

long Z, I, M, L;

int read(){
  cin >> Z >> I >> M >> L;
  if(Z==0 && I==0 && M==0 && L==0) return 0;
  return 1;
}

void work(){
  long cnt = 0;
  map<long, bool> mp; 
  map<long, long> length; 

  long V = L;
  mp[L] = true;
  while(1){
    cnt++;
    V = (Z*V + I)%M;
    if(mp[V]) break;
    mp[V] = true;
    length[V] = cnt;
  }

  cout << cnt - length[V] << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "Case " << i << ": ";
    work();
  }
}
// @end_of_source_code
