#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 28

int M[MAX]; // marbles color
int size;

bool used[MAX];
int path[MAX];
int cnt;

void recursive( int depth, int pre, int len, int plen ){
    if ( depth == size ){
	int c = path[0];
	int l = 1;
	while( path[l] == c ) l++;

	if ( l == len ) return;
	if ( path[0] == path[depth-1] ) return;

	cnt++;
	//		for ( int i = 0; i < size; i++ ) cout << path[i];
	//		cout << endl;
	return;
    }

    int nlen, nplen, cur;
    for ( int i = 0; i < size; i++ ){
	if ( used[i] ) continue;
	used[i] = true;
	cur = M[i];
	path[depth] = cur;

	if ( pre == cur ){
	    nlen = len + 1;
	} else {
	    if ( plen == len ) goto next;
	    nplen = len;
	    nlen =1;
	}

	if ( nlen >3 ) goto next;

	recursive(depth + 1, cur, nlen, nplen);

    next:;
	used[i] = false;
    }


}

void compute(){
    cout << "size = " << size << endl;
    for ( int i = 0; i < size; i++ ) used[i] = false;
    cnt = 0;

    for ( int i = 0; i < size; i++ ){
	used[i] = true;
	path[0] = M[i];
	recursive(1, M[i], 1, -1);
	used[i] = false;
    }

    printf("%d\n", cnt);
}

void input(){
    size = 0;
    int ncolor, k;
    scanf("%d", &ncolor);
    for ( int i = 0; i < ncolor; i++ ){
	scanf("%d", &k);
	for ( int j = 0; j < k; j++ ) M[size++] = i;
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
