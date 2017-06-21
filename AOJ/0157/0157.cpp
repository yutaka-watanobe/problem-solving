#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 200

class Doll{
    public:
    int h, r;
    Doll(){}
    Doll( int h, int r ): h(h), r(r){}

    bool operator < ( const Doll &d ) const {
      if ( r == d.r ) return h < d.h;
      	else return r < d.r;
    }
};

Doll dolls[MAX+1];
int size;

int lis(){
    int T[MAX+1];
    T[0] = 0;
    dolls[0] = Doll( 0, 0 );
    for ( int i = 1; i <= size; i++ ){
	int maxi = 0;
	for ( int j = 0; j <= i - 1; j++ ){
	    if ( T[j] > T[maxi] && 
		 dolls[j].h < dolls[i].h && dolls[j].r < dolls[i].r ){
		maxi = j;
	    }
	}
	T[i] = T[maxi] + 1;
    }

    int maxv = 0;
    for ( int i = 1; i <= size; i++ ) maxv = max( maxv, T[i] );

    return maxv;
}

bool input(){
    int n, m, h, r;
    cin >> n;
    if ( n == 0 ) return false;

    dolls[0] = Doll(0, 0);

    for ( int i = 1; i <= n; i++ ){
	cin >> h >> r;
	dolls[i] = Doll( h, r );
    }
    cin >> m; size = n + m;
    for ( int i = n + 1; i <= size; i++ ){
	cin >> h >> r;
	dolls[i] = Doll( h, r );
    }
    return true;
}

int main(){
    while(input()){
	sort( dolls, dolls + size + 1);
	cout << lis() << endl;
    }
    return 0;
}
