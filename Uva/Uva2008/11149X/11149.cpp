#include<iostream>
using namespace std;
#define MAX 41
#define KMAX 1000000

struct Matrix{
    int M[MAX][MAX], size;
};

bool added[KMAX+1];
Matrix ans;

void add(Matrix A){
    for ( int i = 0; i < A.size; i++ ){
	for ( int j = 0; j < A.size; j++ ){
	    ans.M[i][j] += A.M[i][j];
	    ans.M[i][j] %= 10;
	}
    }
}

Matrix mul( Matrix A, Matrix B ){
    Matrix C;
    C.size = A.size;
    for ( int i = 0; i < A.size; i++ ){
	for ( int j = 0; j < B.size; j++ ){
	    C.M[i][j] = 0;
	    for ( int k = 0; k < C.size; k++ ){
		C.M[i][j] += (A.M[i][k]*B.M[k][j])%10;
		C.M[i][j] %= 10;
	    }
	}
    }
    return C;
}

Matrix pow( Matrix m, int p ){

    Matrix ans = m;

    if ( p == 1 ) {
	if ( !added[p] ){
	    added[p] = true;
	    add(ans);
	}
	return ans;
    }

    
    Matrix tmp = pow( m, p/2 );
    if ( p % 2 == 0 ){
	ans =  mul( tmp, tmp );
    } else {
	ans =  mul( m, mul(tmp, tmp) );
    }
    if ( !added[p] ){
	added[p] = true;
	add(ans);
    }

    if ( !added[p/2] ){
	added[p/2] = true;
	add(tmp);
    }

    return ans;
    
}

main(){
    int n, k;
    while( cin >> n >> k && n && k ){
	Matrix m;
	m.size = n;
	for ( int i = 0; i < n ; i++ ){
	    for ( int j = 0; j < n; j++ ) {
		cin >> m.M[i][j];
		m.M[i][j] %= 10;
	    }
	}
	ans = m;
	for ( int i = 1; i <= k; i++ ) added[i] = false;
	added[1] = true;

	for ( int i = k; i >= 2; i-- ){
	    if ( added[i] ) continue;
	    cout << "add " << i << endl;
	    added[i] = true;
	    add( pow( m, i ) );
	}

	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < n; j++ ){
		if ( j ) cout << " ";
		cout << ans.M[i][j];
	    }
	    cout << endl;
	}
	
	cout << endl;
    }
}
