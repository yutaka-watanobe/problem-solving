#include<iostream>
using namespace std;

#define MAX 28
int n;

pair<char, char> P[MAX];
bool used[MAX];


bool recursive( int p, int pre ){
    if ( p == n ) return true;


    for ( int i= 0; i < n; i++ ){
	if ( used[i] ) continue;

	if ( pre == P[i].first || pre == -1){
	    used[i] = true;
	    if ( recursive( p+1, P[i].second) ) return true;
	    used[i] = false;
	}

	if ( pre == P[i].second || pre == -1){
	    used[i] = true;
	    if ( recursive( p+1, P[i].first) ) return true;
	    used[i] = false;
	}
    }

    return false;
}

int main(){
    char s, t;
    while( cin >> n ){
	for ( int i = 0; i < n; i++ ){
	    cin >> s >> t;
	    P[i] = make_pair(s, t);
	}
	for ( int i = 0; i < n; i++ ) used[i] = false;
	if ( recursive(0, -1) ) cout << "Yes" << endl;
	else cout << "No" << endl;
    }

    return 0;
}
