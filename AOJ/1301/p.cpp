#include<iostream>
#include<cmath>
using namespace std;

main(){
    double x1, x2, x3, y1, y2, y3, r1, r2;
    double a, b, h, l, alpha, beta;
    
    l = 13;
    alpha = 45;
    beta = 30;
    r1 = 2;

    alpha = (alpha*acos(-1)/180.0);
    beta = (beta*acos(-1)/180.0);

    cout << alpha << " " << beta << endl;

    double A, B, C;
    
    A = 1.0/((tan(beta)*tan(beta)));
    B = 2*r1/(tan(alpha)*tan(beta)) - 2*l/tan(beta) - 4*r1;
    C = l*l - 2*r1*l/tan(alpha) + r1*r1/(tan(alpha)*tan(alpha));

    r2 = (-B - sqrt(B*B-4*A*C))/(2*A);

    cout << (-B - sqrt(B*B-4*A*C))/(2*A) << endl;
    cout << (-B + sqrt(B*B-4*A*C))/(2*A) << endl;

    
}
