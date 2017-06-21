#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define MAX 10000

class Piece{
    public:
    int size, buffer[MAX];

    Piece(){ size = 0;}
    Piece(int size):size(size){}

    void insert( int x ){
	buffer[size++] = x;
    }

    int getEnd(){
	return buffer[size-1];
    }

    bool operator < ( const Piece &p ) const{
	    return size < p.size;
	if ( size == p.size )
	    buffer[size-1] > p.buffer[size-1];
	else
	    return size < p.size;
    }
};

pair<int, int> bugs[MAX];
int n, size;

void compute(){
    reverse( bugs, bugs + size );
    multiset<Piece> pieces;

    for ( int j = 0; j < bugs[0].second; j++ ){
	Piece newPiece;
	newPiece.insert( bugs[0].first );
	pieces.insert(newPiece);
    }

    for ( int i = 1; i < size; i++ ){
	for ( int j = 0; j < bugs[i].second; j++ ){
	    Piece top = *(pieces.begin()); 
	    pieces.erase(pieces.begin());
	    if ( top.getEnd() <= bugs[i].first ){
		Piece newPiece;
		newPiece.insert( bugs[i].first );
		pieces.insert(newPiece);
		pieces.insert(top);
	    } else {
		Piece newPiece = top;
		newPiece.insert( bugs[i].first );
		pieces.insert(newPiece);
	    }


	}
    }

    printf("%d\n", pieces.size());
    for ( multiset<Piece>::iterator it = pieces.begin(); it != pieces.end(); it++ ){
	Piece p = *it;
	for ( int i = 0; i < p.size; i++ ){
	    if (i) printf(" ");
	    printf("%d", p.buffer[i]);
	}
	printf("\n");
    }

    
}

void initialize(){
    int x, pre, cnt;
    scanf("%d", &pre);
	cnt = size = 0;
	for ( int i = 1; i < n; i++ ){
	    scanf("%d", &x);
	    if ( x == pre ){
		cnt++;
	    } else {
		bugs[size].first = pre;
		bugs[size++].second = ++cnt;
		cnt = 0;
	    }
	    pre = x;
	}
	bugs[size].first = pre;
	bugs[size++].second = ++cnt;

/*
	for ( int i = 0; i < size; i++ ){
	    cout << bugs[i].first << " " << bugs[i].second << endl;
	}
	cout << endl;
	*/
}

int main(){
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	initialize();
	compute();
    }
    return 0;
}
