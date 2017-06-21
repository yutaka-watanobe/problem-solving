#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define OUT 0
#define IN 1
#define MAX 100

class Event{
    public:
    int id, type, t;
    Event(int id=0, int type=0, int t=0):id(id), type(type), t(t){}
    bool operator < ( const Event &e) const{
	if ( t == e.t ) return type < e.type;
	return t < e.t;
    }
};

main(){
    int s = 150, n, a, b, M[MAX];
    
    while( cin >> n && n ){
	Event events[MAX*2];
	int ne = 0;
	for ( int i = 0; i < n; i++ ){
	    cin >> M[i] >> a >> b;
	    events[ne++] = Event(i, IN, a);
	    events[ne++] = Event(i, OUT, b);
	}

	sort(events, events + ne);

	bool fail = false;
	int cur = 0;

	for ( int i = 0; i < ne; i++){
	    if ( events[i].type == OUT ) cur -= M[events[i].id];
	    if ( events[i].type == IN )  cur += M[events[i].id];
	    if ( cur > s ) fail = true;
	}

	if ( fail ) cout << "NG" << endl;
	else cout << "OK" << endl;
    }
}
