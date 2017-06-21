// pku 2559 (Largest Rectangle in a Histogram)
// O(n) algorithm

#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#define MAX 110000
typedef long long llong;

using namespace std;

struct Rectangle{ llong height;  int pos; };

llong getRectangleArea( int size, llong buffer[]){
    stack<Rectangle> S;
    llong maxv = 0;
    buffer[size] = 0;

    for ( int i = 0; i <= size; i++ ){
	Rectangle rect;
	rect.height = buffer[i];
	rect.pos = i;
	if ( S.empty() ){
	    S.push( rect );
	} else {
	    if ( S.top().height < rect.height ){
		S.push( rect );
	    } else if ( S.top().height > rect.height ) {
		int target = i;
		while ( !S.empty() && S.top().height >= rect.height){
		    Rectangle pre = S.top(); S.pop();
		    llong area = pre.height * (i - pre.pos);
		    maxv = max( maxv, area);
		    target = pre.pos;
		}
		rect.pos = target;
		S.push(rect);
	    }
	}
    }

    return maxv;
}

llong getRectangleAreaMyStack( int size, llong buffer[]){
    Rectangle S[MAX+1];
    int top = 0;
    llong maxv = 0;
    buffer[size] = 0;

    for ( int i = 0; i <= size; i++ ){
	Rectangle rect;
	rect.height = buffer[i];
	rect.pos = i;
	if ( top == 0 ){
	    S[++top] = rect;
	} else {
	    if ( S[top].height < rect.height ){
		S[++top] = rect;
	    } else if ( S[top].height > rect.height ) {
		int target = i;
		while ( top > 0 && S[top].height >= rect.height){
		    Rectangle pre = S[top]; top--;
		    llong area = pre.height * (i - pre.pos);
		    maxv = max( maxv, area);
		    target = pre.pos;
		}
		rect.pos = target;
		S[++top] = rect;
	    }
	}
    }

    return maxv;
}

llong getRectangleAreaBF( int size, llong buffer[] ){
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

    while(1){
	scanf("%d", &size);
	if ( size == 0 ) break;
	for ( int i = 0; i < size; i++ ) scanf("%lld", &buffer[i]);
	cout << getRectangleAreaMyStack( size, buffer ) << endl;
    }
}
