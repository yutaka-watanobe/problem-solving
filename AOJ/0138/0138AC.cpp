#include<iostream>
#include<algorithm>
using namespace std;

#define N 8

class P{
    public:
    int id;
    double score;
    P( int i=0, double s=0):id(i), score(s){}

    bool operator < ( const P &p ) const{
	return score < p.score;
    }
};

main(){
    P A[N], B[N], C[N], D[3*N];
    int n;
    for ( int i = 0; i < N; i++ ) {cin >> A[i].id >> A[i].score; }
    for ( int i = 0; i < N; i++ ) {cin >> B[i].id >> B[i].score; }
    for ( int i = 0; i < N; i++ ) {cin >> C[i].id >> C[i].score; }
    sort( A, A + N );
    sort( B, B + N );
    sort( C, C + N );
    int k = 0;
    for ( int i = 2; i < N; i++ ) D[k++] = A[i];
    for ( int i = 2; i < N; i++ ) D[k++] = B[i];
    for ( int i = 2; i < N; i++ ) D[k++] = C[i];
    sort( D, D + k );	      

    for ( int i = 0; i < 2; i++ ) cout << A[i].id << " " << A[i].score <<endl;
    for ( int i = 0; i < 2; i++ ) cout << B[i].id << " " << B[i].score <<endl;
    for ( int i = 0; i < 2; i++ ) cout << C[i].id << " " << C[i].score <<endl;
    for ( int i = 0; i < 2; i++ ) cout << D[i].id << " " << D[i].score <<endl;


    
}
