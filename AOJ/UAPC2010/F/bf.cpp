#include<iostream>
#include<cstdio>
using namespace std;

double power(int n){
    double p = 1.0;
    for ( int i = 0; i < n; i++ ) p *= 2.0;
    return p;
}
void rec(int p, int n, int seq, double pr, int cnt, double &exp, bool pre){
    if ( p == n ){
	exp += cnt*pr;
	return;
    }

    if ( pre ){
	rec(p+1, n, seq+1, pr*(1/power(seq)), cnt+1, exp, true);
	rec(p+1, n, 0, pr*(1.0 - 1/power(seq)), cnt, exp, false);
    } else {
	rec(p+1, n, seq+1, pr, cnt+1, exp, true);
    }
}

void compute(int n){
    double exp = 0.0;

    rec(1, n, 1, 1.0, 1, exp, true);

    printf("%.12lf\n", exp);
}

main(){
    int n;
    while( cin >> n && n) compute(n);
}
