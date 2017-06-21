#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<cassert>
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
using namespace std;

#define MAX 10000
#define BEGIN 1
#define END 0

class Sheet{
    public:
    int x1, y1, x2, y2, mode;
    Sheet(){}
    Sheet(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2){}

    bool operator < ( const Sheet &s ) const {
	if ( x1 == s.x1 ) return y1 < s.y1;
	return x1 < s.x1;
    }
};

class Event{ 
    public:
    int id, mode, x;
    Event(){}
    Event( int id, int mode, int x): id(id), mode(mode), x(x){}

    bool operator < ( const Event &e ) const{
	if ( x == e.x ) return mode > e.mode;
	return x < e.x;
    }
};

int n, ne;
Sheet S[2*MAX+1];
Event E[2*MAX+1];

int prex;
int r;

int getHeight( multiset<pair<int, int> > &seg, int &group ){
    group = 1;
    if ( seg.size() == 0 ) return 0;
    int w = 0;
    int s, t;
    multiset<pair<int, int> >::iterator it = seg.begin();
    s = (*it).first;
    t = (*it).second;
    it++;
    for (; it != seg.end(); it++ ){
	if ( (*it).first > t ){
	    w += (t - s);
	    s = (*it).first;
	    t = (*it).second;
	    group++;
	} else {
	    t = max( t, (*it).second);
	}
    }
    w += (t - s);
    return w;
}

void sweep(){
    int area = 0, vertical = 0, horizon = 0;
    multiset< pair<int, int> > wid;
    int height = 0, preH = 0;

    E[ne] = Event(-1, -1, 10001);

    int prex = E[0].x;
    int group = 0;    
    for ( int e = 0; e < ne; e++ ){
	Event ev = E[e];
	area += (ev.x - prex)*height;
	horizon += (ev.x - prex)*2*group;

	if ( ev.mode == BEGIN ) wid.insert( make_pair( S[ev.id].y1, S[ev.id].y2) );
	else  wid.erase( wid.find(make_pair( S[ev.id].y1, S[ev.id].y2)) );

	preH = height;
	prex = ev.x;

	height = getHeight(wid, group);

	if ( ev.mode == BEGIN ) vertical += height - preH;
	else  vertical += preH - height;
    }

    cout << area << endl;
    if ( r == 2 ) cout << vertical + horizon << endl;
}

int main(){
    while(1){
	scanf("%d %d", &n, &r);
	if ( n == 0 && r == 0) break;
	ne = 0;
	rep(i, n){
	    scanf("%d %d %d %d", &S[i].x1, &S[i].y1, &S[i].x2, &S[i].y2);
	}

	sort( S, S+n);

	rep(i, n){
	    E[ne++] = Event(i, BEGIN, S[i].x1);
	    E[ne++] = Event(i, END, S[i].x2);
	}
	sort( E, E + ne );
	sweep();
    }
    return 0;
}
