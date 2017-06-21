#include<iostream>
using namespace std;
#define MAX 101

int D[MAX];

bool check(){
    if ( D[1]%2 == 0 || D[2]%2 == 0 ) return false;
    for ( int i = 3; i < MAX; i++ ) if ( D[i]%2 ) return false;
    return true;
}

main(){
    int a, b;
    while( cin >> a >> b ){
	for ( int i = 1; i <= MAX; i++ ) D[i] = 0;
	D[a]++; D[b]++;
	while(1){
	    cin >> a >> b;
	    if ( a == 0 && b == 0) break;
	    D[a]++; D[b]++;
	}
	cout << (check()?"OK":"NG") << endl;
    }
}
