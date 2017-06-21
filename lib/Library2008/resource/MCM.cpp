#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

void output( int, int, int, int);

// begin_of_source
#define MAX 100
#define INFTY (1 << 21)

int SIZE;
int R[MAX + 2]; 
int C[MAX+1][MAX+1]; // cost table
int B[MAX+1][MAX+1]; // best table

void compute(){
    for ( int i = 1; i <= SIZE; i++ )
	for ( int j = 1; j <= SIZE; j++ ) C[i][j] = INFTY;

    for ( int i = 1; i <= SIZE; i++ ) C[i][i] = 0;

    for ( int j = 1; j <= SIZE - 1; j++ ){
	for ( int i = 1; i <= SIZE - j; i++ ){
	    for ( int k = i + 1; k <= i + j; k++ ){
		// C[i][i+j] = min( C[i][i+j], 
                //                  C[i][k-1] + C[k][i+j] + R[i]*R[k]*R[i+j+1]);
		int cost = C[i][k-1] + C[k][i+j] + R[i]*R[k]*R[i+j+1];
		if ( cost < C[i][i+j] ){
		    C[i][i+j] =  cost;
		    B[i][i+j] = k;
		}

	    }
	}
    }
}

void order( int i, int j ){
    if ( i == j ) cout << "M" << i;
    else{
	cout << "(";
	order( i, B[i][j]-1 ); order(B[i][j], j);
	cout << ")";
    }
}

void input(){
    cin >> SIZE;
    for ( int i = 1; i <= SIZE + 1; i++ ) cin >> R[i];
}

void output(){
    cout << "minimum cost = " << C[1][SIZE] << endl;
    order(1, SIZE);
    cout << endl;
}

main(){
    input();
    compute();
    output();
}
// end_of_source



void output( int ii, int ij, int k1, int kk ){
    for ( int a = 1; a <= SIZE+1; a++ ) printf("%4d", a);
     cout << endl;
     for ( int a = 1; a <= SIZE+1; a++ ){
	 if ( a == ii || a == kk || a == ij + 1 ) printf("[%2d]", R[a]);
	 else  printf("%4d", R[a]);
     }
     cout << endl;
     cout << endl;
     for ( int i = 1; i <= SIZE; i++ ){
       cout << "    ";
	 for ( int j = 1; j <= SIZE; j++ ){
	     if ( i > j ) {
		 cout << "    "; continue;
	     }

	     int value = C[i][j];
	     if ( value == INFTY ) value = 99;

	     if ( i == ii && j == ij ) printf("[%2d]", value );
	     else if ( i == ii && j == k1 || i == kk && j == ij ) printf("(%2d)", value );
	     else  printf(" %2d ", value);
	}
	cout << endl;
    }
    cout << endl;
    cout << endl;
}



