// Problem B: Osaki
// @author yutaka
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10000
#define ARRIVAL 0
#define DEPARTURE 1

class Event{
    public:
    int etime, state;
    Event(){}
    Event( int etime, int state): etime(etime), state(state){}
    bool operator < ( const Event &e ) const{
	if ( etime == e.etime ) return state < e.state;
	else return etime < e.etime;
    }
};

int N;
Event E[MAX*2];

void compute(){
    sort( E, E + 2*N );
    int ntrain = 0;
    int maxt = 0;
    for ( int i = 0; i < 2*N; i++ ){
	if ( E[i].state == ARRIVAL ) ntrain--;
	else ntrain++;
	maxt = max( maxt, ntrain);
    }
    cout << maxt << endl;
}

bool input(){
    cin >> N;
    if ( N == 0 ) return false;
    int h, m, s, hh, mm, ss;
    char ch;
    for ( int i = 0; i < 2*N;  ){
	cin >> h >> ch >> m >> ch >> s;
	cin >> hh >> ch >> mm >> ch >> ss;
	E[i++] = Event( h*3600 + 60*m + s, DEPARTURE );
	E[i++] = Event( hh*3600 + 60*mm + ss, ARRIVAL );
    }
    return true;
}

main(){
    while( input() ) compute();
}

