#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 30

int N, K, E[MAX], cnt;

void recursive( int i, int k, int sum, int maxe ){
    if ( k > K ) return;

    if ( i == N ){
	if ( k == K ){
	    if ( sum - maxe > maxe ) cnt++;
	}
	return;
    }

    recursive( i+1, k, sum, maxe );
    recursive( i+1, k+1, sum+E[i], max( maxe, E[i]) );
}

int compute(){
    scanf("%d %d", &N, &K);
    for ( int i = 0; i < N; i++ ) scanf("%d", &E[i]);
    cnt = 0;
    recursive(0, 0, 0, 0);
    return cnt;
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	printf("Case %d: %d\n", i, compute());
    }
}
