#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 100
class Tree{
    public:
    string L;
    double value;
    int P, A, B, C, D, E, F, S, M;
    Tree(){}

    void setValue(){
	int t = A + B + C + (D+E)*M;
	int v = F*S*M - P;
	value = 1.0*v/t;
    }

    bool operator < ( const Tree &t ) const{
	if ( fabs(value - t.value) < 0.000000001 ) return L < t.L;
	return value > t.value;
    }
};

main(){
    Tree T[MAX];
    int n;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	for ( int i = 0; i < n; i++ ){
	    cin >> T[i].L >> T[i].P >> T[i].A >> T[i].B;
	    cin >> T[i].C >> T[i].D >> T[i].E >> T[i].F;
	    cin >> T[i].S >> T[i].M;
	    T[i].setValue();
	}
	sort(T, T+n);
	for ( int i = 0; i < n; i++ ) cout << T[i].L << endl;
	cout << "#" << endl;
    }
}
