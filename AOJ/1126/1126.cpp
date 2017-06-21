#include<string>
#include<iostream>

#define MAX 72

using namespace std;

int row, column;
char M[MAX][MAX];
string T[MAX][MAX], secret;

string max( string s1, string s2 ){
    if ( s1.size() == s2.size() ) return ( s1 > s2 ) ? s1 : s2;
    else  return ( s1.size() > s2.size() ) ? s1 : s2;
}

void compute(){
    secret = "";
    for ( int i = 1; i <= row; i++ ){
        for ( int j = 1; j <= column; j++ ){
            if ( isalpha( M[i][j] ) ) continue;
            T[i][j] = max( T[i-1][j], T[i][j-1] ) + M[i][j];
            if ( T[i][j][0] == '0' ) T[i][j] = T[i][j].substr(1, T[i][j].size()-1);
            secret = max( secret, T[i][j] );
        }
    }
    
    cout << secret << endl;
}

int main(){
    while(1){
	cin >> column >> row;
	if ( column == 0 && row == 0 ) break;
    
	for ( int j = 0; j <= column; j++ ) { M[0][j] = 'A'; T[0][j] = "";}
	for ( int i = 0; i <= row; i++ ) { M[i][0] = 'A'; T[i][0] = "";}
	for ( int i = 1; i <= row; i++ ){
	    for ( int j = 1; j <= column; j++ ){
		cin >> M[i][j];
		T[i][j] = "";
	    }
	}
	compute();
    }
}
