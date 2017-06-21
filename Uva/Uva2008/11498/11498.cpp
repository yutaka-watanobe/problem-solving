#include<stdio.h>
#define REP(i, n) for ( int i = 0; i < n; i++ )

int main(){
    int K, x, y, dx, dy;
    while(1){
	scanf("%d", &K);
	if ( K == 0 ) break;
	scanf("%d %d", &dx, &dy);
	REP(i, K) {
	    scanf("%d %d", &x, &y);
	    if ( x == dx || y == dy ) printf("divisa\n");
	    else if ( x < dx && y > dy ) printf("NO\n");
	    else if ( x > dx && y > dy ) printf("NE\n");
	    else if ( x > dx && y < dy ) printf("SE\n");
	    else if ( x < dx && y < dy ) printf("SO\n");
	}
    }
    return 0;
}
