#include<iostream>
using namespace std;
#define MAX 1000000
void compute(int n){

	if ( i >= MAX ) break;

	for ( int j = i; j < MAX; j++ ) T1[j] = min(T1[j], T1[j-i]+1);
	if ( i % 2 ){
	    for ( int j = i; j < MAX; j++ ) T2[j] = min(T2[j], T2[j-i]+1);
	}
	n++;
    }

    main(){
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	compute(n);
    }
}
