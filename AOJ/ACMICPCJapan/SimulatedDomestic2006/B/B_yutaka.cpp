// Sort + Swap operations
// @author yutaka C++
#include<stdio.h>
#include<algorithm>
#define SIZE 101
#define LSIZE 1001

using namespace std;

class Line{
    public:
    int h, p, q;
    Line(){}
    Line( int h, int p, int q): h(h), p(p), q(q){}

    bool operator < ( const Line &l ) const{
	return h < l.h;
    }
};

int n, m, a;

void compute(){
    Line lines[LSIZE];
    int buffer[SIZE];
    for ( int i = 1; i <= n; i++ ) buffer[i] = i;

    int h, p, q;
    for ( int i = 0; i < m; i++ ){
	scanf("%d %d %d", &h, &p, &q);
	lines[i] = Line( h, p, q );
    }

    sort ( lines, lines + m );

    for ( int i = 0; i < m; i++ ){
	p = lines[i].p; q = lines[i].q;
	swap ( buffer[p], buffer[q] );
    }

    printf("%d\n", buffer[a] );
}

bool input(){
    scanf("%d %d %d", &n, &m, &a);
    if ( n == 0 ) return false;
    return true;
}

main(){
    while ( input() ) compute();
}
