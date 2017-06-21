#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define CMAX 1000
#define BMAX 100000

class Bar{
    public:
    int pos, depth, t1, t2;
    Bar(int p=0, int d=0):pos(p), depth(d){}
    bool operator < ( const Bar &b) const{
	return depth < b.depth;
    }
};

int T[CMAX];
Bar B[BMAX];
int n, m, h, k;

void compute(){
    int P[CMAX];
    for ( int i = 0; i < n; i++ ) P[i] = i;

    sort( B, B + m);

    for ( int i = 0; i < m; i++ ){
	swap( P[B[i].pos-1], P[B[i].pos] );
	B[i].t1 = P[B[i].pos-1];
	B[i].t2 = P[B[i].pos];
    }

    int minv = 0, total, S[CMAX];

    for ( int i = 0; i < n; i++ ) S[i] = 0;
    for ( int i = 0; i < n; i++ ){
	S[P[i]] = T[i];
	if ( P[i]+1 > k ) continue;
	minv += T[i];
    }
    total = minv;
    for ( int i = 0; i < m; i++ ){
	int source = min(B[i].t1, B[i].t2);
	int target = max(B[i].t1, B[i].t2);
	if ( source < k && k <= target ){
	    int score = total - S[source] + S[target];
	    minv = min(minv, score);
	}
    }

    cout << minv << endl;
}

main(){
    int a, b;
    while( cin >> n >> m >> h >> k && n){
	for ( int i = 0; i < n; i++ ) cin >> T[i];
	for ( int i = 0; i < m; i++ ){
	    cin >> a >> b;
	    B[i] = Bar(a, b);
	}
	compute();
    }
}
