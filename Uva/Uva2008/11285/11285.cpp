#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 365
#define CAD 0
#define USD 1

int nday;
double D[MAX + 1];

void compute(){
    int M[MAX+1][2];
    for ( int i = 0; i <= nday; i++ ) M[i][CAD] = M[i][USD] = 0;
    M[0][CAD] = 100000;
    
    for ( int i = 1; i <= nday; i++ ){
	M[i][CAD] = max( M[i-1][CAD], (int)(M[i-1][USD]*D[i]*0.97));
	M[i][USD] = max( M[i-1][USD], (int)(M[i-1][CAD]/D[i]*0.97));
    }

    printf("%.2lf\n", (double)M[nday][CAD]/100);
}

main(){
    while( scanf("%d", &nday) && nday ){
	for ( int i = 1; i <= nday; i++ ) scanf("%lf", &D[i]);
	compute();
    }
}
