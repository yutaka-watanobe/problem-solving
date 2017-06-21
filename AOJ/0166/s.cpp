 #include<iostream>
 #include<cmath>
 using namespace std;
 #define MAX 720
 
 int m, n;
 int D[MAX];
 
 double getArea(int size ){
     D[size-1] = 360;
     for ( int i = 0; i < size-1; i++ ) D[size-1] -= D[i];
     double a = 0.0;
     for ( int i = 0; i < size; i++ ){
 	a += sin(D[i]*acos(-1)/180.0)/2.0;
     }
     return a;
 }
 
 main(){
     int d;
     double S1, S2;
     while(1){
 	cin >> m;
 	if ( m == 0 ) break;
 	for ( int i = 0; i < m-1; i++ ) {
 	    cin >> D[i];
 	}
 	S1 = getArea(m);
 	cin >> n;
 	for ( int i = 0; i < n-1; i++ ) {
 	    cin >> D[i];
 	}
 	S2 = getArea(n);
 	if ( fabs(S1 - S2) < 0.0000001 ) cout << 0 << endl;
 	else if ( S1 > S2 ) cout << 1 << endl;
 	else cout << 2 << endl;
     }
 }
