#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++)

class Cube{
    public:
    char f[6];
    Cube(){}
    void roll_z(){ roll(1, 2, 4, 3);}
    void roll_y(){ roll(0, 2, 5, 3);}
    void roll_x(){ roll(0, 1, 5, 4);}
    void roll(int i, int j, int k, int l){
	char t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }
};

Cube C[8], D[8];
bool U[8];

bool invalid(char c1, char c2){
    return !( max(c1, c2) - min(c1, c2 ) == 32 );
}

bool rec( int p ){
    if ( p == 8 ) return true;
    rep(a, 8){
	if ( U[a] ) continue;
	Cube c = C[a];
	U[a] = true;
	for ( int i = 0; i < 6; i++, (i%2)?c.roll_x():c.roll_y()){
	    for ( int j = 0; j < 4; j++, c.roll_z()){
		D[p] = c;
		if ( p % 2 && invalid(D[p-1].f[2], D[p].f[3])) continue;
		if ( p > 3 && invalid(D[p-4].f[4], D[p].f[1])) continue;
		if ( p%4 > 1 && invalid(D[p-2].f[5], D[p].f[0])) continue;
		if ( rec(p+1) ) return true;
	    }
	}
	U[a] = false;
    }
    return false;
}

main(){
    string str;
    while( cin >> str && str != "0" ) {
	rep(s, 6) C[0].f[s] = str[s];
	for ( int i= 1; i < 8; i++ ) { cin >> str; rep(s, 6) C[i].f[s] = str[s]; };
	rep(i, 8) U[i] = false;
	if ( rec(0) ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}
