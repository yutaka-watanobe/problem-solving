#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static const int MAX = 100;
int NP, NT, NF;
int P[MAX+1];
vector<int> source[MAX+1]; // input of T
vector<int> target[MAX+1]; // output of T
vector<int> adj[MAX+1]; // from P to T
bool inq[MAX+1];

void init(){
  for ( int i = 1; i <= MAX; i++ ){
    source[i].clear();
    target[i].clear();
    adj[i].clear();
    inq[i] = false;
  }
}

void input(){
  int x;
  for ( int i = 1; i <= NP; i++ ) cin >> P[i];
  cin >> NT;
  for ( int i = 1; i <= NT; i++ ){
    while(1){
      cin >> x;
      if ( x == 0 ) break;
      if ( x > 0 ) { 
	target[i].push_back(x);
      } else {
	source[i].push_back(x*(-1));
	adj[x*(-1)].push_back(i);
      }
    }
  }
  cin >> NF;
}

bool isAvailable(int t){
  bool available = true;
  for ( int i = 0; i < source[t].size(); i++ ){
    int s = source[t][i];
    if ( P[s] <= 0 ) available = false;
    P[s]--;
  }
  for ( int i = 0; i < source[t].size(); i++ ){
    int s = source[t][i];
    P[s]++;
  }
  return available;
} 

void fire(int t, queue<int> &Q){
  for ( int i = 0; i < source[t].size(); i++ ){
    int s = source[t][i];
    P[s]--;
  }
  for ( int i = 0; i < target[t].size(); i++ ){
    int g = target[t][i];
    P[g]++;
    for ( int j = 0; j < adj[g].size(); j++ ){
      if ( !inq[adj[g][j]] ) {
	  Q.push(adj[g][j]);
	  inq[adj[g][j]] = true;
	}
    }
  }
}

void trace(){
  for ( int i = 1; i <= NP; i++ ){
    cout << P[i] << " ";
  }
}

void simulate(){
  
  queue<int> Q;
  for ( int i = 1; i <= NP; i++ ){
    if ( P[i] == 0  )continue;
    for ( int j = 0; j < adj[i].size(); j++ ){
      if ( !inq[adj[i][j]] ) {
	Q.push(adj[i][j]);
	inq[adj[i][j]] = true;
      }
    }
  }

  int cnt = 0;
  for ( cnt = 0; cnt < NF; ){
    int fired = -1;
    while(!Q.empty() ){
      int it = Q.front(); Q.pop();
      inq[it] = false;
      if ( isAvailable(it) ){
	fired = it;
	break;
      }
    }
    if ( fired ==  -1 ) break;

    fire(fired, Q); 
    cnt++;

    if ( isAvailable(fired) ) {
      if ( !inq[fired] ) {
	Q.push(fired);
	inq[fired] = true;
      }
    }
  }

  if ( cnt == NF ){
    cout << " still live after " << cnt << " transitions" << endl;
  } else {
    cout << " dead after " << cnt  << " transitions" << endl;
  } 

  cout << "Places with tokens:";
  for ( int i = 1; i <= NP; i++ ){
    if ( P[i] ) cout << " " << i << " (" << P[i] << ")";
  }
  cout << endl;
  cout << endl;
}

main(){
  int tcase = 1;
  while(1){
    cin >> NP;
    if ( NP == 0 ) break;
    cout << "Case " << tcase++ << ":";
    init();
    input();
    simulate();
  }
}
