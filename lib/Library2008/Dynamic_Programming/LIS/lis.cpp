#include<iostream>
using namespace std;

#define MAX 2000

void printLIS(int i, int S[], int P[]){
    if ( P[i] == -1 ) return;
    printLIS(P[i], S, P);
    cout << S[i] << " ";
}

int LIS(int size, int S[]){
    int L[MAX+1], P[MAX+1];
    S[0] = 0;
    L[0] = 0;
    P[0] = -1;
    for ( int i = 1; i <= size; i++ ){
	int k = 0; // max index
	for ( int j = 0; j <= i - 1; j++ ){
	    if ( S[j] < S[i] && L[j] > L[k] ){
		k = j;
	    }
	}
	L[i] = L[k] + 1;
	P[i] = k;
    }

    // print result
    int maxv = 0;
    int maxi;
    for ( int i = 1; i <= size; i++ ){
	if ( maxv <= L[i] ){
	    maxv = L[i];
	    maxi = i;
	}
    }
    
    cout << maxv << endl;
    cout << "-" << endl;
    printLIS(maxi, S, P);
    cout << endl;
}

int main(void){
    int size, S[MAX+1];
    cin >> size;
    for ( int i = 1; i <= size; i++ ) cin >> S[i];
    LIS(size, S);

    return 0;
}
