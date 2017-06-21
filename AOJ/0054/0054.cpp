#include<iostream>
using namespace std;

int main(){
  int a, b, n, q, r, sum;
    while( cin >> a >> b >> n ){
	q = a/b;
	r = a%b;
	sum = 0;
	for ( int i = 0; i < n; i++ ){
	    r *= 10;
	    sum += r/b;
	    r = r%b;
	}
	cout << sum << endl;
    }
    return 0;
}
