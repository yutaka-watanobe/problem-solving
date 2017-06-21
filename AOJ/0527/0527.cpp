#include<iostream>
#include<vector>
using namespace std;
#define MAX 100000
int n, G[MAX];

void simulate(){
    vector<pair<int, int> > S;
    S.push_back(make_pair(G[0], 1));

    for ( int i = 1; i < n; i++ ){
	if ( (i+1) % 2 ){
	    if ( G[i] == S.back().first ) S.back().second++;
	    else S.push_back(make_pair(G[i], 1));
	} else {
	    if ( G[i] == S.back().first ) S.back().second++;
	    else {
		S.back().first = G[i];
		S.back().second++;
	    }
	}
	
	while( S.size() >= 2 ){
	    if ( S[S.size()-2].first == S[S.size()-1].first ){
		S[S.size()-2].second += S[S.size()-1].second;
		S.resize(S.size()-1);
	    } else break;
	}
    }
    int cnt = 0;
    for ( int i = 0; i < S.size(); i++ ){
	if ( S[i].first == 0 ) cnt += S[i].second;
    }
    cout << cnt << endl;
}

main(){

    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ) cin >> G[i];
	simulate();
    }
}
