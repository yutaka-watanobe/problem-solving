// @JUDGE_ID:  17051CA  436  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

double T[35][35];
double V[35][35]; /* value */

int n;
map<string, int> mp;

int read(){
  cin >> n;
  if(n==0) return 0;
  
  string line;
  for(int i=0; i<n; i++){
    cin >> line;
    mp[line] = i;
  }
  
  int m;

  cin >> m;
  string s1, s2;
  double d;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      T[i][j] = 1;
    }
  }

  for(int i=0; i<m; i++){
    cin >> s1 >> d >> s2;
    T[mp[s1]][mp[s2]] = d;
  }

  return 1;
}

void work(){

  for(int i=0; i<n; i++){

    for(int m=0; m<n; m++) V[m][0] = 1;

    for(int k=1; k<=n; k++){

      for(int j=0; j<n; j++){

	V[j][k] = 0 ;
	
	if(k==1){
	  V[j][k] = T[i][j];
	}else{
	  for(int r=0; r<n; r++){
	    if(V[j][k] < V[r][k-1]*T[r][j]){
	      V[j][k] = V[r][k-1]*T[r][j];
	    }
	  }
	}
	if(i==j){
	  if(V[j][k] > 1){
	    goto next;
	  }
	}
      }
    }
  }
  
  cout << "No" << endl;
  return;

 next:;
  cout << "Yes" << endl;

}

main(){
  for(int i=1; read(); i++){
    cout << "Case " << i << ": ";
    work();
  }
}
// @end_of_source_code
