#include<iostream>
using namespace std;

#define MAX 100000

void merge( int left, int mid, int right, int data[] ){
    int L[MAX/2 + 2], R[MAX/2 + 2]; // temporal buffers
    int n1 = mid - left; // size of L
    int n2 = right - mid; // size of R
    for ( int i = 0; i < n1; i++ ) L[i] = data[left + i];
    for ( int i = 0; i < n2; i++ ) R[i] = data[mid + i];

    L[n1] = R[n2] = INT_MAX;
    int i, j;
    i = j = 0;
    for ( int k = left; k < right; k++ ){
	data[k] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
}

void mergeSort( int left, int right, int data[] ){
    if ( left >= right - 1 ) return;
    int mid = ( left + right ) / 2;
    mergeSort( left, mid, data );
    mergeSort( mid, right, data );
    merge(left, mid, right, data );
}

int main(void){
    int size, data[MAX];

    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> data[i];

    mergeSort(0, size, data);

    for ( int i = 0; i < size; i++ ) cout << data[i] << " ";
    cout << endl;
    
    return 0;
}


