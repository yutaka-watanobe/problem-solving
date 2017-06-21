#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)

class Point{
    public:
    int x, y, z;
    Point(int x=0, int y=0, int z=0):x(x), y(y), z(z){}
    bool operator < ( const Point &p) const{
	if ( x != p.x ) return x < p.x;
	if ( y != p.y ) return y < p.y;
	if ( z != p.z ) return z < p.z;
	return false;
    }
    bool operator == ( const Point &p ) const {
	return x == p.x && y == p.y && z == p.z;
    }
};

class Edge{
    public:
    Point p[2];
    Edge(){}
    Edge(Point p1, Point p2){
	p[0] = p1; p[1] = p2; sort(p, p+2);
    }
    bool operator < ( const Edge &e ) const{
	if ( !(p[0] == e.p[0]) ) return p[0] < e.p[0];
	if ( !(p[1] == e.p[1]) ) return p[1] < e.p[1];
	return false;
    }
};

class Key{
    public:
    set<Edge> E;
    vector<Edge> EV;
    Key(){}
    void make( int n ){
	string com;
	E.clear();
	Point pre = Point(0, 0, 0);
	bool V[60];
	rep(i, 60) V[i] = false;
	Point L[60];
	rep(i, n){
	    cin >> com;
	    Point cur = pre;
	    if ( isdigit(com[0])){
		int p = atoi(com.c_str());
		if ( V[p] ){
		    pre = L[p];
		} else {
		    V[p] = true;
		    L[p] = pre;
		}
	    } else {
		if ( com == "+x" ) cur.x++;
		else if ( com == "-x" ) cur.x--;
		else if ( com == "+y" ) cur.y++;
		else if ( com == "-y" ) cur.y--;
		else if ( com == "+z" ) cur.z++;
		else if ( com == "-z" ) cur.z--;
		E.insert(Edge(pre, cur));
		pre = cur;
	    }
	}
	for ( set<Edge>::iterator it = E.begin(); it != E.end(); it++ ) EV.push_back(*it);
    }
    Point move(){
	Point p = (1000, 1000, 1000);
	for ( int i = 0; i < EV.size(); i++ ) sort(EV[i].p, EV[i].p+2);
	sort( EV.begin(), EV.end() );
	p = EV[0].p[0];

	for ( int i = 0; i < EV.size(); i++ ){
	    for ( int j = 0; j < 2; j++ ){
		EV[i].p[j].x -= p.x;
		EV[i].p[j].y -= p.y;
		EV[i].p[j].z -= p.z;
	    }
	}
    }

    void roll_x(){
	for ( int i = 0; i < EV.size(); i++ ){
	    for ( int j = 0; j < 2; j++ ){
		int tmp = EV[i].p[j].y;
		EV[i].p[j].y = EV[i].p[j].z*(-1);
		EV[i].p[j].z = tmp;
	    }
	}
    }
    void roll_y(){
	for ( int i = 0; i < EV.size(); i++ ){
	    for ( int j = 0; j < 2; j++ ){
		int tmp = EV[i].p[j].x;
		EV[i].p[j].x = EV[i].p[j].z*(-1);
		EV[i].p[j].z = tmp;
	    }
	}
    }
    void roll_z(){
	for ( int i = 0; i < EV.size(); i++ ){
	    for ( int j = 0; j < 2; j++ ){
		int tmp = EV[i].p[j].x;
		EV[i].p[j].x = EV[i].p[j].y;
		EV[i].p[j].y = tmp*(-1);
	    }
	}
    }
};

bool equals(Key key1, Key key2 ){
    for ( int i = 0; i < key1.EV.size(); i++ ) sort( key1.EV[i].p, key1.EV[i].p+2);
    sort(key1.EV.begin(), key1.EV.end());
    for ( int i = 0; i < key1.EV.size(); i++ ){
	for ( int j = 0; j < 2; j++ ){
	    if ( !(key1.EV[i].p[j] == key2.EV[i].p[j]) ) return false;
	}
    }
    return true;
}

bool check(Key key1, Key key2){
    if ( key1.EV.size() != key2.EV.size() ) return false;
    for ( int i = 0; i < key2.EV.size(); i++ ) sort( key2.EV[i].p, key2.EV[i].p+2);
    sort(key2.EV.begin(), key2.EV.end());
    key2.move();
    Key target;
    
    rep(i, 6){
	rep(j, 4){
	    target = key1;
	    target.move();
	    if ( equals(target, key2) ) return true;	    
	    key1.roll_z();
	}
	if ( i % 2 == 0 ) key1.roll_y();
	else key1.roll_x();
    }

    return false;
}

main(){
    int n;
    while(1){
	Key key1, key2;
	cin >> n;
	if ( n == 0 ) break;
	key1.make(n);
	cin >> n;
	key2.make(n);
	if ( check(key1, key2) ) cout << "SAME" << endl;
	else cout << "DIFFERENT" << endl;
    }
}
