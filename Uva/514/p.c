// @JUDGE_ID:  17051CA  514  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int A[1001];
int B[1001];

int n;

bool read(){
  cin >> n;
  if(n==0) return false;

  for(int i=0; i<n; i++){
    A[i] = i + 1;
  }

  return  true;
}

void station(){
  int posA, posB;
  posA = posB = 0;
  vector<int> st;

  for(int posA=0; posA<n;){
    if(A[posA]==B[posB]){
      posB++;
      posA++;
    }else if(st.size()>0 && B[posB]==st[st.size()-1]){
      posB++;
      st.erase(st.begin() + st.size()-1);
    }else{
      st.push_back(A[posA]);
      posA++;
    }
  }
  
  if(st.size()==0) cout << "Yes" << endl;
  else cout << "No" << endl;


}

void work(){
  int k;
  while(1){
    for(int i=0; i<n; i++){
      cin >> k;
      if(k==0) return;
      B[i] = k;
    }
    station();
  }
}

main(){
  while(read()){
    work();
    cout << endl;
  }
}
// @end_of_source_code
