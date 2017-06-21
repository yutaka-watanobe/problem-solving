#include<iostream>
#include<algorithm>

using namespace std;
#define N 9

pair<int, char> C[N];

bool check( pair<int, char> c1, pair<int, char> c2, pair<int, char> c3){
    if ( !(c1.second == c2.second && c2.second == c3.second) ) return false;

    if ( c1.first == c2.first && c2.first == c3.first ) return true;

    int v[3];
    v[0] = c1.first;
    v[1] = c2.first;
    v[2] = c3.first;

    sort( v, v+3);
    for ( int i = 0; i < 2; i++ ){
	if ( v[i] != v[i+1]-1 ) return false;
    }
    return true;
}

bool judge(){
    for ( int i = 0; i < N; i++ ) cin >> C[i].first;
    for ( int i = 0; i < N; i++ ) cin >> C[i].second;

    int P[N];
    for ( int i = 0; i < N; i++ ) P[i] = i;

    do{
	if ( check( C[P[0]], C[P[1]], C[P[2]] ) &&
	     check( C[P[3]], C[P[4]], C[P[5]] ) &&
	     check( C[P[6]], C[P[7]], C[P[8]] ) ) return true;
    } while( next_permutation(P, P+N));
    return false;
}

int main(){
    int tcase;
    cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	if ( judge() ) cout << "1" << endl;
	else cout << "0" << endl;
    }
    return 0;
}
