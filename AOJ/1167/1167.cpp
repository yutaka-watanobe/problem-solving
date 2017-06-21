#include<iostream>
using namespace std;
#define MAX 1000000
main(){
    int T1[MAX], T2[MAX];
    for ( int i = 0; i < MAX; i++ ) T1[i] = T2[i] = i;
    int  n = 1;
    while(1){
	int i = n*(n+1)*(n+2)/6;
	if ( i >= MAX ) break;

	for ( int j = i; j < MAX; j++ ) T1[j] = min(T1[j], T1[j-i]+1);
	if ( i % 2 ){
	    for ( int j = i; j < MAX; j++ ) T2[j] = min(T2[j], T2[j-i]+1);
	}
	n++;
    }

    while(1){
	cin >> n;
	if ( n == 0 ) break;
	cout << T1[n] << " " << T2[n] << endl;
    }
}
