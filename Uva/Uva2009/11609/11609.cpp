// n*2^(n-1)
// 一人のリーダーに対して, 残りの人が着くか着かないか(２択)の組み合わせ

#include<iostream>
using namespace std;
typedef unsigned long long ullong;

ullong power( ullong x, int n, const int &M ){
    if ( n == 0 ) return 1;
    ullong tmp = power(x, n/2, M);
    if ( n % 2 ) return (((tmp*tmp)%M)*x)%M;
    else return (tmp*tmp)%M;
}

main(){
    ullong n;
    ullong M = 1000000007;
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	cout << "Case #" << i << ": ";
	cin >> n;
	cout << (n*power(2, n-1, M))%M << endl;
	
    }
}
