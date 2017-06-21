#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
using namespace std;

#define MAX 10000
#define BEGIN 0
#define END 1

class Segment{
    public:
    int s, t;
    Segment(){}
    Segment( int s, int t ): s(s), t(t){}

    bool operator < ( const Segment &seg ) const{
	if ( s == seg.s ) return t < seg.t;
	return s < seg.s;
    }
};

class Sheet{
    public:
    int x1, y1, x2, y2;
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
	if ( x == e.x ) return id < e.id;
	return x < e.x;
    }
};


int n, ne;
Sheet S[MAX];
Event E[2*MAX+1];

set<int> cur;
vector<Segment> pres;

set<int>::iterator it;
int prex;

vector<Segment> generalize(vector<Segment> v ){
    sort( v.begin(), v.end() );
    if ( v.size() <= 1 ) return v;
    vector<Segment> nv;

    Segment cur = v[0];
    int s = cur.s;
    int t = cur.t;

    for ( int i = 1; i < v.size(); i++ ){
	if ( v[i].s > t ){
	    nv.push_back(Segment(s, t));
	    cur = v[i];
	    s = cur.s; t = cur.t;
	} else {
	    t = max( t, v[i].t );
	}
    }
    nv.push_back(Segment(s, t));

    return nv;
}

vector<Segment> generalize2(set<int> v ){
    vector<Segment> nv;
    it = v.begin();
    Segment curseg = Segment(S[*it].y1, S[*it].y2);

    if ( v.size() <= 1 ){
	nv.push_back(curseg); return nv;
    }

    int s = curseg.s;
    int t = curseg.t;
    it++;
    for ( ; it != v.end(); it++ ){
	if( S[*it].y1 > t ){
	    nv.push_back(Segment(s, t));
	    curseg = Segment(S[*it].y1, S[*it].y2);
	    s = curseg.s; t = curseg.t;
	} else {
	    //	    t = max( t, S[*it].y2 );
	    if ( t < S[*it].y2 ) t = S[*it].y2;
	}
    }
    nv.push_back(Segment(s, t));

    return nv;
}


void compute( int x, vector<Segment> p, vector<Segment> u, int &a, int &v, int &h ){
    for ( int i = 0; i < p.size(); i++ ){
	Segment seg = p[i];
	a += (x-prex)*(seg.t-seg.s);
    }

}

void sweep(){
    int area = 0, vertical = 0, horizon = 0;
    
    cur.clear();
    pres.clear();
    prex = 0;

    int preT = -1, preB = INT_MAX;

    E[ne] = Event(-1, -1, 10001);
    
    int e = 0;
    int x;
    prex = E[0].x;
    int top, bottom;

    int maxv = 0;
    while( e < ne ){
	while(1){
	    Event ev = E[e];
	    if ( ev.mode == BEGIN ) cur.insert( ev.id );
	    else cur.erase( ev.id );
	    x = ev.x;
	    if ( E[e+1].x != E[e].x ){ e++;  break;}
	    else e++;
	}
	
	top = -1;
	bottom = INT_MAX;
	maxv = max( maxv, (int)cur.size());
	vector<Segment> curs;
	for ( it = cur.begin(); it != cur.end(); it++ ){
	    top = max( top, S[(*it)].y2);
	    bottom = min( bottom, S[(*it)].y1);
	    //	    cout << (*it) << " ";
	    //	    curs.push_back(Segment( S[(*it)].y1, S[(*it)].y2));
	}

		cout << top << "-->" << bottom << endl;

	//	cout << endl;
	//	curs = generalize(curs);
	//	for ( int i = 0; i < curs.size(); i++ ){
	    //	    cout << curs[i].s << "-" << curs[i].t << "  ";
	//	}
	//	cout << endl;

	//	compute(x, pres, curs, area, vertical, horizon);

	area += (x-prex)*(preT-preB);
	preT = top;
	preB = bottom;
	pres = curs;
	prex = x;

    }

    cout << maxv << " " << area << " " << vertical << " " << horizon << endl;

}

int main(){
    int r;
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
