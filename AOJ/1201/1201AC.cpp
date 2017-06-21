#include<iostream>
#include<string>
#include<cassert>
#include<algorithm>
using namespace std;
#define N 10

string P[N];
bool used[N];
char B[5][5];
char T[5][5];
int cnt;

bool fit( int row, string &str ){
    for ( int j = 0; j < 5; j++ ){
	T[row][j] = str[j];
	if ( B[row][j] == str[j] ) return false;
    }
    
    return true;
}

bool isReversible(string str){
    return !(str[0] == str[4] && str[1] == str[3]);
}

void recursive( int pos ){
    if ( pos == N ){ cnt++; return ;}
    if ( pos < 5 ){
	for ( int b = 0; b < N; b++ ){
	    if ( used[b] ) continue;
	    used[b] = true;
	    for ( int i = 0; i < 5; i++ ) B[i][pos] = P[b][i];
	    recursive(pos+1);
	    if ( isReversible(P[b]) ) { 
		for ( int i = 0; i < 5; i++ ) B[i][pos] = P[b][5-i-1];
		recursive(pos+1);
	    }
	    used[b] = false;
	}
    } else {
	for ( int b = 0; b < N; b++ ){
	    if ( used[b] ) continue;
	    used[b] = true;
	    string pattern = P[b];
	    if ( fit( pos - 5, pattern ) ) recursive( pos+1 );
	    if ( isReversible(pattern) ) { 
		reverse(pattern.begin(), pattern.end());
		if ( fit( pos - 5, pattern ) ) recursive( pos+1 );
	    }
	    used[b] = false;
	}
    }
}

void compute(){
    cnt = 0;
    for ( int i = 0; i < N; i++ ) used[i] = false;

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
}

int main(){
    while(1){
	cin >> P[0];
	if ( P[0] == "END" ) break;
	for ( int i = 1; i < N; i++ ) cin >> P[i];
	compute();
    }
    return 0;
}
