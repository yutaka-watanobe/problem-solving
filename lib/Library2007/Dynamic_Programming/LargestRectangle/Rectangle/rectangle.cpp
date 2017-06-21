// uva 10074
// Take the Land
// N, N but in this case only size
//
//

#include<stdio.h>
#include<iostream>
#include<stack>
#include<cassert>
#include<algorithm>
#define MAX 105
#define BLOCK 0

using namespace std;

struct Rectangle{ int height;  int pos; };

int getLargestRectangle( int size, int buffer[]){
    stack<Rectangle> S;
    int maxv = 0;
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
		    int area = pre.height * (i - pre.pos);
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

int size;
int buffer[MAX][MAX];
int T[MAX][MAX];

int getLargestRectangle(){
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    T[i][j] = 0;
	}
    }
    
    for ( int j = 0; j < size; j++ ){
	int sequence = 0;
	for ( int i = 0; i < size; i++ ){
	    if ( buffer[i][j] == BLOCK ){
		sequence = T[i][j] = 0;
	    } else {
		T[i][j] = ++sequence;
	    }
	}
    }
    
    int maxv = 0;
    for ( int i = 0; i < size; i++ ){
	maxv = max( maxv, getLargestRectangle( size, T[i] ) );
    }
    
    return maxv;
}

int getLargestRectangleBF(){
    int maxArea = 0;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    for ( int height = 1; height <= size - i; height++ ){
		for ( int width = 1; width <= size - j; width++ ){
		    bool isRectangle = true;
		    for ( int a = i; a < i + height; a++ ){
			for ( int b = j; b < j + width; b++ ){
			    if ( buffer[a][b] == BLOCK ) {
				isRectangle = false;
			    }
			}
		    }
		    if ( isRectangle ) {
			maxArea = max( maxArea, height*width );
		    }
		}
	    }
	}
    }
    return maxArea;
}


main(){
    while( cin >> size, size ){
	for ( int i = 0; i < size; i++ ){
	    for ( int j = 0; j < size; j++ ){
		cin >> buffer[i][j];
	    }
	}
	cout << getLargestRectangle() << " ";
	cout << getLargestRectangleBF() << endl;
    }
}
