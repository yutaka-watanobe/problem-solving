#include<iostream>
#include<algorithm>
using namespace std;

#define N 8
#define INF 1000.0

int ID[N*3];
double T[N*3];

void search( int s, int t ){
    int mini;
    double mint = INF;
    for ( int i = s; i <= t; i++ ){
	if ( mint > T[i] ){
	    mint = T[i]; mini = i;
	}
    }
    cout << ID[mini] << " " << T[mini] << endl;
    T[mini] = INF;
}

main(){
    for ( int i = 0; i < N*3; i++ ) cin >> ID[i] >> T[i];
    search(0, 7); 
    search(0, 7);
    search(8, 15); 
    search(8, 15);
    search(16, 23); 
    search(16, 23);
    search(0, 23); 
    search(0, 23);
}
