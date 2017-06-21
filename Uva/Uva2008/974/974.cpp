#include<iostream>
using namespace std;
#define MAX 40000

bool C[MAX+1];

bool isKaprekarNumber(int x){
    long long xx = x*x;
    long long p = 10;
    long long left, right;
    while(1){
	left = xx/p;
	right = xx%p;
	if ( left <= 0 ) break;
	//cout << left << " " << right << endl;
	if ( left > 0 && right > 0 && left + right == x ) return true;
	p *= 10;
    }
    return false;
}

void init(){
    for ( int i = 0; i <= MAX; i++ ) C[i] = false;
    C[0] = C[1] = false;
    for ( int i = 2; i <= MAX; i++ ){
	if ( isKaprekarNumber(i) ) C[i] = true;
    }
}

int main(){
    //    int n;
    //    while( cin >>n ) isKaprekarNumber(n);
    init();
    int tcase; cin >> tcase;
    int INF, SUP, cnt;
    for ( int i = 1; i <= tcase; i++ ){
	if ( i > 1 ) cout << endl;
	cout << "case #" << i << endl;
	cin >> INF >> SUP;
	cnt = 0;
	for ( int j = INF; j <= SUP; j++ ){
	    if ( C[j] ) { cout << j  << endl; cnt++;}
	}
	if ( cnt == 0 ) cout << "no kaprekar numbers" << endl;
    }
}
