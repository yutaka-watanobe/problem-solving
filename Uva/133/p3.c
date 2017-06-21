// @JUDGE_ID:  17051CA  133  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n, k, m;

int read(){
  cin >> n >> k >> m;
  if(n==0 && k==0 && m==0) return 0;
  k--; m--;
  return 1;
}

void work(){
  vector<int> v;
  int p1, p2;

  v.resize(n);
  for(int i=0; i<n; i++) v[i] = i;
  p1 = 0; p2 = n-1;

  int count = 0;
  while(count < n){
    /*
    p1 += k;
    p1 = p1%v.size();
    p2 -=  m;
    p2 = (0-p2)%v.size();
    */
    int j;
    j = 0;
    while(j < k){
      if(p1 == n) p1 = 0;
      if(v[p1]!=-1) j++;
      p1++;
    }
    j = 0;
    while(j < m){
      if(p2 == -1 ) p2 = n -1;
      if(v[p2]!=-1) j++;
      p2--;
    }

    printf("%3d", v[p1]+1);
    if(p1!=p2) printf("%3d", v[p2]+1);
    cout << ",";

    if(p1 == p2) {
      v[p1] = v[p2] = -1;
      count++;
    }else{
      v[p1] = v[p2] = -1;
      count += 2;
    }

  }
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
