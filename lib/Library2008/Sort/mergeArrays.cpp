#include<iostream>
using namespace std;

#define MAX 100000

void merge( int n1, int n2, int L[], int R[], int data[] ){
    L[n1] = R[n2] = INT_MAX;
    int i, j, k;
    i = j = k = 0;
    while ( k < n1 + n2 ){
	data[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
}

int main(void){
    int n1, n2, L[MAX/2], R[MAX/2], data[MAX];

    cin >> n1;
    for ( int i = 0; i < n1; i++ ) cin >> L[i];
    cin >> n2;
    for ( int i = 0; i < n2; i++ ) cin >> R[i];

    merge(n1, n2, L, R, data);

    for ( int i = 0; i < n1 + n2; i++ ) cout << data[i] << " ";
    cout << endl;
    
    return 0;
}


