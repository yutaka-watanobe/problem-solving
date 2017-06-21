#include<iostream>
#include<string>
#include<cassert>
#include<algorithm>
using namespace std;
#define N 10

//string P[N];
char P[N][5];
bool used[N];
char B[5][5];
char T[5][5];
int cnt;
bool RV[N];
int R[5];
bool isR[5];


//bool fit( int row, string &str ){
bool fit( int row, char str[5] ){


        for ( int j = 0; j < 5; j++ ){
    	if ( B[row][j] == str[j] ) return false;
        }
	return true;
    /*
	for ( int i = 0; i < 5; i++ ){
	    for ( int j = 0; j < 5; j++ ){
		cout << B[i][j];
	    }
	    cout << endl;
	}
	cout << "-" << endl;
	for ( int i = 0; i < 5; i++ ){
	    for ( int j = 0; j < 5; j++ ){
		int p = R[j];
		if ( !isR[j] ){
		    assert( B[i][j] == P[p][i] );
		    cout << P[p][i] ;
		} else {
		    assert( B[i][j] == P[p][4-i] );
		    cout << P[p][4-i];
		}
	    }
	    cout << endl;
	}
	cout << "-------------" << endl;

	return true;
    */

    int p;
    for ( int j = 0; j < 5; j++ ){
	p = R[j];
	if ( isR[j] ){
	    if ( P[p][4-row] == str[j] ) return false;
	} else {
	    if ( P[p][row] == str[j] ) return false;
	}
    }
    return true;
}

bool fitR( int row, char str[5] ){

    for ( int j = 0; j < 5; j++ ){
	if ( B[row][j] == str[4-j] ) return false;
    }
    return true;
    /*
    for ( int j = 0; j < 5; j++ ){
	if ( R[j] < 5 )
	    if ( P[R[j]][row] == str[4-j] ) return false;
	else
	    if ( P[R[j]-5][4-row] == str[4-j] ) return false;
    }
    return true;
    */
 int p;
    for ( int j = 0; j < 5; j++ ){
	p = R[j];
	if ( isR[j] ){
	    if ( P[p][4-row] == str[4-j] ) return false;
	} else {
	    if ( P[p][row] == str[4-j] ) return false;
	}
    }
    return true;
}

//bool isReversible(string str){
inline bool isReversible(char *str){
    return (str[0] != str[4] || str[1] != str[3]);
}

int target;

void recursive( int pos ){
    if ( pos == N ){ cnt++; return ;}
    if ( pos < 5 ){
	if ( pos == target ){
	    recursive( pos+1 );
	} else {
	    for ( int b = 1; b < N; b++ ){
		if ( used[b] ) continue;
		used[b] = true;
				for ( int i = 0; i < 5; i++ ) B[i][pos] = P[b][i];
		R[pos] = b;
		isR[pos] = false;
		recursive( pos+1);
		if ( RV[b] ){
		       for ( int i = 0; i < 5; i++ ) B[i][pos] = P[b][4-i];
		       ///		     R[pos] = b;
		       //		     isR[pos] = true;
		    recursive( pos+1 );
		}
		used[b] = false;
	    }
	}
    } else {
	for ( int b = 1; b < N; b++ ){
	    if ( used[b] ) continue;
	    used[b] = true;
	    //	    char *pattern = P[b];
	    if ( fit( pos - 5, P[b] ) ) recursive( pos+1 );
	    if ( RV[b] ){
		if ( fitR( pos - 5, P[b] ) ) recursive( pos+1 );
	    }
	    used[b] = false;
	}
    }
}

void compute(){
    cnt = 0;
    for ( int i = 0; i < N; i++ ) used[i] = false;
    for ( int i = 0; i < N; i++ ) RV[i] = isReversible( P[i] );

    for ( int i = 0; i < 5; i++ ){
	for ( int j = 0; j < 5; j++ ) B[i][j] = ' ';
    }

    // base 0 is static
    used[0] = true;
    for ( target = 0; target < 5; target++ ){
		for ( int i = 0; i < 5; i++ ) B[i][target] = P[0][i];
		//R[target] = 0;
		//isR[target] = false;
	recursive(0);
	if ( RV[0] ){
	    	    for ( int i = 0; i < 5; i++ ) B[i][target] = P[0][4-i];
		    //	    R[target] = 0;
		    //	    isR[target] = true;
	    recursive(0);
	}
    }





    cout << cnt/4 << endl;
    /*
    for ( int base = 0; base < N; base++ ){
	used[base] = true;
	for ( int i = 0; i < 5; i++ ) B[i][0] = P[base][i];
	recursive(1);
	if ( isReversible(P[base]) ) {
	    for ( int i = 0; i < 5; i++ ) B[i][0] = P[base][5-i-1];
	    recursive(1);
	}
	used[base] = false;
    }
    cout << cnt/8 << endl;
    */
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

