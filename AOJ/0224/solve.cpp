#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cassert>
#include<map>
#include<string>
#include<cstdlib>

using namespace std;

const int MAX_N = 6;
const int MIN_N = 1;
const int MAX_S = 100;
const int MIN_S = 1;
const int MAX_C = 5;
const int MIN_C = 1;
const int MAX_EDGE = 256;
const int MIN_EDGE = 5;
const int MAX_WAIGHT = 20;
const int MIN_WAIGHT = 1;

class Edge{
public:
  int dist;
  int waight;

  Edge(){}

  Edge(int Dist,int Waight){
    dist = Dist;
    waight = Waight;
  }
};

class Shop{
public:
  vector<Edge> randEdge;
  vector<Edge> shopEdge;
  vector<Edge> edge;
  int cal;
  bool visited;

  Shop(){}

  Shop(int Cal){
    cal = Cal;
    visited = false;
  }
};

class Randmark{
public:
  vector<Edge> randEdge;
  vector<Edge> shopEdge;
};

class State{
public:
  int nn;
  int cost;
  bool isShop;
 
  bool operator<(const State &state)const{
    if(isShop != state.isShop)
      return isShop < state.isShop;
    return nn < state.nn;
  }

  bool operator>(const State &state)const{
    return cost > state.cost;
  }
};

int n,s,c,k;
vector<Shop> shop;
vector<Randmark> mark;
int ans;

void dijkstra(int s){
  priority_queue<State,vector<State>,greater<State> > qu;
  State state,temp;
  map<State,bool> isExist;

  for(int i = 0;i<shop[s].randEdge.size();i++){
    state.isShop = false;
    state.cost = shop[s].randEdge[i].waight;
    state.nn = shop[s].randEdge[i].dist;
    qu.push(state);
  }

  for(int i = 0;i<shop[s].shopEdge.size();i++){
    state.isShop = true;
    state.cost = shop[s].shopEdge[i].waight;
    state.nn = shop[s].shopEdge[i].dist;
    qu.push(state);
  }

  while(!qu.empty()){
    state = qu.top();
    qu.pop();

    if(isExist[state] == false){
      isExist[state] = true;

      if(state.isShop && state.nn != s){
	shop[s].edge.push_back(Edge(state.nn,state.cost));

	if(state.nn == 0 || state.nn == shop.size()-1){
	  for(int i = 0;i<shop[state.nn].randEdge.size();i++){
	    temp = state;
	    temp.cost += shop[state.nn].randEdge[i].waight;
	    temp.nn = shop[state.nn].randEdge[i].dist;
	    temp.isShop = false;
	    qu.push(temp);
	  }
	  
	  for(int i = 0;i<shop[state.nn].shopEdge.size();i++){
	    temp = state;
	    temp.cost += shop[state.nn].shopEdge[i].waight;
	    temp.nn = shop[state.nn].shopEdge[i].dist;
	    temp.isShop = true;
	    qu.push(temp);
	  }
	}
      }
      
      else if(state.isShop == false){
	for(int i = 0;i<mark[state.nn].randEdge.size();i++){
	  temp = state;
	  temp.cost += mark[state.nn].randEdge[i].waight;
	  temp.nn = mark[state.nn].randEdge[i].dist;
	  temp.isShop = false;
	  qu.push(temp);
	}
	
	for(int i = 0;i<mark[state.nn].shopEdge.size();i++){
	  temp = state;
	  temp.cost += mark[state.nn].shopEdge[i].waight;
	  temp.nn = mark[state.nn].shopEdge[i].dist;
	  temp.isShop = true;
	  qu.push(temp);
	}
      }
    }
  }
  return;
}
  
void makeEdge(){
  for(int i = 0;i<shop.size();i++)
    dijkstra(i);
}

void backTrack(int nn,int cost){
  cost -= shop[nn].cal;
  
  if(nn == shop.size()-1){
    ans = min(ans,cost);
    return;
  }

  shop[nn].visited = true;

  for(int i = 0;i<shop[nn].edge.size();i++)
    if(shop[shop[nn].edge[i].dist].visited == false)
      backTrack(shop[nn].edge[i].dist,cost+c*shop[nn].edge[i].waight);
  
  shop[nn].visited = false;
}

void test(){

  for(int i = 0;i<shop.size();i++){
    cout << "shop : " << i << endl;
    for(int j = 0;j<shop[i].edge.size();j++)
      cout << "(" << shop[i].edge[j].dist << "," << shop[i].edge[j].waight << ") ";
  cout << endl;  
  }
}

bool isShop(string str){
  return str == "H" || str == "D" || str[0] == 'C';
}

int tr(string str){
  if(str == "H")
    return 0;
  
  if(str == "D")
    return shop.size()-1;
  
  return atoi(str.substr(1).c_str())-(int)(str[0] == 'L');
}

main(){
  while(cin >> n >> s >> c >> k && n){
    assert(MIN_N <= n && n <= MAX_N);
    assert(MIN_S <= s && s <= MAX_S);
    assert(MIN_C <= c && c <= MAX_C);
    //    assert(MIN_EDGE <= k && k <= MAX_EDGE);

    shop.clear();
    mark.clear();
    
    shop.push_back(Shop(0));
    for(int i = 0;i<n;i++){
      int cal;
      cin >> cal;
      shop.push_back(Shop(cal));
    }
    shop.push_back(Shop(0));

    for(int i = 0;i<s;i++)
      mark.push_back(Randmark());

    for(int i = 0;i<k;i++){
      string a,b;
      int w;
      cin >> a >> b >> w;

      assert(MIN_WAIGHT <= w && w <= MAX_WAIGHT);
      
      if( isShop(a)){
	if(isShop(b)){
	  shop[tr(a)].shopEdge.push_back(Edge(tr(b),w));
	  shop[tr(b)].shopEdge.push_back(Edge(tr(a),w));
	}
	else{
	  shop[tr(a)].randEdge.push_back(Edge(tr(b),w));
	  mark[tr(b)].shopEdge.push_back(Edge(tr(a),w));
	}
      }
      else{
	if(isShop(b)){
	  mark[tr(a)].shopEdge.push_back(Edge(tr(b),w));
	  shop[tr(b)].randEdge.push_back(Edge(tr(a),w));
	}
	else{
	  mark[tr(a)].randEdge.push_back(Edge(tr(b),w));
	  mark[tr(b)].randEdge.push_back(Edge(tr(a),w));
	}
      }
      //cout << "a = " << a << ", b = " << b << ",w = " << w << endl;
    }
    makeEdge();
    //test();
    ans = 1 << 30;
    backTrack(0,0);
    cout << ans << endl;
  }
  return 0;
}
