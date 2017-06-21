// @JUDGE_ID:  17051CA  10487  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int n;
vector<int> A;

int read(){
  cin >> n;
  if(n==0) return 0;

  A.resize(n);
  for(int i=0; i<n; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  return 1;
}

int search(int k){
  int v, m;
  m = -100000;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      v = A[i]+A[j];
      if(v==k) return v;
      
      if(abs(v-k)<abs(m-k)) m = v;
      
      if(v>k ) goto next;
    }
  next:;
  }
  return m;
}

void work(){
  int k, q ;
  cin >> k;
  for(int i=0; i<k; i++){
    cin >> q;
    cout << "Closest sum to " << q << " is " << search(q) << "." << endl;
  }
}

main(){
  for(int i=1; read(); i++){
    cout << "Case " << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
