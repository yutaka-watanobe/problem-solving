#include<iostream>
using namespace std;

int josephus(int n, int k){
    return (n == 1 ? 0 : (josephus(n-1, k) + k) % n);
}

main(){
    int tcase, n, k;
    cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cin >> n >> k;
	cout << "Case " << i+1 << ": " << josephus( n, k )+1 << endl;
    }
}
