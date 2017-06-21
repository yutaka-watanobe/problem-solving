#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 100000

int getNumber(){
    //    int x; scanf("%d", &x); return x;
    int n = 0;
    char ch;
    while(1){
	ch = getchar();
	if ( ch == ' ' || ch == '\n' ) break;
	n *= 10; n += ch-'0';
    }
    return n;
}

int cnt;

void add( int k, int ij ){
    if ( k < ij ) cnt += (ij - k);
}

void merge( int data[], int left, int mid, int right ){
    int L[MAX/2 + 2], R[MAX/2 + 2]; // temporal buffers
    int n1 = mid - left; // size of L
    int n2 = right - mid; // size of R
    for ( int i = 0; i < n1; i++ ) L[i] = data[left + i];
    for ( int i = 0; i < n2; i++ ) R[i] = data[mid + i];
    L[n1] = R[n2] = INT_MAX;
    int i, j;
    i = j = 0;
    for ( int k = left; k < right; k++ ){
        if ( L[i] <= R[j] ) { data[k] = L[i++]; add(k, left+i-1);}
        else {data[k] = R[j++], add(k, mid+j-1);}
    }
}

void mergeSort( int data[], int left, int right ){
    if ( left >= right - 1 ) return;
    int mid = ( left + right ) / 2;
    mergeSort( data, left, mid );
    mergeSort( data, mid, right );
    merge(data, left, mid, right );
}

int main(){
    int data[MAX], size;
    while(1){
	size = getNumber();
	if ( size == 0 ) break;
	for ( int i = 0; i < size; i++ ){
	    data[i] = getNumber();
	}
	cnt = 0;
	mergeSort(data, 0, size);
	//	cout << cnt << endl;
	if ( cnt % 2 == 0 ) printf("Carlos\n");
	else printf("Marcelo\n");

    }
    
    return 0;
}

