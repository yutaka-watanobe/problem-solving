#include<iostream>

using namespace std;

// begin_of_source
void swap( int &x, int &y ){
    int tmp = x;
    x = y;
    y = tmp;
}

void bubbleSort( int size, int A[]){
    for ( int i = 1; i < size; i++ ){
	for ( int j = 0; j < size - i; j++ ){
	    if ( A[j] > A[j+1] ){
		swap( A[j], A[j+1]);
	    }
	}
    }
}
// end_of_source

main(){
    int A[100];
    int size;
    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> A[i];
    bubbleSort( size, A);
    for ( int i = 0; i < size; i++ ) cout <<  A[i] << " ";
    cout << endl;

}
