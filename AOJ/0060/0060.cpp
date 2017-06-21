#include<iostream>
using namespace std;

main(){
  int a, b, c, cnt;
    while( cin >> a >> b >> c ){
	cnt = 0;
	for ( int i = 1; i <= 10; i++ ){
	    if ( i == a || i == b || i == c ) continue;
	    if ( a + b + i <= 20 ) cnt++;
	}
	cout << (cnt >= 4  ? "YES" : "NO") << endl;
    }
}
