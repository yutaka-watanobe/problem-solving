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
    int ans[9];
    setParameters(x);
    ans[4] = x;
    ans[1] = getUp(x);
    ans[7] = getDown(x);
    ans[3] = getLeft(x);
    ans[5] = getRight(x);
    setParameters(ans[3]);
    ans[0] = getUp(ans[3]);
    ans[6] = getDown(ans[3]);
    setParameters(ans[5]);
    ans[2] = getUp(ans[5]);
    ans[8] = getDown(ans[5]);
    
    printf("%d;%d;%d;\n", ans[0], ans[1], ans[2]);
    printf("%d;%d;%d;\n", ans[3], ans[4], ans[5]);
    printf("%d;%d;%d;\n", ans[6], ans[7], ans[8]);
}

int main(){
    init();
    int n; 
    while(scanf("%d", &n)!= EOF){
	compute(n);
    }
    return 0;
}
