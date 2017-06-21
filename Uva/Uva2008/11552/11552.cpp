#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<cassert>

using namespace std;
#define MAX 1000

static const int INFTY = (1 << 21);

int compute(){
    int k, n;
    string S;
    cin >> k >> S;
    n = S.size()/k;
    set<char> alpha;
    set<char>::iterator pi, pj;

    int T[26][MAX+1];

    int cnt = 1;
    if ( k == 1 ){
	for ( int s = 1; s < S.size(); s++ ) if ( S[s-1] != S[s] ) cnt++;
	return cnt;
    }


    int p = 0;
    for ( int s = 0; s < S.size(); s += k ){
	alpha.clear();
	for ( int j = s; j < s + k; j++ ){
	    alpha.insert(S[j]);
	}
	//for (  it = alpha.begin(); it != alpha.end(); it++ )  cout << *it;
	//cout << endl;
	for ( int i = 0; i < 26; i++ ) T[i][p] = INFTY;
	if ( p == 0 ){
	    //	    for ( int i = 0; i < 26; i++ ) T[i][p] = alpha.size();
	    for ( pi = alpha.begin(); pi != alpha.end(); pi++ ) T[*pi-'a'][p] = alpha.size();
	} else {
	    for ( pi = alpha.begin(); pi != alpha.end(); pi++ ){
		for ( pj = pi; pj != alpha.end(); pj++ ){
		    if ( alpha.size() > 1 &&  *pi == *pj ) continue;
		    // pi,,,pj
		    for ( int i = 0; i < 26; i++  ){
			if ( T[i][p-1] == INFTY ) continue;
			if ( (i+'a') == *pi ){
			    T[*pj-'a'][p] = min(T[*pj-'a'][p], T[i][p-1] + (int)alpha.size()-1);
			} else {
			    T[*pj-'a'][p] = min(T[*pj-'a'][p], T[i][p-1] + (int)alpha.size());
			}
		    }
		}
	    }
	}
	p++;
    }

    assert( p == n );
    int minv = INFTY;
    for ( int i = 0; i < 26; i++ ) minv = min(minv, T[i][n-1]);

    return minv;
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) cout << compute() << endl;
    return 0;
}
