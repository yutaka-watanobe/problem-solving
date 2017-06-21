#include<iostream>
using namespace std;
#define MAX 26

int N, G[MAX][2], m;
long long T[MAX][32];
bool isTarget[MAX];

void compute(){
    for ( int i = 0; i < MAX; i++ )
	for ( int j = 0; j <= m; j++ ) T[i][j] = 0;

    T[0][0] = 1; // 'A' can be end

    for ( int j = 0; j < m; j++ ){
	for ( int i = 0; i < MAX; i++ ){
	    T[G[i][0]][j+1] += T[i][j];
	    T[G[i][1]][j+1] += T[i][j];
	}
    }

    long long sum = 0;
    for ( int i = 0; i < MAX; i++ ) if( isTarget[i] ) sum += T[i][m];
    cout << sum << endl;
}

void input(){
    char ch;
    int id;
    for ( int i = 0; i < MAX; i++ ) isTarget[i] = false;
    for ( int i = 0; i < N; i++ ){
	cin >> ch; id = ch - 'A';
	cin >> ch; G[id][0] = ch - 'A';
	cin >> ch; G[id][1] = ch - 'A';
	cin >> ch; 
	if ( ch == 'x' ) isTarget[id] = true;
	else isTarget[i] = false;
    }
    cin >> m;
}

int main(){
    while ( cin >> N ){
	input();
	compute();
    }
    return 0;
}
