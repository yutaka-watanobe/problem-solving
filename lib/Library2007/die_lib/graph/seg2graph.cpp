// Convert set of segment to graph
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Point{
public:
  double x, y;

  bool operator<(const Point &p) const;
  bool operator==(const Point &) const;
  bool operator!=(const Point &) const;
  
};

class Segment{
public:
  Point p, q;
};

bool isIntersectSS(const Segment &, const Segment &, Point &);


const int GMAX = 100;


vector<Segment> segments;
map<Point, int> id;
int nv;
bool g[GMAX][GMAX];


void assignID(const Point &p){
  if(id.find(p) == id.end())
    id[p] = nv++;
}

void makeGraph(void){
  for(int i = 0; i < nv; ++i)
    fill(g[i], g[i]+nv, false);

  for(int i = 0; i < segments.size(); ++i){
    int f = id[segments[i].p], t = id[segments[i].q];
    g[f][t] = g[t][f] = true;
  }
}

// O(n^2)
void addSegment(const Segment &s){
  vector<Point> vertices;
  vertices.push_back(s.p);
  vertices.push_back(s.q);
  assignID(s.p);
  assignID(s.q);

  // divide existing segments
  Point p;
  for(int i = 0; i < segments.size(); ++i){
    if(isIntersectSS(s, segments[i], p)){ // [notice] s and segments[i] are not pararell
      if(segments[i].p != p && segments[i].q != p){
        // divide segments[i]
        Segment newSegment;
        newSegment.q = segments[i].q;
        segments[i].q = newSegment.q = p;
        segments.insert(segments.begin() + i+1, newSegment);
      }
      vertices.push_back(p);
      assignID(p);
    }
  }

  // add new segments
  sort(vertices.begin(), vertices.end());
  for(int i = 0; i < vertices.size()-1; ++i){
    if(vertices[i] != vertices[i+1]){
      Segment newSegment;
      newSegment.p = vertices[i], newSegment.q = vertices[i+1];
      segments.push_back(newSegment);
    }
  }
}

void init(void){
  nv = 0;
  segments.clear();
  id.clear();
}

int main(void){
  return 0;
}
