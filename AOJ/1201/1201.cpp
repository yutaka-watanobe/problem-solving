#include<iostream>
#include<string>
#include<cassert>
#include<algorithm>
using namespace std;
#define N 10

//string P[N];
char P[N][5];
bool used[N];
char B[5][5], T[5][5];
int cnt;
bool isR[10];

bool fit( int w ){
    for ( int i = 0; i < w; i++ ) if ( B[i][w-1] == T[i][w-1] ) return false;
    for ( int i = 0; i < w-1; i++ ) if ( B[w-1][i] == T[w-1][i] ) return false;
    return true;
}

bool isReversible(char *str){
    return !(str[0] == str[4] && str[1] == str[3]);
}

int next( int pos ){
    if ( pos < 5 ) return pos + 5;
    else if ( pos == 9 ) return N;
    else return pos - 4;
}

int target;
int getW(int pos){
    if ( pos == 10 ) return 5;
    return pos%5;
}

void recursive( int pos ){
    if ( pos >= 5 && !fit( getW(pos)) ) return;
    if ( pos == N ){ cnt++; return ;}

    if ( pos < 5 ){
	if ( pos == target ){
	    for ( int i = 0; i < 5; i++ ) B[i][pos] = P[0][i];
	    recursive( next(pos) );
	    //	    if ( isReversible(P[0] ) ){
	    if ( isR[0] ){
		for ( int i = 0; i < 5; i++ ) B[i][pos] = P[0][4-i];
		recursive( next(pos) );
	    }
	} else {
	    for ( int b = 1; b < N; b++ ){
		if ( used[b] ) continue;
		used[b] = true;
		for ( int i = 0; i < 5; i++ ) B[i][pos] = P[b][i];
		recursive( next(pos));
		//		if ( isReversible(P[b]) ) { 
	    if ( isR[b] ){
		    for ( int i = 0; i < 5; i++ ) B[i][pos] = P[b][4-i];
		    recursive( next(pos) );
		}
		used[b] = false;
	    }
	}
    } else {
	for ( int b = 1; b < N; b++ ){
	    if ( used[b] ) continue;
	    used[b] = true;
	    for ( int i = 0; i < 5; i++ ) T[pos-5][i] = P[b][i];
	    recursive( next(pos) );
	    //	    if ( isReversible(P[b]) ){
	    if ( isR[b] ){
		for ( int i = 0; i < 5; i++ ) T[pos-5][i] = P[b][4-i];
		recursive(next(pos));
	    }
	    used[b] = false;
	}
    }
}

void compute(){
    cnt = 0;
    for ( int i = 0; i < N; i++ ) used[i] = false;
    for ( int i = 0; i < N; i++ ) isR[i] = isReversible(P[i]);

    for ( int i = 0; i < 5; i++ ){
	for ( int j = 0; j < 5; j++ ) B[i][j] = ' ';
    }

    // base 0 is static

    used[0] = true;
    for ( target = 0; target < 5; target++ ){
	recursive(0);
    }




    cout << cnt/4 << endl;

}

int main(){
    while(1){
      //cin >> P[0];
	scanf("%s", P[0]);
	//if ( P[0] == "END" ) break;
	if ( P[0][0] == 'E' ) break;
	//	for ( int i = 1; i < N; i++ ) cin >> P[i];
	for ( int i = 1; i < N; i++ ) scanf("%s", P[i]);
	compute();
    }
    return 0;
}

