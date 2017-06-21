#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<cassert>
#include<queue>
#include<stack>

#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define pb         push_back
#define mp         make_pair
#define vint       vector<int>
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define lli	    long long int
#define ld	    long double

#define INF 100000000

class Node{
public:
  int x, y, cost;
  Node(int t1, int t2){
    x = t1; y = t2;
    cost = INF;
  }
  Node(){}
};

int getDistance(Node n1, Node n2){
  return abs(n1.x - n2.x) + abs(n1.y - n2.y);
}


using namespace std;
main(){
  int H, W;
  while(cin >> H >> W){
    if( H + W == 0)break;
    vector<Node> v[5];
    Node start, goal;
    rep(h, H){
      rep(w, W){
	char c;
	cin >> c;
	if(c == '.')continue;
	else if( c == 'S'){
	  start = Node(w, h);
	}
	else if( c == 'G'){
	  goal = Node(w, h);
	}
	else {
	  int type = c - '0';
	  v[type-1].pb(Node(w, h));
	}
      }
    }
    
    int ans = INF, res = -1;
    rep(startType, 5){     
      int pretype = startType;
      int ntype = pretype + 1;
      rep(i, 5){
	FOR(it, v[i])(*it).cost = INF;
      }
      ntype %= 5;
      //cout << startType+1 << endl;
      FOR(it, v[ntype]){
	(*it).cost = getDistance(start, (*it));	
	//cout << (*it).x << ' '<<(*it).y <<' '<< (*it).cost << endl;
      }
      //cout << endl;

      rep(i, 3){
	pretype = ntype;
	ntype = (ntype+ 1)%5;
	//cout << endl << ntype << endl ;
	FOR(it, v[pretype]){
	  FOR(it2, v[ntype]){
	    (*it2).cost = min((*it2).cost, (*it).cost + getDistance((*it), (*it2)));
	    //    cout << (*it2).x << ' ' << (*it2).y << ' '<< (*it2).cost<< endl;
	  }
	}
      }
      int mini = INF;
      rep(i, v[ntype].size()){
	mini = min(mini, getDistance(v[ntype][i], goal) + v[ntype][i].cost);
	//cout << v[ntype][i].x << ' ' << v[ntype][i].y << ' ' <<v[ntype][i].cost << endl;
      }
      //cout << mini << endl;
      if(ans > mini){
	res = startType;
	ans = mini;
      }
    }
    if(ans >= INF)cout << "NA" << endl;
    else{
      cout << res + 1 << ' ' << ans << endl;
    }
  }
}
  
  
























































