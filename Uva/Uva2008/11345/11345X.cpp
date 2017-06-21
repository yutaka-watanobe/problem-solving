#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cassert>
using namespace std;

bool overlap( int &p1, int &p2, int t1, int t2 ){
    assert( p1 <= p2 );
    assert( t1 <= t2 );
    int r1, r2;
    
    if ( p2 <= t1 && p2 <= t2 ) return false;
    if ( t1 <= p1 && t2 <= p1 ) return false;

    r1 = max( p1, t1 );
    r2 = min( p2, t2 );

    p1 = min(r1, r2);
    p2 = max(r1, r2);
    return ( p1 < p2 );
}

void generalize( int &x1, int &y1, int &x2, int &y2 ){
    int a1, a2, b1, b2;
    if ( x1 < x2 ) {a1 = x1; a2 = x2;}
    else {a1 = x2, a2 = x1;}
    if ( y1 < y2 ) {b1 = y1; b2 = y2;}
    else {b1 = y2, b2 = y1;}

    x1 = a1;
    x2 = a2;
    y1 = b1;
    y2 = b2;
}

int compute(){
    int m; scanf("%d", &m);
    if ( m == 0 ) return 0;

    int i1, i2, j1, j2;
    int x1, x2, y1, y2, tx1, tx2, ty1, ty2;
    //    cin >> x1 >> y1 >> x2 >> y2;
    //    cin >> i1 >> j1 >> i2 >> j2;
    scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
    if ( i1 < i2 ) {x1 = i1; x2 = i2;}
    else {x1 = i2, x2 = i1;}
    if ( j1 < j2 ) {y1 = j1; y2 = j2;}
    else {y1 = j2, y2 = j1;}
    
    bool non = false;
    for ( int i = 1; i < m; i++ ){
	//	cin >> i1 >> j1 >> i2 >> j2;
      scanf("%d %d %d %d", &i1, &j1, &i2, &j2);

	if ( i1 < i2 ) {tx1 = i1; tx2 = i2;}
	else {tx1 = i2, tx2 = i1;}
	if ( j1 < j2 ) {ty1 = j1; ty2 = j2;}
	else {ty1 = j2, ty2 = j1;}
	
	if ( !overlap( x1, x2, tx1, tx2 ) ) non = true;
	if ( !overlap( y1, y2, ty1, ty2 ) ) non = true;
    }

    if ( non ) return 0;

    return (x2-x1)*(y2-y1);

}

main(){
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	cout << "Case " << i << ": " << compute() << endl;
    }
}

