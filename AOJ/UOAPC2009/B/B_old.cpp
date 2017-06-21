#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
int main(){
    
    int n;
    char tp;

    int M[3][3], T[3][3];
    while( cin >> n ){
	cin >> tp;
	rep(i, 3) rep(j, 3) M[i][j] = 0;
	M[0][1] = M[1][0] = M[1][2] = M[2][1] = 1;
	for ( int t = 1; t < n; t++ ){
	    rep(a, 3) rep(b, 3) T[a][b] = 0;

	    static const int di[4] = {0, -1, 0, 1};
	    static const int dj[4] = {1, 0, -1, 0};
	    int ni, nj;
	    rep(i, 3) rep(j, 3){
		for ( int r = 0; r < 4; r++ ){
		    ni = i + di[r];
		    nj = j + dj[r];
		    if  ( ni < 0 || nj < 0 || ni >= 3 || nj >= 3 ) {
			T[i][j]+=M[i][j];
		    } else {
			T[ni][nj]+=M[i][j];
		    }
		}
	    }
	    rep(a, 3) rep(b, 3) M[a][b] = T[a][b];
	}

	int pos = tp - 'A';
	int num = M[pos/3][pos%3];

	int p = 1;
	for (int i = 0; i < n; i++ ) p *= 4;

	//	cout << num << "/" << p << endl;
	printf("%.8lf\n", 1.0*num/p);
	/*
	for ( int i = 0; i < 3; i++ ){
	    for (int j = 0; j < 3; j++ ){
		printf("%25d", M[i][j]);
	    }
	    cout << endl;
	    }*/
    }

}
