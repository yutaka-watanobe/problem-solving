#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 10000

class Pair{
    public:
    int first, second;
    Pair(int f=0, int s=0): first(f), second(s){}

    bool operator < ( const Pair &p ) const {
	if ( first == p.first ) return second > p.second;
	return first > p.first;
    }
};

void compute(){
    int cnt = 0;
    int n; cin >> n;
    int f, s;
    priority_queue<Pair> PQ;

    for ( int i = 0; i < n; i++ ){
	cin >> f >> s;
	PQ.push(Pair(min(f, s), max(f,s)));
    }

    while( !PQ.empty() ){
	Pair u = PQ.top(); PQ.pop();

	if ( u.first == u.second ) continue;

	Pair v = PQ.top(); PQ.pop();

	if ( u.first == v.first && u.second == v.second ){
	    cnt++; continue;
	}

	PQ.push(Pair(u.second, v.second)); cnt++;
    }

    cout << cnt << endl;
}

main(){
    int tcase; cin >> tcase;

    for ( int t = 0; t < tcase; t++ ) compute();
}
