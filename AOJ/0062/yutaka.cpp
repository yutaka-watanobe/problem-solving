#include<iostream>
using namespace std;
#define MAX 100000

main(){
    double T[MAX][100];



    for ( int i = 0; i < MAX; i++ ){
	for ( int j = 0; j < 100; j++ ) T[i][j] = 0.0;
    }

    T[1][1] = 1.0;

    for ( int i = 1; i <= 10; i++ ){
	for ( int j = 1; j <= i; j++ ){
	    T[i+1][j] += T[i][j];
	}
    }

}
