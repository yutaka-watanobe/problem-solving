// math
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

main(){
    double T, D, H, h, e;
    char in1,in2;
    
    while(cin >> in1 && in1 != 'E'){
	if(in1 == 'T') cin >> T;
	else if(in1 == 'D') cin >> D;
	else  cin >> H;
	cin >> in2;
	if(in2 == 'T') cin >> T;
	else if(in2 == 'D') cin >> D;
	else  cin >> H;
	
	if( (in1 == 'T' && in2 == 'D') ||	(in1 == 'D' && in2 == 'T') ){
	    e = 6.11*exp(5417.7530*((1./273.16)-(1./(D+273.16))));
	    h = (0.5555)*(e-10.0);
	    H = T + h;
	}
	if( (in1 == 'H' && in2 == 'D') ||	(in1 == 'D' && in2 == 'H') ){
	    e = 6.11*exp(5417.7530*((1./273.16)-(1./(D+273.16))));
	    h = (0.5555)*(e-10.0);
	    T = H - h;
	}
	if( (in1 == 'T' && in2 == 'H') ||	(in1 == 'H' && in2 == 'T') ){
	    h = H - T;
	    e = h/0.5555 + 10.0;
	    double a = 273.16;
	    D = 1./(((log(6.11)-log(e))/5417.7530) + 1/a) - a;
	}
	printf("T %.1f D %.1f H %.1f\n",T,D,H);
    }
}

