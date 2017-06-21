#include<iostream>
#include<algorithm>
#define MAX 30
using namespace std;

class Box{
    public:
    int n, D[10], id;
    Box(){}
    Box(int n, int id):n(n), id(id){ for ( int i = 0; i < n; i++ ) D[i] = 0;}

    void sortB(){
	sort( D, D + n );
    }

    bool include( Box &b ){
	for ( int i = 0; i < n; i++ ){
	    if ( D[i] <= b.D[i] ) return false;
	}
	return true;
    }

    bool operator < ( const Box &b ) const{
	return D[0] < b.D[0];
    }

};

int n, d;
Box B[MAX+1];
bool isFast;

void printLIS(int i, int P[]){
    if ( P[i] == -1 ) return;
    printLIS(P[i], P);

    if ( isFast ){
	isFast = false;
    } else cout << " ";
    cout << B[i].id;
}

void compute(){
    int L[MAX+1], P[MAX+1];
    L[0] = 0;
    P[0] = -1;
    for ( int i = 1; i <= n; i++ ){
	int k = 0; // max index
	for ( int j = 0; j <= i - 1; j++ ){
	    if ( B[i].include(B[j]) && L[j] > L[k] ){
		k = j;
	    }
	}
	L[i] = L[k] + 1;
	P[i] = k;
    }

    // print result
    int maxv = 0;
    int maxi;
    for ( int i = 1; i <= n; i++ ){
	if ( maxv <= L[i] ){
	    maxv = L[i];
	    maxi = i;
	}
    }
    
    cout << maxv << endl;
    isFast = true;
    printLIS(maxi, P);
    cout << endl;
}

int main(){
    while( cin >> n >> d ){
	B[0] = Box(d, 0);
	for ( int i = 1; i <= n; i++ ){
	    B[i] = Box(d, i);
	    for ( int j = 0; j < d; j++ ) cin >> B[i].D[j];
	    B[i].sortB();
	}
	sort( B, B + n + 1 );
	compute();
    }
    return 0;
}


