// eratos
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 1000000
#define LIMIT 114

void eratos ( int n, bool prime[]){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    // 奇数を素数の候補とする
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    // 合成数でない奇数だけを残す
    for ( int i = 3; i <= limit; i += 2 ){
        if ( !prime[i] ) continue;
        for ( int j = i * i, k = i * 2; j <= n; j += k )
        prime[j] = false;
    }
}

bool prime[MAX+1];

int compute(int lower, int upper){
    int counter[LIMIT+1];
    for ( int i = 0; i <= LIMIT; i++ ) counter[i] = 0;

    bool isFast = true;
    int pre;
    for ( int p = lower; p <= upper; p++ ){
	if ( !prime[p] ) continue;
	if ( !isFast ){
	    counter[p - pre]++;
	}
	isFast = false;
	pre = p;
    }

    int maxv = 0;
    int maxp;
    for ( int i = 0; i <= LIMIT; i++ ){
	if ( maxv < counter[i] ){
	    maxp = i;
	    maxv = counter[i];
	}
    }

    int mcount = 0;
    for ( int i = 0; i <= LIMIT; i++ ){
	if ( counter[i] == maxv ) mcount++;
    }

    if ( mcount > 1 ) return -1;
    return maxp;
}

main(){
    eratos( MAX, prime );

    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	int l, u; scanf("%d %d", &l, &u);
	int champ = compute(l, u);
	if ( champ < 0 ) printf("No jumping champion\n");
	else printf("The jumping champion is %d\n", champ);
    }
}
