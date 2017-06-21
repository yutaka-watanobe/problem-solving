#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int x1, y1, x2, y2;
    while(1){
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	if ( x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 ) break;
	if ( x1 == x2 && y1 == y2 ) printf("0\n"); 
	else if ( (x1 == x2 || y1 == y2) ||
		  max(x1, x2)-min(x1,x2) == max(y1, y2)-min(y1, y2) ) printf("1\n");
	else printf("2\n");
    }
    return 0;
}
