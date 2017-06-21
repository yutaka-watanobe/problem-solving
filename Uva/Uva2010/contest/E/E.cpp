#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

typedef long long llong;
#include<iostream>
using namespace std;

#define MAX 2000

void printLIS(int i, int S[], int P[]){
    if ( P[i] == -1 ) return;
    printLIS(P[i], S, P);
    cout << S[i] << " ";
}

int LIS(int size, int S[], int W[], int ld){
    int L[MAX+1], P[MAX+1];
    S[0] = 0;
    L[0] = 0;
    P[0] = -1;
    for ( int i = 1; i <= size; i++ ){
	int k = 0; // max index
	for ( int j = 0; j <= i - 1; j++ ){
	    if ( ld == 0 ){
		if ( S[j] < S[i] && L[j] > L[k] ){
		    k = j;
		}
	    } else {
		if ( S[j] > S[i] && L[j] > L[k] ){
		    k = j;
		}
	    }
	}
	L[i] = L[k] + W[i];
	P[i] = k;
    }

    // print result
    int maxv = 0;
    int maxi;
    for ( int i = 1; i <= size; i++ ){
	if ( maxv <= L[i] ){
	    maxv = L[i];
	    maxi = i;
	}
    }
    
    return maxv;
}

int main(void){
    int size, S[MAX+1], W[MAX+1];

    int tcase; cin >> tcase;
    rep(t, tcase){
      cout << "Case " << t+1 << ". ";
      cin >> size;
      for ( int i = 1; i <= size; i++ ) cin >> S[i];
      for ( int i = 1; i <= size; i++ ) cin >> W[i];

      int lis = LIS(size, S, W, 0);
      int lds = LIS(size, S, W, 1);

      if ( lis >= lds ){
	  cout << "Increasing (" << lis << "). Decreasing (" << lds << ")." << endl;
      } else {
	  cout << "Decreasing (" << lds << "). Increasing (" << lis << ")." << endl;
      }

    }
    return 0;
}
