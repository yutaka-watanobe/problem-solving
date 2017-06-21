#include<stdio.h>
#include<set>
using namespace std;
#define MAX 50

int N;
set<int> stamps[MAX], all;

void input(){
    scanf("%d", &N);
    all = set<int>();
    for ( int i = 0; i < N; i++ ){
	int m, k; scanf("%d", &m);
	stamps[i] = set<int>();
	for ( int j = 0; j < m; j++ ) {
	    scanf("%d", &k);
	    stamps[i].insert(k);
	    all.insert(k);
	}
    }
}

void compute(){
    int counter[MAX];
    int total = 0;
    fill( counter, counter + N, 0 );
    
    set<int>::iterator it;
    for ( it = all.begin(); it != all.end(); it++ ){
	int cnt = 0;
	int target;
	for ( int i = 0; i < N; i++ ){
	    if ( stamps[i].count(*it) ) { cnt++; target = i; }
	}
	if ( cnt == 1 ) { counter[target]++; total++; }
    }

    for ( int i = 0; i < N; i++ ){
	printf(" %.6lf%%", 100.0*counter[i]/total);
    }
    printf("\n");
}

main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 1; i <= tcase; i++ ){
	printf("Case %d:", i);
	input();
	compute();
    }
}
