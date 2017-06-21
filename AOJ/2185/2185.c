#include<stdio.h>

int compute(){
    int i, x, y, w, h, n, px, py, sum = 0;
    scanf("%d %d %d %d %d", &x, &y, &w, &h, &n);

    for ( i = 0; i < n; i++ ){
	scanf("%d %d", &px, &py);
	if ( x <= px && px <= x + w &&
	     y <= py && py <= y + h ) sum++;
    }

    return sum;
}

int main(){
    int i, tcase; scanf("%d", &tcase);
    for ( i = 0; i < tcase; i++ ) printf("%d\n", compute());
    return 0;
}
