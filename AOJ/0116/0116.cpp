#include<stdio.h>
#include<iostream>
#include<cassert>
#include<stack>
#include<algorithm>
#define MAX 505
#define BLOCK 0

using namespace std;

struct Rectangle{ int height;  int pos; };

int getLargestRectangle( int size, int buffer[]){
    //stack<Rectangle> S;
    Rectangle S[1000];
    int top = 0;
    int maxv = 0;
    buffer[size] = 0;
    
    for ( int i = 0; i <= size; i++ ){
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if ( top == 0 ){
            //S.push( rect );
	    S[++top] = rect;
        } else {
            if ( S[top].height < rect.height ){
                //S.push( rect );
		S[++top] = rect;
	    } else if ( S[top].height > rect.height ) {
                 int target = i;
                 while ( top > 0 && S[top].height >= rect.height){
                     //Rectangle pre = S.top(); S.pop();
		     Rectangle pre = S[top--];
                     int area = pre.height * (i - pre.pos);
                     maxv = max( maxv, area);
                     target = pre.pos;
                 }
                 rect.pos = target;
                 //S.push(rect);
		 S[++top] = rect;
             }
         }
     }
     return maxv;
 }

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];
 
int getLargestRectangle(){
    for ( int i = 0; i < H; i++ ){
	for ( int j = 0; j < W; j++ ){
	    T[i][j] = 0;
	}
    }
     
    for ( int j = 0; j < W; j++ ){
	int sequence = 0;
	for ( int i = 0; i < H; i++ ){
	    if ( buffer[i][j] == BLOCK ){
		sequence = T[i][j] = 0;
	    } else {
		T[i][j] = ++sequence;
	    }
	}
    }
    
    int maxv = 0;
    for ( int i = 0; i < H; i++ ){
	maxv = max( maxv, getLargestRectangle( W, T[i] ) );
    }
    
    return maxv;
}

int main(void){
    char ch;
    while(1){
	scanf("%d %d", &H, &W);
	if ( H == 0 && W == 0) break;
	scanf("%c", &ch);
	char ch;
	for ( int i = 0; i < H; i++ ){
	    for ( int j = 0; j < W; j++ ){
		scanf("%c", &ch);
		if ( ch == '*' ) buffer[i][j] = 0;
		else buffer[i][j] = 1;
	    }
	    scanf("%c", &ch);
	}
	cout << getLargestRectangle() << endl;
    }
    
    return 0;
}
