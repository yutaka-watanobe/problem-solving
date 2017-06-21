#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

static const double PI = acos(-1);

double L, W, T;

void compute(){
    double l = W/(tan(T*PI/180));
    double d = sqrt(W*W + l*l);
    double A = 0, B = 0;
    double rem = L;
    int cnt = 0;
    while(rem > l){
	cnt++;
	rem -= l;
	A += d;
    }

    double dw = tan(T*PI/180)*rem;
    double dd = sqrt(rem*rem+dw*dw);

    A += dd;

    double h;
    if ( cnt % 2 ) h = W - dw;
    else h = dw;

    B = sqrt(h*h + L*L);

    printf("%.3lf\n", A/B);

}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cin >> L >> W >> T;
	compute();
    }
}
