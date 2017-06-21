#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;

bool check( int C[MAX] ){
    int m = (C[0] + C[1] + C[2])%C[9];
    if ( (C[3] + C[4] + C[5])%C[9] != m ||
	 (C[6] + C[7] + C[8])%C[9] != m ||
	 (C[0] + C[3] + C[6])%C[9] != m ||
	 (C[1] + C[4] + C[7])%C[9] != m ||
	 (C[2] + C[5] + C[8])%C[9] != m ||
	 (C[0] + C[4] + C[8])%C[9] != m ||
	 (C[2] + C[4] + C[6])%C[9] != m ) return false;
    return true;
}

void compute( int T[MAX] ){
    int P[10], C[10], size, cnt;
    cnt = size = 0;
    bool used[11];
    for( int i = 1; i <= MAX; i++) used[i] = false;
    for( int i = 0; i < MAX; i++ ) used[T[i]] = true;
    for( int i = 1; i <= MAX; i++) if ( !used[i] ) P[size++] = i;
    sort(P, P + size);

    do{
	for ( int i = 0; i < MAX; i++ ) C[i] = T[i];
	for ( int i = 0, pos = 0; i < MAX; i++ ){
	    if ( C[i] == 0 ) C[i] = P[pos++];
	}
	if ( check(C) ) cnt++;
    }while( next_permutation(P, P + size) );

    cout << cnt << endl;
}

int main(){
    int T[10];

    while( cin >> T[0] && T[0] != -1 ){
	for ( int i = 1; i < MAX; i++ ) cin >> T[i];
	compute(T);
    } 
   
    return 0;
}
