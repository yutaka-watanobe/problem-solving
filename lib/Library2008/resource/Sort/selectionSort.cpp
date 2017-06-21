#include<iostream>

using namespace std;

// begin_of_source
void swap( int &x, int &y ){
    int tmp = x;
    x = y;
    y = tmp;
}

void selectionSort( int size, int A[]){
    for ( int i = 0; i < size - 1; i++ ){
	int target = i;
	for ( int j = i + 1; j < size; j++ ){
	    if ( A[j] < A[target] ) target = j;
	}
	swap( A[i], A[target] );
    }
}
// end_of_source

main(){
    int A[100];
    int size;
    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> A[i];
    selectionSort( size, A);
    for ( int i = 0; i < size; i++ ) cout <<  A[i] << " ";
    cout << endl;

}
