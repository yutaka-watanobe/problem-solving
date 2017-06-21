#include<stdio.h>
#include<algorithm>
#include<cassert>
using namespace std;
#define MAX 16384

int source[MAX+1];
int size;

int pos, base, start, inside_base, outside_base;

void init(){
    int i = 1;
    int limit = (1<<30);
    size = 0;
    while( i*i < limit ){
	source[size++] = i*i;
	i += 2;
    }
}

void setParameters(int x){
    pos = distance(source, upper_bound(source, source + size, x));
    base = pos*2-1;
    start = base*base;
    //inside_base = (pos-1)*8+1;
    //outside_base = (pos)*8+1;
    outside_base = (pos << 3 ) + 1;
    inside_base = outside_base - 8;
}

int getUp(int x ){
    setParameters(x);
    if ( x >= start + base*3 + 3 ){
	return x + outside_base + 6;
    } else if ( x >= start + base*2 + 2 ){
	return x + 1;
    } else if ( x > start + base + 1  ){
	return x - (inside_base + 2);
    } else if ( x > start + 1 ) {
	return x - 1;
    } else if ( x >= start ){
	return x + outside_base - 2;
    } else {
	assert( false );
    }
}

int getLeft( int x ){
    setParameters(x);
    if ( x == 1 ) return 6;
    if ( x > start + base*3 + 3 ){
	return x - 1;
    } else if ( x >= start + base*2 + 2 ){
	return x + outside_base + 4;
    } else if ( x >= start + base + 1  ){
	return x + 1;
    } else if ( x > start + 1 ) {
	return x - inside_base;
    } else if ( x >= start ){
	return x -1;
    } else {
	assert( false );
    }
}

int getRight(int x ){
    setParameters(x);
    if ( x >= start + base*3 + 3 ){
	return x+1;
    } else if ( x > start + base*2 + 2 ){
	return x - (inside_base + 4);
    } else if ( x > start + base + 1  ){
	return x - 1;
    } else if ( x >= start + 1 ) {
	return x + outside_base;
    } else if ( x == start ){
	return x+1;
    } else {
	assert( false );
    }
}

int getDown(int x ){
    setParameters(x);
    if ( x == 1 ) return 4;
    if ( x > start + base*3 + 3 ){
	return x-(inside_base + 6);
    } else if ( x > start + base*2 + 2 ){
	return x - 1;
    } else if ( x >= start + base + 1  ){
	return x + outside_base + 2;
    } else if ( x >= start + 1 ) {
	return x + 1;
    } else if ( x == start ){
	return x - inside_base + 2;
    } else {
	assert( false );
    }
}

void compute(int x){
    int left = getLeft(x);
    int right = getRight(x);
    printf("%d;%d;%d;\n", getUp(left), getUp(x), getUp(right));
    printf("%d;%d;%d;\n", left, x, right);
    printf("%d;%d;%d;\n", getDown(left), getDown(x), getDown(right));
}

int main(){
    init();
    int n; 
    while(scanf("%d", &n)!= EOF){
	compute(n);
    }
    return 0;
}
