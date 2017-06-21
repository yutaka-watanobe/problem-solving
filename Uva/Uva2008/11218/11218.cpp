#include<iostream>
using namespace std;
#define MAX 82

main(){
    int n;
    int T[MAX][4];
    bool used[10];
    int tcase = 1;
    while ( cin >> n && n ){
	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < 4; j++ ) cin >> T[i][j];
	}

	int max_score = -1;

	for ( int g1 = 0; g1 < n - 2; g1++ ){
	    for ( int g2 = g1+1; g2 < n - 1; g2++ ){
		for ( int g3 = g2+1; g3 < n; g3++ ){

		    fill( used, used + 10, false );

		    for ( int i = 0; i < 3; i++ ) {
			used[T[g1][i]] = true;
			used[T[g2][i]] = true;
			used[T[g3][i]] = true;
		    }

		    bool notFilled = false;
		    for ( int i = 1; i <= 9; i++ ) {
			if ( !used[i] ) notFilled = true;
		    }

		    if ( notFilled ) continue;

		    int score = T[g1][3] + T[g2][3] + T[g3][3];
		    max_score = max(max_score, score);

		}
	    }
	}
	cout << "Case " << tcase++ << ": " << max_score << endl;
    }
}
