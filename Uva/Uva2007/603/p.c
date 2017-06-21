// @JUDGE_ID:  17051CA  603  C++
// @begin_of_source_code
/* シミュレーション */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

string line;
vector<int> A, IA;

void read(){
  A.clear(); IA.clear();
  int k;
  while(1){
    cin >> k; 
    if(k==99) break;
    A.push_back(k-1);
    IA.push_back(k);
  }
}

void work(){
  vector<bool> visited(A.size(), false);
  int target, source;
  int sub, s, index;
  getline(cin, line);
  while(getline(cin, line) && !line.empty()){
    source = atoi(line.c_str()) - 1;
    sub = 100;
    for(int i=0; i<A.size(); i++){
      target = A[i];

      if(!visited[i]){
	if(source<target) s = 19 - (target - source) + 1;
	else if(source>target) s = source - target;
	else{
	  sub = 0;
	  index = i;
	  goto next;
	}
	if(sub > s){
	  sub = s;
	  index = i;
	}
      }
    }
  next:;
    A[index] = source;
    visited[index] = true;
    for(int i=0; i<A.size(); i++){
      if(!visited[i]){ 
	if(sub>0)A[i] += (sub); 
	A[i] = A[i]%20;
      }
    }
  }
  
  for(int i=0; i<A.size(); i++){
    cout << "Original position " << IA[i] << " ";
    if(!visited[i]) cout << "did not park" << endl;
    else cout << "parked in " << A[i]+1 << endl;
  }

}

main(){
  int testCase;
  cin >> testCase; 
  for(int i=0; i<testCase; i++){
    if(i) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
