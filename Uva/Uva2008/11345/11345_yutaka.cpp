#include<stdio.h>
#include<algorithm>
using namespace std;
#define MIN -10000
#define MAX 10000

int compute(){
    int x1, x2, y1, y2, tx1, tx2, ty1, ty2, m;
    x1 = MIN;
    x2 = MAX;
    y1 = MIN;
    y2 = MAX;
    scanf("%d", &m);
    for ( int i = 0; i < m; i++ ){
	scanf("%d %d %d %d", &tx1, &ty1, &tx2, &ty2);
	x1 = max(x1, tx1);
	x2 = min(x2, tx2);
	y1 = max(y1, ty1);
	y2 = min(y2, ty2);
    }

    return (( x1 >= x2 || y1 >= y2 ) ? 0 : (x2-x1)*(y2-y1));
}

main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	printf("Case %d: %d\n", i, compute());
    }
}

