#include<iostream>
using namespace std;

main(){
    int n; cin >> n;
    long long x, sum = 0;
    for ( int i = 0; i < n; i++ ){
	cin >> x; sum += x;
    }
    
    cout << (int)(sum/n) << endl;
}
