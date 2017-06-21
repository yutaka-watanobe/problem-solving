#include<iostream>
using namespace std;

main(){
    int n; 
    while( cin >> n && n ){
	int t = 0;
	while(n != 1){
	    if ( n % 2 == 0 ) n /= 2;
	    else n = 3*n + 1;
	    t++;
	}
	cout << t << endl;
    }
}
