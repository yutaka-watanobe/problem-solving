#include<stdio.h>
#include<iostream>
using namespace std;
typedef unsigned long long ullong;

ullong power( ullong x, int n, const int &M ){
    if ( n == 0 ) return 1;
    ullong tmp = power(x, n/2, M);
    if ( n % 2 ) return (((tmp*tmp)%M)*x)%M;
    else return (tmp*tmp)%M;
}

ullong power( ullong x, int n ){
    if ( n == 0 ) return 1;
    ullong tmp = power(x, n/2);
    if ( n % 2 ) return tmp*tmp*x;
    else return tmp*tmp;
}

main(){
    ullong x;
    int n;
    while( cin >> x >> n ){
	cout << power(x, n) << endl;
  }
}
