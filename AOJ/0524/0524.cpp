#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int> > P;
set<pair<int, int> > T; // target;

int m, n;

void compute(){
    sort( P.begin(), P.end() );

    int dx, dy;

    for ( set<pair<int, int> >::iterator it = T.begin(); it != T.end(); it++ ){
	int x = (*it).first;
	int y = (*it).second;

	dx = x - P[0].first;
	dy = y - P[0].second;

	bool mutch = true;
	for ( int i = 1; i < P.size(); i++ ){
	    int tx = P[i].first + dx;
	    int ty = P[i].second + dy;

	    if ( T.find( make_pair(tx, ty) ) == T.end() ){
		mutch = false;
		break;
	    }
	}

	if ( mutch ){
	    cout << dx << "  " << dy << endl;
	    return;
	}
    }

}

int main(){
    int x, y;
    while(1){
	cin >>m;
	if ( m == 0 ) break;
	P.clear();
	T.clear();
	for ( int i = 0; i < m; i++ ){
	    cin >> x >> y;
	    P.push_back( make_pair(x, y) );
	}
	cin >> n;
	for ( int i = 0; i < n; i++ ){
	    cin >> x >> y;
	    T.insert( make_pair(x, y ) );
	}
	compute();
    }

    return 0;
}
