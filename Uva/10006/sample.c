#include <iostream>
#include <cmath>

using namespace std;

class TCarmichaelNumbers {
public:

	int N;

	bool input() {
		cin >> N;
		if ( N == 0 ) return false;
		return true;
	}

	void work() {
		if ( isCarmichael(N) )
			cout << "The number " << N << " is a Carmichael number." << endl;
		else
			cout << N << " is normal." << endl;
	}

	bool isCarmichael( int n ) {
		if ( isprime(n) || n == 1 ) return false;

		// 合成数であることが保証された.
		// 全てに対してフェルマー判定をすり抜ければ true となる.
		for ( unsigned int a = 2; a < n; a++ )
			if ( powmod(a, n, n) != a ) return false;
		return true;
	}

	unsigned int powmod( unsigned int n, unsigned int p, unsigned int m ) {
		if ( p == 0 ) return 1;
		const unsigned int d = powmod(n, p/2, m);
		const unsigned int r = d * d % m;
		return (p & 1)? r * n % m : r;
	}

	bool isprime( int n ) {
		if ( n == 0 || n == 1 ) return false;

		if ( n == 2 || n == 3 ) return true;
		if ( n % 2 == 0 || n % 3 == 0 ) return false;

		const int limit = (int)sqrt(n);
		for ( int i = 5, b = 1; i <= limit; b = -b, i += 3 + b )
			if ( n % i == 0 ) return false;
		return true;
	}

};

int main() {
	TCarmichaelNumbers TCN;

	while ( TCN.input() )
		TCN.work();	

	return 0;
}
