#include<stdio.h>
#define MAX 10
#define rep(i, n) for ( int i = 0; i < n; i++)
main(){
    int P[MAX+4][MAX+4];
    int dx[13] = {0, 1, 0, -1, 0, 1, -1, -1, 1, 2, 0, -2, 0};
    int dy[13] = {0, 0, -1, 0, 1, -1, -1, 1, 1, 0, -2, 0, 2};
    int x, y, size, empty = 0, maxv = 0;
    rep(y,MAX+4) rep(x,MAX+4) P[y][x] = 0;
    while ( scanf("%d,%d,%d", &x, &y, &size) != EOF ) {
	x += 2; y += 2;
	rep(r,size*4+1) P[y + dy[r]][x + dx[r]]++;
    }
    for ( int y = 2; y <= 11; y++ ){
        for ( int x = 2; x <= 11; x++ ){
            if ( P[y][x] == 0 ) empty++;
            if ( P[y][x] > maxv ) maxv = P[y][x];
        }
    }
    printf("%d\n%d\n", empty, maxv);
}
