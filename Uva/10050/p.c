// @JUDGE_ID:  17051CA  10050  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>

bool days[110][4000];


void work(){
  int n, p, k;
  vector<int> plist;

  cin >> n;
  cin >> p;
  
  for(int i=0; i<p; i++){
    cin >> k;
    plist.push_back(k);
  }


  for(int i=0; i<p; i++){
    for(int j=0; j<n; j++){
      if( (j+1)%plist[i]==0 ) days[i][j] = true;
      else days[i][j] = false;
    }
  }

  int cnt = 0;
  for(int j=0; j<n; j++){
    bool party = false;
    if( !( (j+2)%7==0  || (j+1)%7==0) ){
      for(int i=0; i<p; i++){
	if(days[i][j]){
	  party = true;
	  goto next;
	}
      }
    next:;
      if(party) cnt++;
    }
  }

  cout << cnt << endl;
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    work();
  }
}
// @end_of_source_code
