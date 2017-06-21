// pku 2559
// Largest Rectangle in a Histogram
// 
//
//

#include<stdio.h>
#include<iostream>
#include<stack>
#include<cassert>
#include<algorithm>
#include<stdlib.h>
#define MAX 200000
typedef long long llong;

using namespace std;

struct Bar{ llong height;  int pos; };

llong compute( int size, llong buffer[]){
    stack<Bar> S;
    llong maxv = 0;
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
		    llong area = pre.height * (i - pre.pos);
		    maxv = max( maxv, area);
		    //		    cout << "area = " << area << endl;
		    target = pre.pos;
		}
		bar.pos = target;
		S.push(bar);
	    }
	}
    }

    //    cout << maxv << endl;
    //    printf("%lld\n", maxv);
    return maxv;
}

llong computeBF( int size, llong buffer[] ){

    llong maxv = 0;
    for ( int i = 0; i < size; i++ ){
	for ( int j = i; j < size; j++ ){
	    llong minh = INT_MAX;
	    for ( int k = i; k <= j; k++ ){
		minh = min( minh, buffer[k] );
	    }
	    maxv = max( maxv, minh*(j-i+1));
	}
    }
    return maxv;
}


main(){
    int size;
    llong buffer[MAX+1];
    llong buffer2[MAX+1];
    while(1){
	scanf("%d", &size);
	if ( size == 0 ) break;
	for ( int i = 0; i < size; i++ ){
	    scanf("%lld", &buffer[i]);
	    //	    cin >> buffer[i];
	}
	/*
	for ( int i = 0; i < size; i++ ){
	    buffer2[i] = buffer[size-i-1];
	    }*/
	cout << compute( size, buffer ) << endl;
	//	assert( compute(size, buffer) == compute(size, buffer2) );
	//	assert( compute(size, buffer) == computeBF(size, buffer) );
    }
}
