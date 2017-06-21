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
    /*
    if ( depth == 0 ){
	len++;
    } else {
	if ( path[depth-1] == path[depth] ) len++;
	else {
	    if ( len == plen ) return;
	    plen = len;
	    len = 1;
	}
    }

    if ( len > 3 ) return;
    ********/

    if ( depth == size ){
	cnt++;
	for ( int i = 0; i < size; i++ ) cout << path[i];
	cout << endl;
	return;
    }


    int nlen, nplen;
    for ( int i = 0; i < size; i++ ){
	if ( used[i] ) continue;
	used[i] = true;
	path[depth] = M[i];

	if ( pre != path[depth] ) {
	    if ( plen == len ) continue;
	    nplen = len;
	    nlen =1;
	} else {
	    nlen = len + 1;
	}

	if ( nlen >3 ) continue;

	recursive(depth + 1, path[depth], nlen, nplen);
	used[i] = false;
    }


}

void compute(){
    cout << "size = " << size << endl;
    for ( int i = 0; i < size; i++ ) used[i] = false;
    cnt = 0;

    recursive(0, -1,0, -1);


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
