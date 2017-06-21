#include<iostream>
using namespace std;
#define MAX 100

int bsearch( int n, int A[], int key ){
    int left, right, mid, cnt = 0;
    left = 0;
    right = n-1;
    
    while( left <= right ){
	mid = (left+right)/2;
	cnt++;
	if ( A[mid] == key ) break;
	else if ( A[mid] > key ) right = mid - 1;
	else left = mid + 1;
    }
    
    return cnt;
}

main(){
    int n, A[MAX], key;
    while(1){
	cin >> n; 
	if ( n == 0 ) break;
	for ( int i = 0; i < n; i++ ) cin >> A[i];
	cin >> key;
	cout << bsearch(n, A, key) << endl;
    }
}
