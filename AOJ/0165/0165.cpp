// prime + DP (1d) + count
#include<iostream>
#include<cmath>
#define MAX 1000000
using namespace std;

void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
	if ( !prime[i] ) continue;
	for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
}

int main(void){
    bool prime[MAX + 1];
    eratos( MAX, prime );

    int T[MAX+1];
    for ( int i = 0; i <= MAX; i++ ) T[i] = 0;
    for ( int i = 1; i <= MAX; i++ ){
	T[i] = T[i-1];
	if ( prime[i] ) T[i]++;
    }

    int n, p, m, x, ans;
    while( cin >> n && n ){
	ans = 0;
	for ( int i = 0; i < n; i++ ){
	    cin >> p >> m;
	    x = 0;
	    int left = max(0, p-m);
	    int right = min(p+m, MAX);

	    x += T[right] - T[left];
	    if ( prime[left] ) x++;

	    if ( x == 0 )  ans--;
	    else ans += x-1;

	}
	cout << ans << endl;
    }

    return 0;
}
