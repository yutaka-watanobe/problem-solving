#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
char G[8][8];
bool p(int i, int j){return (0<=i&&i<8&&0<=j&&j<8)&&(G[i][j] == '1');}
main(){
    while( cin >> G[0][0] ){
	int si = 0, sj = 0;
	rep(i, 8) rep(j, 8) {
	    if (i+j == 0) continue;
	    cin >> G[i][j];
	    if(G[i][j] == '1') { si = i; sj = j;}
	}
	char ch = 'A';
	if ( p(si-3, sj) ) ch = 'B';
	else if ( p(si, sj-3) ) ch = 'C';
	else if ( p(si-2, sj+1)) ch = 'D';
	else if ( p(si-1, sj-2)) ch = 'E';
	else if ( p(si-2, sj-1)) ch = 'F';
	else if ( p(si, sj-1) && p(si-1, sj+1) ) ch = 'G';
	cout << ch << endl;
    }
}
