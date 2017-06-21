#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 4

int M[MAX];
int ncolor, nmarble;
int firstColor, firstSize;
int cnt;

void recursive(int preColor, int preSize, int sum, bool isFirst ){
    if ( sum == nmarble ){
	if ( preColor == firstColor || preSize == firstSize ) return;
	cnt++;
	return;
    }

    for ( int i = 0; i < ncolor; i++ ){
	for ( int n = 1; n <= min(M[i], 3); n++ ){
	    if ( preColor == i || preSize == n ) continue;
	    M[i] -= n;
	    if ( isFirst ){
		firstColor = i;
		firstSize = n;
	    }
	    recursive( i, n, sum + n, false );
	    M[i] += n;
	}
    }
}

void compute(){
    cnt = 0;

    recursive(-1, -1, 0, true);

    printf("%d\n", cnt);
}

void input(){
    nmarble = 0;
    scanf("%d", &ncolor);
    for ( int i = 0; i < ncolor; i++ ){
	scanf("%d", &M[i]);
	nmarble += M[i];
    }
}

int main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
    return 0;
}
