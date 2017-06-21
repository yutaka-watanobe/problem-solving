#include<iostream>
using namespace std;

#define MAX 30001
#define LEFT 0
#define RIGHT 1

int size, T[MAX], D[MAX];

void input(){
    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> T[i];
}

int next(int i, int direction ){
    for ( int t = i; t < size-1; t++ ){
	if ( D[t] == direction ) return t;
    }
    return size;
}

void compute(){
    int k = 0;
    for ( int i = 1; i < size; i++ ){
	if ( T[i-1] < T[i] ) D[k++] = RIGHT;
	else if ( T[i-1] > T[i] ) D[k++] = LEFT;
    }

    int count = 0;
    int i = 0;

    i = next( i, LEFT );
    if ( i == size ) {
	cout << 1 << endl; return;
    }
    count = 2;
    
    while(1){
	i = next(i, RIGHT);
	if ( i == size ) break;
	count++;
	i = next(i, LEFT);
	if ( i == size ) break;
	count++;
    }

    cout << count << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i= 0; i < tcase; i++ ) {
	input();
	compute();
    }
}
