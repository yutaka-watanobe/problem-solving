#include<iostream>
using namespace std;
#define MAX 3000

static const int C[6] = {1, 5, 10, 50, 100, 500};
//static const int C[6] = {1, 2, 7, 8, 12, 50};
int T[MAX+1];

int compute(int n){
    int ans = 0;
    
    for ( int i = 5; i >= 0; i-- ){
	if ( n >= C[i] ){
	    ans += n/C[i];
	    n = n%C[i];
	}
    }
    return ans;
}

int main(){
    int n;
    while( cin >> n ) cout << compute(n) << endl;

    return 0;
}
