#include<iostream>
#include<cstdio>
#include<complex>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i, n) for ( int i = 0; i < n; i++ )
#define REP(i, b, e) for ( int i = b; i <= e; i++ )
#define MAX 40
typedef complex<double> Point;
int n, m;
double P[MAX];
static const double PI = acos(-1.0);

double getArea(double r1, double r2, double r3){
    Point p1 = polar(1.0, r1*2*PI);
    Point p2 = polar(1.0, r2*2*PI);
    Point p3 = polar(1.0, r3*2*PI);
    double a = abs(p1 - p2);
    double b = abs(p2 - p3);
    double c = abs(p3 - p1);
    double s = (a + b + c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

void compute(){
    double M[MAX+1][MAX][MAX];
    double T[MAX][MAX][MAX];
    rep(i, n) rep(j, n) rep(k, n) T[i][j][k] = getArea(P[i], P[j], P[k]);
    double maxv = 0.0;
    rep(k, m+1) rep(i, n) rep(j, n) M[k][i][j] = 0.0;
    REP(k, 2, m-1){
	REP(i, 0, n-2) REP(j, i+1, n-1){
	    int t = (j+1)%n;
	    while(1){
		if ( t == i ) break;
		M[k+1][i][t] = max(M[k+1][i][t], M[k][i][j] + T[i][j][t]);
		t = (t+1)%n;
	    }
	}
    }
    rep(i, n) rep(j, n) maxv = max(maxv, M[m][i][j]);
    printf("%.6lf\n", maxv);
}

main(){
    while(1){
	scanf("%d %d", &n, &m);
	if ( n == 0 && m == 0 ) break;
	rep(i, n) scanf("%lf", &P[i]);
	compute();
    }
}
