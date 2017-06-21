// eratostenes
// 2 nested loop

#include<iostream>
#include<cmath>
using namespace std;
#define MAX 10000
#define PMAX 1229
bool prime[MAX+1]; // prime number table
int T[MAX+1];

void eratos(int n){
    fill(prime, prime+MAX, false);
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    for ( int i = 3; i*i <= n; i += 2 ) {
	if ( !prime[i] ) continue;
	for ( int j = i * i, k = i * 2; j <= n; j += k ) prime[j] = false;
    }
}

void initialize(){
    eratos(MAX);
    int plist[1229];
    int size = 0;
    for ( int i = 2; i <= MAX; i++ ){
	if  ( prime[i] ) plist[size++] = i;
    }
    for ( int i = 0; i <= MAX; i++ ) T[i] = 0;

    for ( int i = 0; i < size; i++ ){
	int sum = 0;
	for ( int j = i; j < size; j++ ){
	    sum += plist[j];
	    if ( sum >= MAX ) continue;
	    T[sum]++;
	}
    }
}

main(){
    initialize();
    int n;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	cout << T[n] << endl;
    }
}