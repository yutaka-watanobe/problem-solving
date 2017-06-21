#include <stdio.h>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include<climits>
using namespace std;

pair<int, int> knapsack(const vector<int> &value, const vector<int> &weight, 
			int lim){
  static int W[1001];

  for(int i=0; i<=lim; i++){
    W[i] = INT_MAX;
  }
  
  W[0] = 0;

  for(int i=0; i<value.size(); i++){
    for(int j=lim; j>=0; j--){
      int k = j+weight[i];

      if(W[j]!=INT_MAX && k<=lim){
	if(W[k] == INT_MAX){
	  W[k] = value[i]+W[j];
	}
	else {
	  W[k] = max(W[k], W[j]+value[i]);
	}
      }
    }
  }

  int maxValue = 0, maxWeight = 0;

  for(int i=lim; i>=0; i--){
    if(W[i] == INT_MAX) continue;

    if(maxValue <= W[i]){
      maxValue = W[i];
      maxWeight = i;
    }
  }

  return make_pair(maxValue, maxWeight);
}

int main(){
  vector<int> value, weight;
  int lim;
  
  for(int t=1; ; t++){
    cin >> lim;

    if(lim == 0) break;

    int n;

    cin >> n;

    value.resize(n);
    weight.resize(n);

    for(int i=0; i<n; i++){
      scanf("%d,%d", &value[i], &weight[i]);
    }
    
    cout << "Case " << t << ":" << endl;

    pair<int, int> r = knapsack(value, weight, lim);

    cout << r.first << endl;
    cout << r.second << endl;
  }

  return 0;
}
