#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdlib>
#include<string>

using namespace std;

const double eps = 1e-08; 

class Point{
public:
  double x;
  double y;

  Point(){}

  Point(double inX,double inY){
    x = inX;
    y = inY;
  }

  ~Point(){}

  Point operator-(const Point in)const{
    Point re(x,y);
    re.x -= in.x;
    re.y -= in.y;
    return re;
  }

  Point operator+(const Point in)const{
    Point re(x,y);
    re.x += in.x;
    re.y += in.y;
    return re;
  }

  Point operator*(const Point in)const{
    Point re(x,y);
    re.x *= in.x;
    re.y *= in.y;
    return re;
  }

  Point operator*(const double t)const{
    Point re(x,y);
    re.x *= t;
    re.y *= t;
    return re;
  }

  Point operator/(const Point in)const{
    Point re(x,y);
    re.x /= in.x;
    re.y /= in.y;
    return re;
  }

  bool operator<(const Point &in)const{
    double myEps = 1e-08;
    if(!(fabs(x - in.x) < myEps))
      return x < in.x;
    if(!(fabs(y - in.y) < myEps))
      return y < in.y;
    return false;
  }
};

int n;
double d;


class Rectangle{
public:
  Point p1,p2,p3,p4;

  Rectangle(){}

  Rectangle(Point _p1,Point _p2,Point _p3,Point _p4){
    p1 = _p1;
    p2 = _p2;
    p3 = _p3;
    p4 = _p4;
  }
};


class Node{
public:
  vector<int> edge;
  vector<int> isEdgeUsed;
  vector<int> revEdge;
  Point p1,p2,p3;
  Rectangle rect;
  bool vanished;
  bool visited;
  int in;
  int num;

  Node(){
    edge.clear();
    revEdge.clear();
  }

  Node(Point _p1,Point _p2,Point _p3){
    Node();

    p1 = _p1;
    p2 = _p2;
    p3 = _p3;

    setRectangle();
    vanished = false;
    visited = false;
    in = 0;
    num = -1;
  }

  //単位法線ベクトルを求める 3番目の引数で法線ベクトルの向きが変わる。
  Point unitNormalVector(Point p1,Point p2,int manipu){
    double k;
    Point unv[2];
    
    unv[0] = Point(p1.y - p2.y,p2.x - p1.x);
    k = sqrt(1/(unv[0].x*unv[0].x + unv[0].y*unv[0].y));
    unv[0] = unv[0]*k;
    unv[1] = Point(p2.y - p1.y,p1.x - p2.x);
    k = sqrt(1/(unv[1].x*unv[1].x + unv[1].y*unv[1].y));
    unv[1] = unv[1]*k;
    
    return unv[manipu];
  }

  double distance(Point a,Point b){
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
  }

  void setRectangle(){
    Point a,b,c;
    double da = distance(p1,p2);
    double db = distance(p2,p3);
    double dc = distance(p1,p3);

    if(fabs(da - db) < eps){
      a = p2;
      b = p1;
      c = p3;
    }
    else if(fabs(da-dc) < eps){
      a = p1;
      b = p2;
      c = p3;
    }
    else{
      a = p3;
      b = p1;
      c = p2;
    }
    
    double l = sqrt( (b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y)); 
    rect.p1 = b;
    Point uv = unitNormalVector(b,c,0);

    Point temp1,temp2;

    temp1 = b+(uv*d);
    temp2 = b-(uv*d);
    if( distance(temp1,a) < distance(temp2,a))
      rect.p2 = temp1;
    else
      rect.p2 = temp2;

    temp1 = c+(uv*d);
    temp2 = c-(uv*d);
    if( distance(temp1,a) < distance(temp2,a))
      rect.p3 = temp1;
    else
      rect.p3 = temp2;
    
    rect.p4 = c;
  }

  bool operator<(const Node &node)const{
    if(vanished != node.vanished)
      return vanished < node.vanished;
    if(in != node.in)
       return in < node.in;
    return edge.size() > edge.size();
  }
};

class BigNode{
public:
  vector<int> innerNode;
  vector<int> edge;
  bool vanished;
  int in;

  BigNode(){
    vanished = false;
    in = 0;
  }

  bool operator<(const BigNode &bignode)const{
    if(vanished != bignode.vanished)
      return vanished < bignode.vanished;
    if(in != bignode.in)
      return in < bignode.in;
    return false;
  }
};

vector<Node> node;
vector<BigNode> bnode;


//外積
double cross(Point p1,Point p2){
  return p1.x*p2.y - p1.y*p2.x;
}

//内積
double dot(Point p1,Point p2){
  return p1.x*p2.x + p1.y*p2.y;
}

//点が線分上にあるかどうかを判定する。
bool isPointOnSegment(Point p,Point line1,Point line2)
{
  double d;
  if (line1.x > line2.x) {
    d = line2.x, line2.x = line1.x, line1.x = d;
    d = line1.y, line1.y = line2.y, line2.y = d;
  }
  return line1.x <= p.x && p.x <= line2.x && 
    ((line1.y <= line2.y && line1.y <= p.y && p.y <= line2.y) ||
     (line1.y > line2.y && line2.y <= p.y && p.y <= line1.y))
    && fabs((p.y-line1.y)*(line2.x-line1.x) - (line2.y-line1.y)*(p.x-line1.x)) < eps;
}

//線分と線分の交差判定
bool getCross(Point p1,Point p2,Point p3,Point p4){
  //端点は考慮していない。
  if(cross(p1-p2,p3-p1) * cross(p1-p2,p4-p1) < 0 &&
     cross(p3-p4,p1-p3) * cross(p3-p4,p2-p3) < 0)
    return true;
  //端点判定
  if(isPointOnSegment(p1,p3,p4) ||
     isPointOnSegment(p2,p3,p4) ||
     isPointOnSegment(p3,p1,p2) ||
     isPointOnSegment(p4,p1,p2) )
    return true;
  return false;
}
 
double getSPDistance(Point line1,Point line2,Point p){
  if ( dot(line2-line1, p-line1) < 0 )
    return sqrt( (p.x-line1.x) * (p.x-line1.x) + 
		 (p.y-line1.y) * (p.y-line1.y));
  if ( dot(line1-line2, p-line2) < 0 ) 
    return sqrt( (p.x-line2.x) * (p.x-line2.x) + 
		 (p.y-line2.y) * (p.y-line2.y));
  return fabs(cross(line2-line1, p-line1)) / sqrt((line2.x-line1.x) * (line2.x-line1.x) + (line2.y-line1.y) * (line2.y-line1.y));
}    

double distance2(Point a,Point b){
  return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool isPointIn(int a,Point p){
  return 
     ( cross(node[a].rect.p1 - p,node[a].rect.p2-p) < 0 &&
       cross(node[a].rect.p2 - p,node[a].rect.p3-p) < 0 &&
       cross(node[a].rect.p3 - p,node[a].rect.p4-p) < 0 &&
       cross(node[a].rect.p4 - p,node[a].rect.p1-p) < 0 ) || 
     ( cross(node[a].rect.p1 - p,node[a].rect.p2-p) > 0 &&
       cross(node[a].rect.p2 - p,node[a].rect.p3-p) > 0 &&
       cross(node[a].rect.p3 - p,node[a].rect.p4-p) > 0 &&
       cross(node[a].rect.p4 - p,node[a].rect.p1-p) > 0 ); 
}

bool isPointIn2(int b,Point p){
  return
    ( cross(node[b].p1-p,node[b].p2-p) < 0 &&
      cross(node[b].p2-p,node[b].p3-p) < 0 &&
      cross(node[b].p3-p,node[b].p1-p) < 0 ) ||
    ( cross(node[b].p1-p,node[b].p2-p) > 0 &&
      cross(node[b].p2-p,node[b].p3-p) > 0 &&
      cross(node[b].p3-p,node[b].p1-p) > 0 );
}

bool isConnecting(int a,int b){
  return 
    getCross( node[a].rect.p2 , node[a].rect.p1, node[b].p2 , node[b].p1) ||
    getCross( node[a].rect.p2 , node[a].rect.p1, node[b].p3 , node[b].p2) ||
    getCross( node[a].rect.p2 , node[a].rect.p1, node[b].p1 , node[b].p3) ||

    getCross( node[a].rect.p3 , node[a].rect.p2, node[b].p2 , node[b].p1) ||
    getCross( node[a].rect.p3 , node[a].rect.p2, node[b].p3 , node[b].p2) ||
    getCross( node[a].rect.p3 , node[a].rect.p2, node[b].p1 , node[b].p3) ||
    
    getCross( node[a].rect.p4 , node[a].rect.p3, node[b].p2 , node[b].p1) ||
    getCross( node[a].rect.p4 , node[a].rect.p3, node[b].p3 , node[b].p2) ||
    getCross( node[a].rect.p4 , node[a].rect.p3, node[b].p1 , node[b].p3) ||

    getCross( node[a].rect.p1 , node[a].rect.p4, node[b].p2 , node[b].p1) ||
    getCross( node[a].rect.p1 , node[a].rect.p4, node[b].p3 , node[b].p2) ||
    getCross( node[a].rect.p1 , node[a].rect.p4, node[b].p1 , node[b].p3) ||
    isPointIn(a,node[b].p1) || isPointIn(a,node[b].p2)|| isPointIn(a,node[b].p3) || isPointIn2(b,node[a].rect.p1) || isPointIn2(b,node[a].rect.p2) || isPointIn2(b,node[a].rect.p3) || isPointIn2(b,node[a].rect.p4);
}  

void makeEdge(){
  for(int i = 0;i<node.size();i++)
    for(int j = 0;j<node.size();j++)
      if(i != j && isConnecting(i,j)){
	node[i].edge.push_back(j);
	node[i].isEdgeUsed.push_back(0);
	node[j].revEdge.push_back(i);
      }
}

void test(){
  int num = 0;

  for(int i = 0;i<node.size();i++){
    cout << i << ": " << "p1 = (" << node[i].rect.p1.x << "," << node[i].rect.p1.y << "), p2 = (" << node[i].rect.p2.x << "," << node[i].rect.p2.y << "), p3 = ("  << node[i].rect.p3.x << "," << node[i].rect.p3.y << "), p4 = ("  << node[i].rect.p4.x << "," << node[i].rect.p4.y << ")" << endl;
    cout << "edge = ";
    for(int j = 0;j<node[i].edge.size();j++)
      cout << node[i].edge[j] << " ";
    cout << endl;
  }
}

int revPos;
int revMax;
int sccNum;

void revDfs(int nn, BigNode &bn){
  node[nn].vanished = true;
  bn.innerNode.push_back(nn);
  for(int i = 0;i<node[nn].revEdge.size();i++)
    if(node[node[nn].revEdge[i]].vanished == false)
      revDfs(node[nn].revEdge[i],bn);
}

void dfs(int nn){
  node[nn].visited = true;
  
  for(int i = 0;i<node[nn].edge.size();i++)
    if(node[node[nn].edge[i]].visited == false){
      dfs(node[nn].edge[i]);
    }

  node[nn].num = sccNum++;
  if(revMax < sccNum-1){
    revMax = sccNum-1;
    revPos = nn;
  }
}

int stronglyConnectedComponents(){
  int re = 0;
  sccNum = 0;

  for(int i = 0;i<node.size();i++)
    if(node[i].visited == false)
      dfs(i);

  while(true){
    bool finishFlag = true;
    for(int i = 0;i<node.size();i++)
      if(node[i].vanished == false)
	finishFlag = false;
    if(finishFlag)
      break;

    revPos = -1;
    revMax = -10;

    for(int i = 0;i<node.size();i++)
      if(revMax < node[i].num && node[i].vanished == false){
	revMax = node[i].num;
	revPos = i;
      }
    BigNode bn;
    revDfs(revPos,bn);
    bnode.push_back(bn);
  }
}

bool isEdgeExist(int a,int b){
  for(int i = 0;i<bnode[a].innerNode.size();i++)
    for(int j = 0;j<bnode[b].innerNode.size();j++){
      if(isConnecting(bnode[a].innerNode[i],bnode[b].innerNode[j])){
	return true;
      }
    }
  return false;
}

void makeBigEdge(){
  for(int i = 0;i<bnode.size();i++)
    for(int j = 0;j<bnode.size();j++)
      if(i != j && isEdgeExist(i,j)){
	bnode[i].edge.push_back(j);
	bnode[j].in++;
      }
}

void tatch(int nn){
  bnode[nn].vanished = true;

  for(int i = 0;i<bnode[nn].edge.size();i++)
    if(bnode[bnode[nn].edge[i]].vanished == false)
      tatch(bnode[nn].edge[i]);
}

int getAns(){
  int re = 0;
  
  while(true){
    bool finishFlag = true;
    for(int i = 0;i<bnode.size();i++)
      if(bnode[i].vanished == false)
	finishFlag = false;
    if(finishFlag)
      break;

    int idx = 0;
    
    for(int i = 1;i<bnode.size();i++)
      if(bnode[i] < bnode[idx])
	idx = i;

    tatch(idx);
    re++;
  }
  return re;
}

void test2(){
  for(int i = 0;i<bnode.size();i++){
    cout << i << ": ";
    for(int j = 0;j<bnode[i].innerNode.size();j++)
      cout << bnode[i].innerNode[j] << " ";
    cout << endl;
    
    cout << bnode[i].edge.size() << " : " ;
    for(int j = 0;j<bnode[i].edge.size();j++)
      cout << bnode[i].edge[j] << " ";
    cout << endl;
  }
}

 
main(){
  while(cin >> n >> d && n){
    node.clear();
    bnode.clear();
   
    double x1,y1,x2,y2,x3,y3;
    for(int i = 0;i<n;i++){
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      node.push_back(Node(Point(x1,y1),Point(x2,y2),Point(x3,y3)));
    }
    
    makeEdge();
    //test();
    stronglyConnectedComponents();
    makeBigEdge();
    //test2();
    cout << getAns() << endl;
  }
  return 0;
}
