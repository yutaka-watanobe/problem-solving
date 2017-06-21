// math (numbers sequence)
// Base = (n+1)*(n+1) - 1
// ans = Base + Base - 2 + Base - 4
#include<iostream>
using namespace std;
typedef unsigned long long ullong;

main(){
    ullong n;
    while ( cin >> n ){
	cout << 3*(n+1)*(n+1)/2 - 9 << endl;
    }
}
