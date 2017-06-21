#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Piece{
    public:
    int d, w, area;
    Piece(){}
    Piece( int d, int w ): d(d), w(w){ area = d*w; }
    
    bool operator < ( const Piece &p ) const{
	return area < p.area;
    }
};

int n;
vector<Piece> P;

void cut( int p, int s ){
    Piece target = P[p]; P.erase( P.begin() + p );
    Piece new1, new2;
    int d = target.d;
    int w = target.w;
    int c1 = w;
    int c2 = w + d;
    int c3 = 2*w + d;
    int c4 = 2*w + 2*d;
    s = s % c4;
    if ( 0 < s && s < c1 ){
	new1 = Piece( d, s ); new2 = Piece( d, c1 - s );
    } else if ( c2 < s && s < c3 ){
	new1 = Piece( d, c3 - s ); new2 = Piece( d, s - c2 );
    } else if ( c1 < s && s < c2 ){
	new1 = Piece( s - c1, w ); new2 = Piece( c2 - s, w );
    } else if ( c3 < s && s < c4 ){
	new1 = Piece( s - c3, w ); new2 = Piece( c4 - s, w );
    } 

    if ( new1 < new2 ){ P.push_back( new1 ); P.push_back( new2 ); }
    else { P.push_back( new2 ); P.push_back( new1 ); }
}

void simulate(){
    int p, s;
    for ( int i = 0; i < n; i++ ){
	cin >> p >> s;
	cut( p - 1, s );
    }
    sort( P.begin(), P.end() );
    for ( int i = 0; i < P.size(); i++ ){
	if ( i ) cout << " ";
	cout << P[i].area;
    }
    cout << endl;
}

bool input(){
    int w, d;
    cin >> n >> w >> d;
    if ( n == 0 && w == 0 && d == 0 ) return false;
    P.clear();
    P.push_back(Piece(d, w));
    return true;
}

main(){
    while ( input() ) simulate();
}
