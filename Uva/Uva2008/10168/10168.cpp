#include<iostream>
#include<cmath>
using namespace std;

#define MAX 10000002

void eratos ( int n, bool prime[]){
   for ( int i = 1; i <= n/2; i++ ) prime[i] = true;
   int limit = (int)sqrt((double)n) + 1;
   for ( int i = 3; i <= limit; i += 2 ){
       if ( !prime[i/2] ) continue;
       for ( int j = i + i; j <= n; j += i ) {
	   if ( j % 2 != 0 ) prime[j/2] = false;
       }
   }
}

bool prime[MAX/2+10];
bool isPrime(int x){
    if ( x == 2 ) return true;
    if ( x % 2 == 0 ) return false;
    return prime[x/2];
}

pair<int, int> getPair(int x ){
    for ( int i = 2; i <= x; i++ ){
	if ( isPrime(i) && isPrime(x-i) ){
	    return make_pair(i, x-i);
	}
    }
}

int main(){
    
    eratos(MAX, prime);

    /*
    int y;
    while( cin >> y ){
	if ( isPrime(y) ) cout << "P" << endl;
	else cout << "no" << endl;
	}*/
    /*
    pair<int, int> T[(MAX/2)+10];
    for ( int n = 4; n <= MAX; n += 2 ){
	for ( int i = 2; i <= n; i++ ){
	    if ( isPrime(i) && isPrime(n-i) ){
		T[n/2] = make_pair(i, n-i);
		goto next;
	    }
	}
    next:;
    }
    */

    int x, l, r;
    pair<int, int> left, right;
    while( cin >> x ){
	if ( x < 8 ) cout << "Impossible." << endl;
	else if ( x == 8 ) cout << "2 2 2 2" << endl;
	else {
	    if ( x % 2 == 0 ){
		l = x/2;
		r = x/2;	    
		if ( l % 2 != 0 ) { l--; r++; };
	    } else {
		l = 5;
		r = x - 5;
	    }

	    left = getPair(l);
	    right = getPair(r);
	    cout << left.first << " " << left.second << " ";
	    cout << right.first << " " << right.second << endl;

	    //	    cout << T[l/2].first << " " << T[l/2].second << " ";
	    //	    cout << T[r/2].first << " " << T[r/2].second << endl;
	}
    }

    return 0;
}
