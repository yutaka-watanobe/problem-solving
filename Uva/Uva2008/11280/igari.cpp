#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#define MAX_NODE 1000

using namespace std;

class Edge{
public:
  int dist;
  int cost;

  Edge(int inDist,int inCost){
    dist = inDist;
    cost = inCost;
  }

  Edge(){
  }
};

class Node{
public:
  vector<Edge> edge;
};

class State{
public:
  int cost;
  int nn;
  int step;

  bool operator>(const State &in)const{
    return cost > in.cost;
  }
};

Node node[MAX_NODE];

int dijkstra(int n,int limit){
  priority_queue<State,vector<State>,greater<State> > qu;
  State state,temp;
  bool visited[MAX_NODE][MAX_NODE+1];

  for(int i = 0;i<n;i++)
    for(int j = 0;j<=n;j++)
      visited[i][j] = false;

  state.nn = state.step = state.cost = 0;
  qu.push(state);

  while(!qu.empty()){
    state = qu.top();
    qu.pop();

    if(state.step <= limit + 1 && visited[state.nn][state.step] == false){
      visited[state.nn][state.step] = true;

      // cout << state.nn << " " << state.step << " " << state.cost << endl;

      if(state.nn == n-1)
	return state.cost;

      for(int i = 0;i<node[state.nn].edge.size();i++){
	temp = state;
	temp.step++;
	temp.nn = node[state.nn].edge[i].dist;
	temp.cost += node[state.nn].edge[i].cost;
	qu.push(temp);
      }
    }
  }
  return -1;
}

void input(){
  int t;
  cin >> t;
  for(int k = 0;k<t;k++){
    int n;
    cin >> n;
    map<string,int> p;
    string str1,str2;
    for(int i = 0;i<n;i++){
      cin >> str1;
      p[str1] = i;
      node[i].edge.clear();
    }
    int m,cost;
    cin >> m;
    for(int i = 0;i<m;i++){
      cin >> str1 >> str2 >> cost;
      //cout << str1 << " " << str2 << " " << cost << endl;
      node[p[str1]].edge.push_back(Edge(p[str2],cost));
    }
    int q;
    cin >> q;
    if(k != 0)
      cout << endl;
    cout << "Scenario #" << k+1 << endl;
    for(int i = 0;i<q;i++){
      int limit;
      cin >> limit;
      int ans = dijkstra(n,limit);
      if(ans == -1)
	cout << "No satisfactory flights" << endl;
      else
	cout << "Total cost of flight(s) is $" << ans << endl;
    }
  }
}

main(){
  input();
  return 0;
}
