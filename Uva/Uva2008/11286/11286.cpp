#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long llong;
#define MAX 10000
#define NC 5

int n;
llong C[MAX];
map<int, int> M;

void input(){ 
    llong tmp[NC];
    M = map<int, int>();

    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < NC; j++ ) cin >> tmp[j];
	sort( tmp, tmp + NC );
	llong value = 0;
	llong p = 1;
	for ( int j = NC-1; j >= 0; j--, p *= 1000 ) {
	    value += tmp[j]*p;
	}
	C[i] = value;
	M[value]++;
    }
}

void compute(){
    map<int, int>::iterator it;
    int maxv = 0;
    for ( it = M.begin(); it != M.end(); it++ ){
	maxv = max( maxv, (*it).second);
    }

    int cnt = 0;
    for ( int i = 0 ; i < n; i++ ){
	if ( M[C[i]] == maxv ) cnt++;
    }

    cout << cnt << endl;
}

main(){
    while( cin >> n && n ){
	input();
	compute();
    }
}
