#include<cstdio>
#define MAX 100000
#define INF (1<<21)

int id[MAX], total[MAX];
int n;

int searchMin(){
    int minv = INF;
    int target;
    for ( int i = 0; i < n; i++ ){
	if ( total[i] < 0 ) continue;
	if ( total[i] < minv ){
	    minv = total[i];
	    target = i;
	}
    }
    total[target] = -1;
    return id[target];
}

int searchMax(){
    int maxv = 0;
    int target;
    for ( int i = 0; i < n; i++ ){
	if ( total[i] < 0 ) continue;
	if ( total[i] > maxv ){
	    maxv = total[i];
	    target = i;
	}
    }
    total[target] = -1;
    return id[target];
}

main(){
    int m, s;
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	for ( int i = 0; i < n; i++ ){
	    scanf("%d", &id[i]);
	    total[i] = 0;
	    for ( int j = 0; j < 4; j++ ){
		scanf("%d %d", &m, &s);
		total[i] += m*60+s;
	    }
	}

	printf("%d\n", searchMin());
	printf("%d\n", searchMin());
	searchMax();
	printf("%d\n", searchMax());
    }
}
