#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 28

int M[MAX]; // marbles color
int size;

bool used[MAX];
int cnt;

void recursive( int pos, int prel, int prec, int pre, int cur, int len ){
    cout << pos << endl;
    if ( pre != cur  ){ // cut
	if ( len == prel ) return;
	if ( pre == prec ) return;
	prel = len;
	prec = cur;
	len = 1;


    } else {
	len++;
    }

    if ( len > 3 ) return;

    if ( pos == size ){
	cnt++;
	return;
    }

    for ( int i = 0; i < size; i++ ){
	if ( used[i] ) continue;
	used[i] = true;
	recursive(pos+1, prel, prec, pre, M[i], len);
	used[i] = false;


    }


}

void compute(){
    cout << "size = " << size << endl;
    for ( int i = 0; i < size; i++ ) used[i] = false;
    cnt = 0;
    recursive(0, 0, -1, -1, -2, 0);
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
