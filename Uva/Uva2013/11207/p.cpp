#include<stdio.h>
#include<algorithm>
using namespace std;

main(){
    int n, maxi;
    double w, h, maxv;

    while (1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	maxv = 0;
	for ( int i = 0; i < n; i++ ){
	    scanf("%lf %lf", &w, &h);
	    double value = max( max( min(w/4, h), min(w, h/4) ), min(w/2, h/2) );
	    if ( maxv < value ){ maxv = value; maxi = i;}
	}
	printf("%d\n", maxi+1);
    }
}
