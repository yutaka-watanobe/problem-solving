#include<iostream>
using namespace std;

void compute( int source ){
    bool M[10000];
    for ( int i = 0; i < 10000; i++ ) M[i] = false;
    M[source] = true;
    int cnt = 1;
    int x = source;
    while(1){
	x = ((x*x)/100)%10000;
	if ( M[x] ) break;
	M[x] = true;
	cnt++;
    }
    cout << cnt << endl;
}

main(){
    int n;
    while( cin >> n && n ) compute(n);
}
