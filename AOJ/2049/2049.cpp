#include<cstdio>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 1000000
void simulate( int x, int y ){
    int R[MAX+1];
    rep(i, MAX+1) R[i] = -1;

    int q = x;
    int r;
    int i = 1;
    
    R[x] = 0;

    while(1){
	r = q % y;
	if ( r == 0 || R[r] > 0 ) {
	    if ( R[r] == -1 ) printf("%d %d\n", i-1, 0);
	    else printf("%d %d\n", R[r]-1, i-R[r]);
	    break;
	}
	R[r] = i;
	q = r*10;
	i++;
    }
}

main(){
    int x, y;
    while(1){
	scanf("%d %d", &x, &y);
	if ( x == 0 && y == 0 ) break;
	simulate(x, y);
    }
}
