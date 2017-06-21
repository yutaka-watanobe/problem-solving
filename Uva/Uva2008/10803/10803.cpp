// Floyd
#include<iostream>
#include<cmath>
using namespace std;
static const int MAX = 101;
static const int INFTY = (1 << 21);
struct Point{
    double x, y;
};

double D[MAX][MAX];
int size;
Point P[MAX];

void floyd(){
    for ( int k = 0; k < size; k++ ){
	for ( int i = 0; i < size; i++ ){
	    if ( D[i][k] == INFTY ) continue;
	    for ( int j = 0; j < size; j++ ){
		if ( D[k][j] == INFTY ) continue;
		if ( D[i][j] == INFTY || D[i][k] + D[k][j] < D[i][j] ){
		    D[i][j] = D[i][k] + D[k][j];
		}
	    }
	}
    }
}

double getDist( Point p1, Point p2 ){
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void compute(){
    for ( int i = 0; i < size; i++ ){
	for( int j = 0; j < size; j++ ){
	    double dist = getDist( P[i], P[j] );
	    if ( dist <= 10.0 ) D[i][j] = dist;
	    else D[i][j] = INFTY;
	}
    }
    floyd();

    double ans = 0.0;
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < size; j++ ){
	    if ( i == j ) continue;
	    if ( D[i][j] == INFTY) {
		cout << "Send Kurdy" << endl;
		return;
	    }
	    ans = max( ans, D[i][j] );
	}
    }

    // fabs(ans*1e4 - floor(ans*1e4) - 0.5) > 1e-2
    printf("%.4lf\n", ans);
}

void input(){
    cin >> size;
    for ( int i = 0; i < size; i++ ){
	cin >> P[i].x >> P[i].y;
    }
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	cout << "Case #" << i << ":" << endl;
	input();
	compute();
	cout << endl;
    }
}
