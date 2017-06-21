#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int RT[24][6] = {
    {1,2,3,4,5,6}, {1,3,5,2,4,6}, {1,5,4,3,2,6}, {1,4,2,5,3,6},
    {4,2,1,6,5,3}, {4,1,5,2,6,3}, {4,5,6,1,2,3}, {4,6,2,5,1,3},
    {6,2,4,3,5,1}, {6,4,5,2,3,1}, {6,5,3,4,2,1}, {6,3,2,5,4,1},
    {3,2,6,1,5,4}, {3,6,5,2,1,4}, {3,5,1,6,2,4}, {3,1,2,5,6,4},
    {5,1,3,4,6,2}, {5,3,6,1,4,2}, {5,6,4,3,1,2}, {5,4,1,6,3,2},
    {2,1,4,3,6,5}, {2,4,6,1,3,5}, {2,6,3,4,1,5}, {2,3,1,6,4,5}
};

int T[3][3], F[3][3], puzzle[27];
set<int> solved;

int getRight(){
    int sum = 0;
    for ( int i = 2; i < 27; i += 3 ) sum += RT[puzzle[i]][2];
    return sum;
}

void recursive( int pos ){
    if ( pos == 27 ){ solved.insert(getRight()); return; }
    int i = (pos%9)/3;
    int j = (pos%9)%3;
    int k = pos/9;
    
    for ( int r = 0; r < 24; r++ ){
	if ( i == 0 && T[3-k-1][j] && T[3-k-1][j] != RT[r][0] ) continue;
	if ( k == 0 && F[i][j] && F[i][j] != RT[r][1] ) continue;
	if ( i && RT[r][0] + RT[puzzle[k*9+(i-1)*3+j]][5] != 7 ) continue;
	if ( k && RT[r][1] + RT[puzzle[(k-1)*9+i*3+j]][4] != 7 ) continue;
	if ( j && RT[r][3] + RT[puzzle[k*9+i*3+(j-1)]][2] != 7 ) continue;
	puzzle[pos] = r;
	recursive( pos+1 );
    }
}

void compute(){
    solved.clear();
    recursive(0); 
    if ( solved.size() == 0 ) {	cout << 0 << endl; return; }
    set<int>::iterator p = solved.begin();
    cout << *p;
    for ( p++; p != solved.end(); p++ ) cout << " " << *p;
    cout << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int t = 0; t < tcase; t++ ){
	for ( int i = 0; i < 3; i++ ) {
	    for ( int j = 0; j < 3; j++ ) cin >> T[i][j];
	}
	for ( int i = 0; i < 3; i++ ) {
	    for ( int j = 0; j < 3; j++ ) cin >> F[i][j];
	}
	compute();
    }
}
