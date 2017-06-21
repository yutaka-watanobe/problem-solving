#include<iostream>
using namespace std;

#define MAX 100
int P[MAX][MAX];

void genFilled(int n, int m){
    cout << n << " " << m << endl;
    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < n ; j++ ){
	    if (j) cout << " ";
	    cout << rand()%2;
	}
	cout << endl;
    }

    for ( int i = 0; i < m; i++ ){
	for ( int j = 0; j < m; j++ ){
	    if (j) cout << " ";
	    cout << rand()%2;
	}
	cout << endl;
    }
}
void genFilledWithAHall(int n, int m){
    cout << n << " " << m << endl;
    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < n ; j++ ){
	    if (j) cout << " ";
	    cout << rand()%2;
	}
	cout << endl;
    }

    int hi = rand()%m;
    int hj = rand()%m;
    for ( int i = 0; i < m; i++ ){
	for ( int j = 0; j < m; j++ ){
	    if (j) cout << " ";
	    if ( i == hi && j == hj ){
	      cout << -1;
	    }else{
	      cout << rand()%2;
	    }
	}
	cout << endl;
    }
}
void genSparce(int n, int m){
    cout << n << " " << m << endl;
    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < n ; j++ ){
	    if (j) cout << " ";
	    if ( rand()%11 == 0 ) cout << 1;
	    else cout << 0;
	}
	cout << endl;
    }

    for ( int i = 0; i < m; i++ ){
	for ( int j = 0; j < m; j++ ){
	    if (j) cout << " ";
	    if ( rand()%11 == 0 ) cout << 1;
	    else cout << 0;
	}
	cout << endl;
    }
}
main(){
  /*
    genFilled(10, 1);
    genFilled(10, 2);
    genFilled(10, 2);
    genFilled(10, 3);
    genFilled(10, 3);
    genFilled(10, 3);
    genFilled(10, 3);
    genFilled(10, 4);
    genFilled(10, 4);
    genFilled(10, 4);
    genFilled(10, 5);
    genFilled(10, 5);
    genFilled(10, 5);
    genFilled(10, 6);
    genFilled(10, 6);
    genFilled(20, 2);
    genFilled(20, 2);
    genFilled(20, 3);
    genFilled(20, 3);
    genFilled(20, 4);
    genFilled(20, 4);
    genFilled(30, 1);
    genFilled(30, 2);
    genFilled(30, 3);
    genFilled(50, 4);
    genFilled(50, 4);
    genFilled(100, 2);
    genFilled(100, 2);
    genFilled(100, 3);
    genFilled(100, 3);
    genFilled(100, 4);
    genFilled(100, 4);
    genFilled(100, 4);
    genFilled(100, 5);
    genFilled(100, 5);
    genFilled(100, 6);
    genFilled(100, 6);
  */

  /*
  genFilledWithAHall(10, 2);
  genFilledWithAHall(10, 2);
  genFilledWithAHall(10, 2);
  genFilledWithAHall(10, 3);
  genFilledWithAHall(10, 3);
  genFilledWithAHall(10, 3);
  genFilledWithAHall(10, 3);
  genFilledWithAHall(10, 4);
  genFilledWithAHall(10, 4);
  genFilledWithAHall(10, 4);
  */

  genSparce(50, 3);
  genSparce(50, 3);
  genSparce(50, 3);
  genSparce(50, 3);
  genSparce(100, 4);
  genSparce(100, 5);
  genSparce(100, 6);
  genSparce(100, 7);
  genSparce(100, 20);
  genSparce(100, 20);
  genSparce(100, 30);
  genSparce(100, 50);


    cout << "0 0" << endl;
}
