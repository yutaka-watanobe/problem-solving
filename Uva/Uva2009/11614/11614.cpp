#include<iostream>
#include<cmath>
using namespace std;
#define EPS 0.00000000001
main(){
    int tcase; cin >> tcase;
    double x;
    for ( int i = 0; i < tcase; i++ ){
	cin >> x;
	cout << (int)((sqrt(1+8*x)-1)/2.0 + EPS) << endl;
    }
}
