#include<stdio.h>

int P[7];

int max( int x, int y ){
    if ( x > y ) return x;
    else return y;
}

int min( int x, int y ){
    if ( x < y ) return x;
    else return y;
}

int compute(){
    int parcel = 0;
    int rem, val;

    // 6
    parcel += P[6];
    
    // 5
    parcel += P[5];
    P[1] -= min( P[1], P[5]*11);

    // 4
    parcel += P[4];
    rem = P[4]*5; // p2
    
    val = min(P[2], rem);

    rem -= val;
    P[2] -= val;

    rem *= 4; // p1

    P[1] -= min( P[1], rem );

    // 3
    parcel += P[3]/4; 
    P[3] = P[3]%4;

    if ( P[3] == 3 ) {
	parcel++;
	rem = 1;
	val = min(P[2], rem);
	rem -= val;
	P[2] -= val;
	rem = rem*4 + 5;
	P[1] -= min( P[1], rem );
    } else if ( P[3] == 2 ){
	parcel++;
	rem = 3;
	val = min(P[2], rem);
	rem -= val;
	P[2] -= val;
	rem = rem*4 + 6;
	P[1] -= min( P[1], rem );
    } else if ( P[3] == 1 ){
	parcel++;
	rem = 5;
	val = min(P[2], rem);
	rem -= val;
	P[2] -= val;
	rem = rem*4 + 7;
	P[1] -= min( P[1], rem );
    } 
    
    // 2
    parcel += P[2]/9; 
    P[2] = P[2]%9;
    
    if ( P[2] > 0){
	parcel++;
	rem = 36 - P[2]*4;
	P[1] -= min( P[1], rem );
    }

    // 1
    parcel += P[1]/36;
    P[1] = P[1]%36;

    if ( P[1] > 0 ) parcel++;


    
    return parcel;
}

int main(){
    while(1){
	int sum = 0;
	for ( int i = 1; i <= 6; i++ ) { scanf("%d", &P[i]); sum += P[i];}
	if ( sum == 0 ) break;
	printf("%d\n", compute());
    }

    return 0;
}
