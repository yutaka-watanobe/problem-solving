// uva 10074
// Take the Land
// 
//
//

#include<stdio.h>
#include<iostream>
#include<stack>
#include<cassert>
#include<algorithm>
#include<stdlib.h>
#define MAX 105

using namespace std;

struct Bar{ int height;  int pos; };

int compute( int size, int buffer[]){
    stack<Bar> S;
    int maxv = 0;
    buffer[size] = 0;

    for ( int i = 0; i <= size; i++ ){
	Bar bar;
	bar.height = buffer[i];
	bar.pos = i;
	if ( S.empty() ){
	    S.push( bar );
	} else {
	    if ( S.top().height < bar.height ){
		S.push( bar );
	    } else if ( S.top().height > bar.height ) {
		int target = i;
		while ( !S.empty() && S.top().height >= bar.height){
		    Bar pre = S.top(); S.pop();
		    int area = pre.height * (i - pre.pos);
		    maxv = max( maxv, area);
		    //		    cout << "area = " << area << endl;
		    target = pre.pos;
		}
		bar.pos = target;
		S.push(bar);
	    }
	}
    }
    return maxv;
}

main(){
    int M, N;
    int buffer[MAX][MAX];
    int T[MAX][MAX];
    int tmp[MAX];

    while( cin >> M >> N ){
	if ( M == 0 && N == 0 ) break;
	for ( int i = 0; i < M; i++ ){
	    for ( int j = 0; j < N; j++ ){
		cin >> buffer[i][j];
	    }
	}

	for ( int i = 0; i < M; i++ ){
	    for ( int j = 0; j < N; j++ ){
		T[i][j] = 0;
	    }
	}

	for ( int j = 0; j < N; j++ ){
	    int p = 0;
	    for ( int i = 0; i < M; i++ ){
		if ( buffer[i][j] == 1 ){
		    p = 0; T[i][j] = p;
		} else {
		    p++; T[i][j] = p;
		}
	    }
	}

	int maxv = 0;
	for ( int i = 0; i < M; i++ ){

	    for ( int j = 0; j < N; j++ ) tmp[j] = T[i][j];
	    
	    maxv = max( maxv, compute( N, tmp) );

	}

	cout << maxv << endl;
    }
    

}
