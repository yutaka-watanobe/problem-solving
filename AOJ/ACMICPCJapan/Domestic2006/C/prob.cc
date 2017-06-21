#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<cassert>

#define MAX_SIZE 10
#define MAX_STONE 105

using namespace std;

class Point{
public:
  int r, c;
  
  Point(){}
  Point(int r, int c){}
  
  bool isAdj(const Point &p) {
    static int dr[]={0,1,1,0,-1,-1}, dc[]={-1,-1,0,1,1,0};

    for(int i=0;i<6;i++)
      if(r+dr[i]==p.r && c+dc[i]==p.c) return true;
    
    return false;
  }
  
  bool operator< (const Point &p) const {
    if(r==p.r) return c<p.c;
    return r<p.r;
  }
  
  bool operator== (const Point &p) const {
    return (r==p.r && c==p.c);
  }
};

class State{
public:
  int n;
  Point p[MAX_SIZE];

  State(){}
  
  bool operator< (const State &s) const {
    for(int i=0;i<n;i++){
      if(p[i]==s.p[i]) continue;
      return (p[i]<s.p[i]);
    }
    return false;
  }
};

int nBody, nStone;
Point body[MAX_SIZE], stone[MAX_STONE], goal;

bool read(){
  cin >> nBody;
  if(nBody==0) return false;

  for(int i=0;i<nBody;i++)
    cin >> body[i].r >> body[i].c;

  cin >> nStone;
  for(int i=0;i<nStone;i++)
    cin >> stone[i].r >> stone[i].c;
  
  cin >> goal.r >> goal.c;
  
  return true;
}

bool onStone(Point &p){
  for(int i=0;i<nStone;i++)
    if(p==stone[i]) return true;
  return false;
}

void makeNext(int id, State &curr, set<State> &next, bool moved, int add){
  if(add== 1 && id==nBody) return;
  if(add==-1 && id==-1) return;

  const static int dr[]={0,1,1,0,-1,-1}, dc[]={-1,-1,0,1,1,0};  
  
  State nextS = curr;
  nextS.n = curr.n;
  for(int i=0;i<nBody;i++)
    nextS.p[i] = curr.p[i];
  
  if(!moved){
    for(int i=0;i<6;i++){
      Point nextP = curr.p[id];
      
      nextP.r += dr[i];
      nextP.c += dc[i];
    
      bool valid = true;

      for(int j=0;j<nBody;j++){
	if(j==id) continue;
	else if(onStone(nextP)){
	  valid = false;
	  break;
	}
	else if(nextP==curr.p[j]){ // kininaru
	  valid = false;
	  break;
	}
	else if(abs(j-id)==1){
	  if(!nextP.isAdj(curr.p[j])){ 
	    valid = false;
	    break;
	  }
	}
	else{
	  if(nextP.isAdj(curr.p[j])){ 
	    valid = false;
	    break;
	  }
	}
      }
    
      if(!valid) continue;
    
      nextS.p[id] = nextP;
      next.insert(nextS);
      makeNext(id+add,nextS,next,true,add);
    }
  }
  makeNext(id+add,curr,next,false,add);
}

int bfs(){
  const static int dr[]={0,1,1,0,-1,-1,0}, dc[]={-1,-1,0,1,1,0,0};  
  State init;
  queue<State> Q;
  map<State,int> M;
  
  init.n = nBody;
  for(int i=0;i<nBody;i++)
    init.p[i] = body[i];
  
  Q.push(init);
  M[init] = 0;
  
  while(!Q.empty()){
    State curr = Q.front();
    Q.pop();
    
        
    int currCost = M[curr];
    
    /*
    cout << "curr " << currCost << endl;
    for(int i=0;i<nBody;i++)
      cout << curr.p[i].r << ',' << curr.p[i].c << endl;
    cout << endl;
    */

    if(curr.p[0]==goal)
      return currCost;
    
    if(currCost==20) continue;
    
    set<State> next;
    makeNext(0,curr,next,false,1);
    makeNext(nBody-1,curr,next,false,-1);

    for(set<State>::iterator i=next.begin();i!=next.end();i++){
      if(M.count(*i)==0 || M[*i]>currCost+1){
	M[*i] = currCost+1;
	Q.push(*i);
	/*
	cout << "next" << endl;
	for(int j=0;j<nBody;j++)
	  cout << i->p[j].r << ',' << i->p[j].c << endl;
	cout << endl;      
	*/
      }
    }
    
  }
  
  assert(false);
  return -1;
}

void work(){
  cout << bfs() << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
