#include<iostream>
#include<vector>
#include<cassert>
#include<map>

using namespace std;

const int MAX_MONEY = 5000;

main(){
  int x,n,e;
  while(cin >> x >> n >> e && x){
    pair<int,int> event[n+1];
    double table[n+1][MAX_MONEY+1];
    int num[x];

    for(int i = 0;i<x;i++)
      cin >> num[i];

    for(int i = 0;i<n+1;i++){
      event[i] = make_pair(0,0);
    }
    
    for(int i = 0;i<n+1;i++)
      for(int j = 0;j<=MAX_MONEY;j++)
	table[i][j] = 0;

    table[0][0] = 1;
        
    for(int i = 0;i<e;i++){
      int m,e,a;
      cin >> m >> e >> a;

      event[m] = make_pair(e,a);
    }

    for(int i = 0;i<n;i++){
      for(int j = 0;j<=MAX_MONEY;j++)
	for(int k = 0;k<x;k++){
	  int pos = i+num[k];
	  bool isIgnore = false;
	  
	  if(event[pos].first == 1){
	    isIgnore = true;
	    pos += event[pos].second;
	  }

	  if(pos > n)
	    pos = n;
	
	  if(event[pos].first == 0 || event[pos].first == 1 || isIgnore)
	    table[pos][j] += table[i][j] / (double)x;
	  
	  else if(event[pos].first == 2)
	    table[pos][j+event[pos].second] += table[i][j] / (double)x;
	  
	  else
	    table[pos][j-event[pos].second < 0 ? 0 : j-event[pos].second] += table[i][j] / (double)x;
	}
    }
    
    double ans = 0;
    for(int j = 0;j<=MAX_MONEY;j++){
	ans += j*table[n][j];
      }
    
    cout << (int)ans << endl;
  }
  return 0;
}
