#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAX 1000000
using namespace std;

void eratos ( int n, vector<int> &v){
    bool prime[MAX+1];
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
    for ( int i = 0; i <=n; i++ ) if (prime[i]) v.push_back(i);
}

main(){
    int N, P;
    vector<int> primes;
    eratos(MAX, primes);

    int k;
    while(1){
	cin >> N >> P;
	if ( N == -1 && P == -1 ) break;
	int s = distance(primes.begin(), upper_bound(primes.begin(), primes.end(), N));

	vector<int> v;
	for ( int i = s; i < s+P; i++ ){
	    for ( int j = i; j < s+P; j++ ){
		v.push_back(primes[i] + primes[j]);
	    }
	}
	sort(v.begin(), v.end());
	cout << v[P-1] << endl;
    }
}
