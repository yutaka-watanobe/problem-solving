// division (remainder)
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 1001

int buffer[MAX];
int size;

bool isMultiple(){
    reverse( buffer, buffer + size );
    
    while ( size < 3 ){
	buffer[size] = 0;
	size++;
    }

    int value, rem;
    for ( int current = size - 3; current >= 1; current-- ){
	value = 100*buffer[current+2] + 10*buffer[current+1] + buffer[current];
	rem = value % 11;
	buffer[current+2] = rem / 100; rem %= 100;
	buffer[current+1] = rem / 10; rem %= 10;
	buffer[current+0] = rem;
    }

    value = 100*buffer[2] + 10*buffer[1] + buffer[0];
    return value % 11 == 0;
}

void compute(){
    for ( int i = 0; i < size; i++) printf("%d", buffer[i]);
    if ( isMultiple() ){
	printf(" is a multiple of 11.\n");
    } else {
	printf(" is not a multiple of 11.\n");
    }
}

bool read(){
    char ch;
    size = 0;
    while ( 1 ){
	scanf("%c", &ch);
	if ( ch == '\n' ) break;
	buffer[size++] = ch - '0';
    }
    if ( size == 1 && buffer[0] == 0 ) return false;
    return true;
}

main(){
    while ( read() ){
	compute();
    }
}
