// @JUDGE_ID:  17051CA  754  C++
// @begin_of_source_code
#include<stdio.h>
#include<cmath>
#include<stl.h>
#include<vector>
#include<queue>
#include<float.h>
#define EPS 0.0000001
#define deq(a, b) (fabs(a-b) < EPS)
#define MAX 31

class graph {
 public:
  vector<vector<int> > adj;
  vector<vector<int>::iterator> pos;
  
  graph(){}
  graph( int n ){ resize(n); }

  void resize( int n ){
    adj.resize(n), pos.resize(n); 
    for( int i = 0; i < n; i++ ){
      adj[i].clear();
    }
  }

  int size(){ return adj.size(); }

  void insert( int i, int j ){
    adj[i].push_back(j);
  }
  
  int next( int i ){ 
    if( pos[i] == adj[i].end() ) return -1;
    return *pos[i]++; 
  }
  
  void reset(int i){ pos[i] = adj[i].begin(); }
  void reset(){ for( int i = 0; i < size(); i++) reset(i); }

  void clear(){ adj.clear(), pos.clear(); }
};

class point{
 public:
  double x, y;
  point(){}
  point(double x, double y): x(x), y(y){}

  bool operator < ( const point &p ) const{
    if ( deq( x, p.x ) ){
      return y < p.y;
    } else {
      return x < p.x;
    }
  }
};

class segment{
 public:
  point p1, p2;
  segment(){}
  segment( point p1, point p2 ): p1(p1), p2(p2){}
};

bool isParallel(point p1, point p2, point p3, point p4){
  double dx1, dx2, dy1, dy2;
  dx1 = p2.x - p1.x;
  dy1 = p2.y - p1.y;
  dx2 = p4.x - p3.x;
  dy2 = p4.y - p3.y;
  return dy1*dx2 == dy2*dx1;
}
/*
 * 重なる場合は 0 を返す
 */
int direction(point pi, point pj, point pk){
  /* (pk - pi)*(pj - pi) */
  return (int)((pk.x - pi.x)*(pj.y - pi.y) - (pj.x - pi.x)*(pk.y - pi.y));
}

bool on_segment(point pi, point pj, point pk){
  if( min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
      min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)) return true;
  else return false;
}

/**
 * segment が intersect するか否か？
 * Solved 273, 191
 */
int segments_intersect(const point &p1, const point &p2, 
		 const point &p3, const point &p4){
  int d1, d2, d3, d4;
  bool on1, on2, on3, on4;

  d1 = direction(p3, p4, p1);
  d2 = direction(p3, p4, p2);
  d3 = direction(p1, p2, p3);
  d4 = direction(p1, p2, p4);

  on1 = on_segment(p3, p4, p1);
  on2 = on_segment(p3, p4, p2);
  on3 = on_segment(p1, p2, p3);
  on4 = on_segment(p1, p2, p4);

  if( ((d1>0 && d2<0)||(d1<0 && d2>0)) &&
      ((d3>0 && d4<0)||(d3<0 && d4>0)) ) return true;
  else if( d1==0 && on1 ) return true;
  else if( d2==0 && on2 ) return true;
  else if( d3==0 && on3 ) return true;
  else if( d4==0 && on4 ) return true;
  else return false;
}


/*
 線分 s との交点を返す.
 線分 s と交わり, 平行でないことを確かめて実行すること.
 交わっていない場合も延長線上の交点を返す。
 Computational Geometry in C
 Solved 10406*/
bool intersection( segment seg1, segment seg2, point &ip ){
  point p1, p2, p3, p4;
  p1 = seg1.p1;
  p2 = seg1.p2;
  p3 = seg2.p1;
  p4 = seg2.p2;

  if ( isParallel( p1, p2, p3, p4 ) ) return false;

  double num, denom, r;
  
  num = (p1.y - p3.y) * (p4.x - p3.x)
    - (p1.x - p3.x) * (p4.y - p3.y);
  denom = (p2.x - p1.x) * (p4.y - p3.y)
    - (p2.y - p1.y) * (p4.x - p3.x);
  
  assert( ! deq(denom, 0) );
  r = num / denom;
  
  ip = point(p1.x + r*(p2.x - p1.x), p1.y + r*(p2.y - p1.y));

  if ( (0 < ip.x && ip.x < 100 || deq( ip.x, 0 ) || deq( ip.x, 100 )) &&
       (0 < ip.y && ip.y < 100 || deq( ip.y, 0 ) || deq( ip.y, 100 )) ){
    return true;
  } else {
    return false;
  }
}

class Door{
 public:
  point pos;
  int wallID;

  Door(){}
  Door( point pos, int wallID ): pos(pos), wallID(wallID){}
};

class TreasureHunt{
 public:
  int nwall;
  segment W[ MAX ]; /* wall */
  vector<Door> D;
  segment left, right, top, bottom;
  point treasure;

  graph g;

  void createDoors(){
    D.clear();

    for ( int current = 0; current < nwall; current++ ){
      vector<point> intersected;
      
      for ( int target = 0; target < nwall; target++ ){
	if ( current == target ) continue;
	
	point ip;
	if ( intersection( W[current], W[target], ip ) ){
	  intersected.push_back( ip );
	}
      }

      sort( intersected.begin(), intersected.end() );

      for ( int i = 1; i < intersected.size(); i++ ){
	point p1 = intersected[i-1];
	point p2 = intersected[i];

	Door d = Door( point( (p1.x + p2.x)/2, (p1.y + p2.y)/2 ), current );
	D.push_back( d );
      }

    }
  }

  bool connectable( point p1, point p2, int id1, int id2 ){
    for ( int i = 0; i < nwall; i++ ){
      if ( i == id1 || i == id2 ) continue;
      if ( segments_intersect( p1, p2, W[i].p1, W[i].p2 ) ) return false;
    }
    return true;
  }

  void createGraph(){
    g.clear();
    g = graph( D.size() + 1 ); /* 0 -> treasure */

    for ( int i = 0; i < D.size() - 1; i++ ){
      for ( int j = i + 1; j < D.size(); j++ ){
	if ( connectable( D[i].pos, D[j].pos, D[i].wallID, D[j].wallID ) ){
	  g.insert( i+1, j+1 );
	  g.insert( j+1, i+1 );
	}
      }
    }

    for ( int i = 0; i < D.size(); i++ ){
      if ( connectable( treasure, D[i].pos, D[i].wallID, -1 ) ){
	g.insert( 0, i+1 );
	g.insert( i+1, 0 );
      }
    }

  }
  
  int bfs(){
    vector<int> d;
    queue<int> q;
    int u, v;
    
    d.resize(g.size(), 0);
    
    q.push(0);
    d[0] = 1;

    g.reset();
    
    while ( !q.empty() ){
      u = q.front(), q.pop();
      if ( D[ u - 1 ].wallID < 4 ) return d[u] - 1;
      while( ( v = g.next(u) ) != -1 ){
	if( !d[v] ){
	  d[v] = d[u] + 1;
	  q.push( v );
	}
      }
    }
    assert( false );
  }

  void work(){
    createDoors();
    createGraph();

    cout << "Number of doors = " << bfs() << endl;
  }

  void read(){
    cin >> nwall;
    nwall += 4; /* for out-side */

    left = segment( point( 0, 0 ), point( 0, 100 ) );
    top = segment( point( 0, 100 ), point( 100, 100 ) );
    right = segment( point( 100, 100 ), point( 100, 0 ) );
    bottom = segment( point( 100, 0 ), point( 0, 0 ) );

    W[0] = left;
    W[1] = top;
    W[2] = right;
    W[3] = bottom;

    point p1, p2;
    for ( int i = 4; i < nwall; i++ ){
      cin >> p1.x >> p1.y >> p2.x >> p2.y;
      W[ i ] = segment( p1, p2 );
    }
    
    cin >> treasure.x;
    cin >> treasure.y;
  }
};

main(){
  TreasureHunt TH;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    if ( i ) cout << endl;
    TH.read();
    TH.work();
  }
}

// @end_of_source_code


