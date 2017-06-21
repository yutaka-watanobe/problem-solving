#include<iostream>
#include<cassert>
#include<map>
#include<algorithm>
using namespace std;
#define MAX 100

class Node{
    public:
    int ll, rl, lw, rw;
    Node(int ll = 0, int rl = 0, int lw = 0, int rw = 0): ll(ll), rl(rl), lw(lw), rw(rw){}
};

Node T[MAX+1];
int N, root;

int gcd( int a, int b ){
    if ( b == 0 ) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a/gcd(a, b))*b;
}

bool rec( int u, int v ){
    int x = T[u].ll;
    int y = T[u].rl;
    int a, b;
    int L = x + y;
    int xv = x*v;
    int yv = y*v;
    if ( xv % (L) ) return false;
    if ( yv % (L) ) return false;

    b = xv / (L);
    a = yv / (L);

    if ( T[u].lw && T[u].rw ){
      return rec( T[u].lw, a ) && rec( T[u].rw, b );
    }else if ( T[u].lw && T[u].rw == 0 ){
      return rec( T[u].lw, a );
    } else if ( T[u].lw == 0 && T[u].rw ){
      return rec( T[u].rw, b );
    } else {
      return true;
    }
}

int compute(){
    int GCD = gcd(T[root].ll, T[root].rl);
    int s = T[root].ll/GCD;
    int a = s;
    int b;

    while(1){
	b = a*T[root].rl / T[root].ll;
	int i = a + b;
	if ( rec(root, i) ) return i;
	a += s;
    }
}

int main(){
    while(1){
	cin >> N;
	if ( N == 0 ) break;
	bool hasP[MAX+1] = {};
	for ( int i = 1; i <= N; i++ ){
	    cin >> T[i].ll >> T[i].rl >> T[i].lw >> T[i].rw;
	    if ( T[i].lw ) hasP[T[i].lw] = true;
	    if ( T[i].rw ) hasP[T[i].rw] = true;
	}
	int cnt = 0;
	for ( int i = 1; i <= N; i++ ) if ( !hasP[i] ) { root = i; cnt++; }
	assert( cnt == 1 );
	cout << compute() << endl;
    }

    return 0;
}
