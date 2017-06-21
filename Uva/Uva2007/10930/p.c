// sequence, map
#include<stdio.h>
#include<map>

int size;
int buffer[32];

bool isAsequence(){
    if ( size == 1 ) return true;

    map<int, bool> M = map<int,bool>();
    map<int, bool> nextM;

    M[buffer[0]] = true;

    for ( int i = 1; i < size; i++ ){
	int value = buffer[i];
	if ( buffer[i-1] >= value ) return false;
	if ( M[ value ] ) return false;

	nextM = M;

	map<int, bool>::iterator pos;
	for ( pos = M.begin(); pos != M.end(); pos++ ){
	    int sum = value;
	    if ( (*pos).second ){
		sum += (*pos).first;
	    }
	    nextM[sum] = true;
	}
	M = nextM;
    }

    return true;
}

bool read(){
    if ( scanf("%d", &size) == EOF ) return false;
    for ( int i = 0; i < size; i++ ){
	scanf("%d", &buffer[i]);
    }
    return true;
}

main(){
    for( int tcase = 1; read(); tcase++ ){
	printf("Case #%d:", tcase);
	for ( int i = 0; i < size; i++ ){
	    printf(" %d", buffer[i]);
	}
	printf("\n");
	if ( isAsequence() ) printf("This is an A-sequence.\n");
	else printf("This is not an A-sequence.\n");
    }
}
