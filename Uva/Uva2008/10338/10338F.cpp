#include<stdio.h>

typedef unsigned long long llong;

llong F[21];

void init(){
    F[0] = 1;
    for ( int i = 1; i <= 20; i++ ) F[i] = F[i-1]*i;
}

llong compute(){
    int C[26];
    for ( int i = 0; i < 26; i++ ) C[i] = 0;
    char ch;
    int size = 0;
    while(1){
	ch = getchar();
	if ( ch == '\n' ) break;
	C[ch-'A']++;
	size++;
    }
    llong ans = F[size];
    for ( int i = 0; i < 26; i++ ){
	if ( C[i] > 1 ){
	    ans /= F[C[i]];
	}
    }
    return ans;
}

int main(){
    char ch;
    int tcase; scanf("%d", &tcase);
    ch = getchar();
    init();

    for ( int i = 1; i <= tcase; i++ ){
	printf("Data set %d: %lld\n", i, compute());
    }
    return 0;
}
