// @JUDGE_ID:  17051CA  10074  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int m, n;
int read(){
  cin >> m >> n;
  if(m==0 && n==0) return 0;
  return 1;
}

void work(){
  vector<vector<int> > v;
  vector<vector<int> > t;

  v.resize(m);
  t.resize(m);
  for(int i=0; i<m; i++){
    v[i].resize(n);
    t[i].resize(n);
  }

  /* read */
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin >> v[i][j];
    }
  }

  /* create table */
  int cnt;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cnt = 0;
      for(int jj=j; jj<n; jj++){
	if(v[i][jj]) goto next;
	else cnt++;
      }
    next:;
      t[i][j] = cnt;
    }
  }

  int maxV = 0;
  for(int j=0; j<n; j++){
    for(int i=0; i<m; i++){

      int cnt = 0;
      int val = t[i][j];      
      if(t[i][j]==0) goto next2;
      for(int ii=i; ii<m; ii++){
	val = min(val, t[ii][j]);
	cnt++;
	maxV = max(maxV, cnt*val);
      }
    next2:;

    }
  }

  cout << maxV << endl;

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
