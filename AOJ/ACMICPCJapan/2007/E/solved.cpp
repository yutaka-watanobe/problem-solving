#include<iostream>
#include<vector>
#include<cfloat>
#include<map>
#include<cmath>
#include<cassert>
#define NMAX 200
#define SMAX 200
using namespace std;
#define PI 3.14159265358979323846

class Node{
public:
  int x, y;
  Node(){}
  Node(int x, int y): x(x), y(y){}
  bool operator < ( const Node &n ) const{
    if ( x == n.x ) return y < n.y;
    else return  x < n.x;
  }
  void print(){
    cout << "(" << x << "," << y << ")";
  }
};

class Segment{
public:
  Node n1, n2;
  Segment(){}
  Segment(Node n1, Node n2): n1(n1), n2(n2){}
};

int nline, nload, nsign, nnode;
Node nodes[NMAX];
Segment S[SMAX], loads[SMAX], signs[SMAX];
double G[NMAX][NMAX];
//#define INFTY (1<<21)
#define INFTY FLT_MAX
map<Node, int> NM; // node to index

double getDist( Node p1, Node p2 ){
  return sqrt( (double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

bool onSegment(Node p1, Node p2, Node p3 ){
  double dx1 = p2.x - p1.x;
  double dy1 = p2.y - p1.y;
  double dx2 = p3.x - p1.x;
  double dy2 = p3.y - p1.y;
  return ( dx2*dy1 == dx1*dy2 &&
	   min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) &&
	   min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y));

}

bool onLoad(Node p1, Node p2 ){
  for ( int i = 0; i < nload; i++ ){
    if ( onSegment(loads[i].n1, loads[i].n2, p1 ) &&
	 onSegment(loads[i].n1, loads[i].n2, p2 ) ) return true;
  }
  return false;
} 

double getTheta(Node p1, Node p2, Node o ){
  p1.x -= o.x; p2.x -= o.x;
  p1.y -= o.y; p2.y -= o.y;
  return acos((p1.x*p2.x + p1.y*p2.y )/(sqrt(1.0*p1.x*p1.x+p1.y*p1.y)*sqrt(1.0*p2.x*p2.x+p2.y*p2.y)));
}

bool onSign(Node p1, Node p2 ){
  for ( int i = 0; i < nsign; i++ ){
    if ( onSegment(p1, p2, signs[i].n1 ) && getTheta(signs[i].n2, p2, signs[i].n1) <= PI/2 ||
	 onSegment(p1, p2, signs[i].n2 ) && getTheta(signs[i].n1, p2, signs[i].n2) <= PI/2 ) return true;
  }
  return false;
}

void addNode( Node node ){
  if ( NM.find(node) == NM.end()  ){
    NM[node] = nnode;
    nodes[nnode++] = node;
  }
}

void makeGraph(){
  bool isTouch1, isTouch2;
  nload = nsign = 0;
  for ( int s = 0; s < nline; s++ ){
    isTouch1 = isTouch2 = false;
    for ( int t = 0; t < nline; t++ ){
      if ( t == s ) continue;
      if ( onSegment(S[t].n1, S[t].n2, S[s].n1 ) ) isTouch1 = true;
      if ( onSegment(S[t].n1, S[t].n2, S[s].n2 ) ) isTouch2 = true;
    }
    if ( isTouch1 && isTouch2 ){
      addNode( S[s].n1 ); addNode( S[s].n2 );
      loads[nload++] = S[s];
    } else signs[nsign++] = S[s];
  }

  //  cout << "nodes" << endl;
  //  for ( int i = 0; i < nnode; i++ ) {nodes[i].print(); cout << endl;}
  /*
  cout << "loads" << endl;
  for ( int i = 0; i < nload; i++ ){
    loads[i].n1.print();    loads[i].n2.print(); cout << endl;
  }
  cout << "signs" << endl;
  for ( int i = 0; i < nsign; i++ ){
    signs[i].n1.print();    signs[i].n2.print(); cout << endl;
  }
  */

  for ( int i = 0; i < nnode; i++ ){
    for ( int j = 0; j < nnode; j++ ) G[i][j] = INFTY;
  }

  for ( int i = 0; i < nnode; i++ ){
    for ( int j = 0; j < nnode; j++ ){
      if ( i == j ) continue;
      if ( onLoad(nodes[i], nodes[j] ) && !onSign(nodes[i], nodes[j]) ){
	G[i][j] = getDist( nodes[i], nodes[j] );
	//		nodes[i].print();
	//		nodes[j].print();
	//		cout << G[i][j] << endl;
      }
    }
  }
  // generalize
  bool changed = true;
  while(changed){
    changed = false;
    for ( int i = 0; i < nnode; i++ ){
      for ( int j = 0; j < nnode; j++ ){
	for ( int k = 0; k < nnode; k++ ){
	  if ( G[i][j] != INFTY && onSegment(nodes[i], nodes[j], nodes[k]) &&
	       G[i][k] != INFTY && G[k][j] != INFTY ){
	    //	    cout << G[i][j] << "  " << G[i][k] + G[k][j] << endl;
	    //	    cout << fabs(G[i][j] - (G[i][k]+G[k][j])) << endl;
	    //	    assert(fabs(G[i][j] - (G[i][k]+G[k][j])) <= 0.0000001);
	    G[i][j] = INFTY;
	    changed = true;
	    goto next;
	  }
	}
      }
    }
  next:;
  }


}

void parse( int P[], int u ){
  //  if ( u == -1 ) return;
  //  parse( P, P[u] );
  //  cout << nodes[u].x << " " << nodes[u].y << endl;

  if ( P[u] != -1 ) parse(P, P[u] );
  cout << nodes[u].x << " " << nodes[u].y << endl;
}

void dijkstra(){
  double D[NMAX];
  bool V[NMAX];
  int P[NMAX];
  for ( int i = 0; i < nnode; i++ ){
    D[i] = INFTY;
    V[i] = false;
  }

  P[0] = -1;
  D[0] = 0.0;
  int u;
  while(1){
    double minv = INFTY;
    for ( int i = 0; i < nnode; i++ ){
      if ( !V[i] && D[i] < minv ){
	minv = D[i];
	u = i;
      }
    }
    //    cout << minv << endl;
    if ( minv == INFTY ) break;
    V[u] = true;

    for ( int v = 0; v < nnode; v++ ){
      if ( G[u][v] == INFTY || V[v] ) continue;
      if ( D[v] > D[u] + G[u][v] ){
	D[v] = D[u] + G[u][v];
	P[v] = u;
      }
    }
  }

  //  for ( int i = 0; i < nnode; i++ ){
  //    cout << D[i] << endl;
  //  }
  //  cout << "parse" << endl;
  if ( D[1] == INFTY ) cout << "-1" << endl;
  else {
    parse( P, 1 );
    cout << 0 << endl;
  }
}

main(){
  int x1, y1, x2, y2;
  while( cin >> nline, nline ){
    nnode = 0;
    NM = map<Node, int>();
    cin >> x1 >> y1; addNode(Node(x1, y1));
    cin >> x1 >> y1; addNode(Node(x1, y1));
    for ( int i = 0; i < nline; i++ ){
      cin >> x1 >> y1 >> x2 >> y2;
      S[i] = Segment( Node(x1, y1), Node(x2, y2) );
    }
    makeGraph();
    dijkstra();
  }
}
