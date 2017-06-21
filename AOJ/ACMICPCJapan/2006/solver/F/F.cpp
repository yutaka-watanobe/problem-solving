#include<iostream>
#include<queue>
#include<map>
#include<set>

using namespace std;
#define INFTY (1<<20)
#define MAX 1000

int ans[MAX+1];
bool state[MAX+1];

int limit;

int bfs(int target){
  set<int> state;
  state.insert(1);

  queue<set<int> > Q;
  map<set<int>, bool> V;
  map<set<int>, int> D;

  Q.push(state);
  V[state] = true;
  D[state] = 0;

  set<int> u, v;
  set<int>::iterator it1, it2;
  while(!Q.empty() ){
    u = Q.front(); Q.pop();

    if ( u.size() > 12 ) break;

    for ( it1 = u.begin(); it1 != u.end(); it1++ ){
      for ( it2 = u.begin(); it2 != u.end(); it2++ ){
	int sum = *it1 + *it2;
	int sub = *it1 - *it2;
	if ( sum == target || sub == target ) return D[u];
	if ( sum <= MAX ) {
	  v = u;
	  v.insert( sum );
	  if ( !V[v] ) {
	    V[v] = true;
	    D[v] = D[u]+1;
	    Q.push(v);
	  }
	}
	if ( sub >= -1000 ) {
	  v = u;
	  v.insert( sub );
	  if ( !V[v] ) {
	    V[v] = true;
	    D[v] = D[u]+1;
	    Q.push(v);
	  }
	}
      }
    }
  }
}

main(){
  int n;
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    cout << bfs(n) << endl;
  }
}
