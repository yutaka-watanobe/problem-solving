#include<iostream>
#include<queue>
#include<cmath>
#define MAX 102

using namespace std;

struct Island{
    int x, y, r, id;
};

int K, M, N;
Island I[MAX];

double getDist( Island p1, Island p2 ){
    double d = sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
    return d - (p1.r + p2.r);
}

bool bfs(){
    bool visited[MAX];
    for ( int i = 0; i < N; i++ ) visited[i] = false;

    queue<Island> Q;

    Q.push(I[0]);
    Island u, v;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.id == 1 ) return true;
	
	for ( int i = 1; i < N; i++ ){
	    if ( visited[i] ) continue;
	    if ( getDist(u, I[i]) > 1.0*K*M ) continue;

	    visited[i] = true;
	    Q.push(I[i]);
	}
    }

    return false;
}

main(){
    while( cin >> K >> M ){
	cin >> I[0].x >> I[0].y >> I[0].r;
	cin >> I[1].x >> I[1].y >> I[1].r;
	I[0].id = 0;
	I[1].id = 1;
	cin >> N;
	for ( int i = 2; i < N + 2; i++ ){
	    cin >> I[i].x >> I[i].y >> I[i].r;
	    I[i].id = i;
	}
	N += 2;
	if (bfs()) cout << "Larry and Ryan will escape!" << endl;
	else cout << "Larry and Ryan will be eaten to death." << endl;


    }
}
