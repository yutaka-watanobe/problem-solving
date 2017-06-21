// @JUDGE_ID:  17051CA  10496  C++
// @begin_of_source_code
/* Grid */
/* ¡Ì≈ˆ§ø§Í */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

class Point{
 public:
  int x, y;
  Point(){}
  Point(int x, int y): x(x), y(y){}
};

int X, Y;
int sx, sy;
int n;
int shortest;
vector<Point> p;

int read(){
  cin >> X >> Y;
  cin >> sx >> sy;
  cin >> n;
  p.clear();
  int a, b;
  for(int i=0; i<n ;i++){
    cin >> a >> b;
    p.push_back(Point(a, b));
  }
}

int getDist(Point p1, Point p2){
  return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

void collect(vector<int> perm){

  int dist = 0;
  for(int i=0; i<n-1; i++){
    dist += getDist(p[perm[i]], p[perm[i+1]]);
    if(dist>shortest) return;
  }
  dist += getDist(p[perm[0]], Point(sx, sy));
  dist += getDist(Point(sx, sy), p[perm[n-1]]);

  if(shortest>dist) shortest = dist;
}

void work(){
  vector<int> perm;
  perm.resize(n);
  for(int i=0; i<n; i++) perm[i] = i;

  shortest = INT_MAX;

  do{
    if(perm[0] <= perm[n-1]){
      collect(perm);
    }
  }while(next_permutation(perm.begin(), perm.end()));

  cout << "The shortest path has length " << shortest << endl;

}

main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    read();
    work();
  }
}
// @end_of_source_code
