#include<iostream>
#include<vector>
using namespace std;

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


vector<Segment> generalize(vector<Segment> v ){
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

int main(){

    int s, t;
    vector<Segment> v;

    while( 1 ){
	cin >> s >> t;
	if ( s == 0 && t == 0 ) break;
	v.push_back(Segment(s, t));
    }

    sort ( v.begin(), v.end() );

    for ( int i = 0; i < v.size(); i++ ) cout << v[i].s << "," << v[i].t << " ";
    cout << endl;

    v = generalize(v);

    for ( int i = 0; i < v.size(); i++ ) cout << v[i].s << "," << v[i].t << " ";
    cout << endl;



    return 0;
}

