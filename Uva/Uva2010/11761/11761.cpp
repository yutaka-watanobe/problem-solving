#include<iostream>
#include<cmath>
using namespace std;
#define MAX 40000
typedef unsigned long long ullong;

ullong R, A;

ullong getArea(ullong a, ullong b, ullong c){
    double s= (a+b+c)/2.0;
    double S =  sqrt(s*(s-a)*(s-b)*(s-c));

    return (ullong)(S + 0.0000000000000001);
}

void compute(){
    ullong target = 4*A*R;
    /*
    for ( ullong a = 1; a <= MAX; a++ ){
	if ( a > target ) break;
	for ( ullong b = 1; b <= MAX; b++ ){
	    if ( a*b > target ) break;
	    for ( ullong c = 1; c <= a+b-1; c++ ){
		if ( a*b*c > target ) break;
		
		ullong s = getArea(a, b, c);

		//if ( s > A ) break;


		if ( s == A && a*b*c == target ){
		    cout << a << " " << b << " " << c << endl;
		    return;
		}
	    }
	}
	}*/
    /*
    for ( ullong c = 1; c <= MAX; c++ ){
	if ( c > target ) break;
	for ( ullong b = 1; b <= c; b++ ){
	    if ( c*b > target ) break;
	    for ( ullong a = 1; a <= b; a++ ){
		if ( a*b*c > target ) break;
		//		if ( a+b <= c ) break;
		ullong s = getArea(a, b, c);
		if ( s == A && a*b*c == target ){ 
		    cout << a << " " << b << " " << c << endl;
		    return;
		}
	    }
	}
	}*/
    
    for ( ullong a = 1; a <= 2*R; a++ ){
	if ( a > target ) break;
	if ( target % a ) continue;
	for (  ullong b = 1; b <= 2*R; b++ ){
	    ullong ab = a*b;
	    if ( ab > target ) break;
	    if ( ab > target ) break;
	    if ( target % ab ) continue;
	    ullong c = target / ab;
	    ullong s = getArea(a, b, c);

	    if ( s==A && a*b*c == target ){
		cout << a  << " " << b << " " << c << endl;
		return;
	    }

	}
    }
    

    cout << "-1 -1 -1" << endl;
}

main(){
    while(1){
	cin >> R >> A;
	if ( R == 0 && A == 0 ) break;
	compute();
    }
}
