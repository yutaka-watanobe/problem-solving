#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
static const int MAX = 1000000;

void eratos ( int n, bool prime[], vector<int> &v){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    for ( int i = 3; i <= limit; i += 2 ){
        if ( !prime[i] ) continue;
        for ( int j = i * i, k = i * 2; j <= n; j += k )
        prime[j] = false;
    }

    for ( int i = 2; i <= n; i++ ){
	if ( prime[i] ) v.push_back(i);
    }
}

main(){
    bool prime[MAX+1];
    vector<int> primeList;
    eratos(MAX, prime, primeList);

    int x, p1, p2, ap1, ap2;
    while( cin >> x && x ){
	int diff = INT_MIN;
	for ( int i = 0; i < primeList.size(); i++ ){
	    p1 = primeList[i];
	    if ( p1 >= x ) break;
	    p2 = x - p1;
	    if ( !prime[p2] ) continue;
	    if ( p1 > p2 ) continue;
	    if ( p2 - p1 > diff ) {
		diff = p2 - p1;
		ap1 = p1;
		ap2 = p2;
	    }
	}
	cout << x << ":" << endl;
	if ( diff == INT_MIN ) cout << "NO WAY!" << endl;
	else cout << ap1 << "+" << ap2 << endl;

    }

}
