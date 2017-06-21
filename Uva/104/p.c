// @JUDGE_ID:  17051CA  104  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

double T[25][25];
int Path[25][25]; /* path */
double V[25][25]; /* value */

int n;

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i==j) T[i][j] = 1;
      else cin >> T[i][j];
    }
  }
  
  return 1;
}

void work(){
  /* init */
  int kk, ii;
  bool exist = false;

  kk = 100;      
  int P[25][25];

  for(int i=0; i<n; i++){

    for(int m=0; m<n; m++) V[m][0] = 1;

    for(int k=1; k<=n; k++){

      for(int j=0; j<n; j++){

	V[j][k] = 0 ;
	
	if(k==1){
	  V[j][k] = T[i][j];
	  Path[j][k] = i;
	}else{
	  for(int r=0; r<n; r++){
	    if(V[j][k] < V[r][k-1]*T[r][j]){
	      V[j][k] = V[r][k-1]*T[r][j];
	      Path[j][k] = r;
	    }
	  }
	}

	if(i==j){
	  if(V[j][k] > 1.01){
	    if(kk > k){
	      kk = k; ii = i;
	      exist = true;
	      P = Path;
	    }
	    goto next;
	  }
	}
      }
    }
  next:;
  }

  if(!exist){
    cout << "no arbitrage sequence exists" << endl;
    return;
  }

  int next;
  vector<int> p;
  p.push_back(ii);
  next = ii;
  for(int i=kk; i>=1; i--){
    p.push_back(P[next][i]);
    next = P[next][i];
  }
  reverse(p.begin(), p.end());
  for(int i=0; i<p.size(); i++){
    if(i!=0) cout << " ";
    cout << p[i]+1;
  }
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
