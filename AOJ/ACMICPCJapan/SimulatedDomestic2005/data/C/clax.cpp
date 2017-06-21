
#include<iostream>
#include<complex>

#define INF 100000000
#define MAX_SIZE 25
#define MAX_BUF ((1<<20) +5)

using namespace std;

typedef complex<double> Point;

int nDst;
Point src, devil, dst[MAX_SIZE];
double cost[MAX_BUF];

bool read(){
  int x1, y1, x2, y2;
  cin >> nDst >> x1 >> y1 >> x2 >> y2;
  if((nDst|x1|y1|x2|y2)==0) return false;
  
  src = Point(x1,y1);
  devil = Point(x2,y2);
  
  for(int i=0;i<nDst;i++){
    int x, y;
    cin >> x >> y;
    
    dst[i] = Point(x,y);
  }
  
  return true;
}

bool rec(int nVisited, double time, Point curr, bool visited[], int state){
  if(nVisited==nDst) return true;

  for(int i=0;i<nDst;i++){
    if(visited[i]) continue;
    
    int nextState = state | (1<<i);
    
    double nextTime = time+abs(curr-dst[i]);
    double nextKilled = abs(devil-dst[i]);
    
    if(nextTime>=nextKilled) break;
    if(cost[nextState]<=nextTime) break;
    
    visited[i] = true;
    cost[nextState] = nextTime;
    
    if(rec(nVisited+1,nextTime,dst[i],visited,nextState)) return true;

    visited[i] = false;
  }

  return false;
}

void work(){
  int state = 0;
  bool visited[MAX_SIZE];

  for(int i=0;i<nDst;i++)
    visited[i] = false;
  
  for(int i=0;i<MAX_BUF;i++)
    cost[i] = INF;
  
  if(rec(0,0,src,visited,state)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
