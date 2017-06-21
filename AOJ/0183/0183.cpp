#include<iostream>
using namespace std;
#define REP(i, e) for ( int i = 0; i < e; i++ )

char judge( char B[3][3]){
    REP(i, 3){
	if ( B[i][0] == B[i][1] && B[i][1] == B[i][2] && B[i][0] != '+' ) return B[i][0];
	if ( B[0][i] == B[1][i] && B[1][i] == B[2][i] && B[0][i] != '+' ) return B[0][i];
    }
    if ( B[0][0] == B[1][1] && B[1][1] == B[2][2] && B[0][0] != '+' ) return B[0][0];
    if ( B[0][2] == B[1][1] && B[1][1] == B[2][0] && B[0][2] != '+' ) return B[0][2];
    return '*';
}

int main(){
    char B[3][3];
    while(1){
	cin >> B[0][0];
	if ( B[0][0] == '0' ) break;
	REP(i, 3) REP(j, 3) if ( !(i == 0 && j == 0 )) cin >> B[i][j];
	char result = judge(B);
	if ( result == '*' ) cout << "NA" << endl;
	else cout << result << endl;
    }
}
