#include<iostream>
#include<string>
#define rep(i, n) for ( int i = 0; i < n; i++ )
using namespace std;
#define MAX 100
class Cube{
    public:
    string f[6];
    Cube(){}
    void roll_z(){ roll(1, 2, 4, 3);}
    void roll_y(){ roll(0, 2, 5, 3);}
    void roll_x(){ roll(0, 1, 5, 4);}
    void roll(int i, int j, int k, int l){
	string t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }
};

Cube C[MAX];
int n;

bool eq( Cube c1, Cube c2 ){
    rep(i, 6) if ( c1.f[i] != c2.f[i] ) return false;
    return true;
}

bool equal( Cube c1, Cube c2 ){
    rep(i, 6){
	rep(j, 4){
	    if ( eq(c1, c2) ) return true;
	    c1.roll_z();
	}
	if ( i % 2 == 0 ) c1.roll_y();
	else c1.roll_x();
    }
    return false;
}

main(){
    while( cin >> n && n ){
	rep(i, n) rep(j, 6) cin >> C[i].f[j];
	int cnt = 0;
	rep(i,n) {
	    bool hasSame = false;
	    for(int j=i+1; j<=n-1;j++) if (equal(C[i],C[j])) {hasSame = true;break;}
	    if ( !hasSame ) cnt++;
	}
	cout << n - cnt << endl;
    }
}
