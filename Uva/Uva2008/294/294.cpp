#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int getNumberOfDivisor(int n){
    int sum = 0;
    for ( int i = 1; i*i <= n; i++ ){
	if ( i*i == n ) sum++;
	else if ( n % i == 0 ) sum += 2;
    }
    return sum;
}

void compute(){
    int L, U;
    scanf("%d %d", &L, &U);
    int maxi, maxv;
    maxv = 0;
    for ( int i = L; i <= U; i++ ){
	int ndiv = getNumberOfDivisor(i);
	if ( maxv < ndiv ){
	    maxv = ndiv;
	    maxi = i;
	}
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, maxi, maxv);
}

int main(){
    int n; scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) compute();
    return 0;
}
