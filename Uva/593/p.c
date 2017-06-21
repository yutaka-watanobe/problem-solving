// @JUDGE_ID:  17051CA  593  C++
// @begin_of_source_code
/* Graph Simulation + APSP */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<map>
#include<set>
#include<string>
#include<queue>

class Host{
 public:
  int address;
  int routerID;
  set<int> group;
  int current_message;

  Host(){}
  Host( int address, int routerID ): address(address), routerID(routerID){
    group.clear();
  }

  void join( int add ){
    group.insert( add );
  }

  void leave( int add ){
    set<int>::iterator pos;
    pos = find( group.begin(), group.end(), add );
    group.erase( pos );
  }

};

class Tunnel{
 public:
  int threshold;
  string target;
  Tunnel(){}
  Tunnel(int threshold, string target): threshold(threshold), target(target){}
};

class Router{
 public:
  vector<Tunnel> tunnel;
  vector<int> hostID;
  Router(){}

  void addTunnel(Tunnel t){
    tunnel.push_back( t );
  }

  void addHost(int id){
    hostID.push_back( id );
  }
};

class Message{
 public:
  int hostAddress, packetID, remain;
  Message(int h, int p, int r ): hostAddress(h), packetID(p), remain(r){}

  bool operator < ( const Message &m ) const{
    if ( m.hostAddress != hostAddress ){
      return hostAddress < m.hostAddress;
    }else{
      return packetID < m.packetID;
    }
  }
};

vector<Router> R;
vector<Message> M;
map<int, Host> H;
map<string, int> routerID;

int read(){
  int m;
  cin >> m;
  if ( m == 0 ) return 0;
  
  R.clear();
  M.clear();
  H = map<int, Host>();
  routerID = map<string, int>();

  string name, target;
  char ch;
  int add, shr, k;
  for ( int i = 0; i < m; i++ ){
    cin >> name >> k;
    routerID[ name ] = i;
    Router router = Router();
    for ( int j = 0; j < k; j++ ){
      cin >> ch;
      if ( ch == 'H' ){
	cin >> add;
	H[ add ] = Host( add, i );
	router.addHost( add );
      }else if ( ch == 'T' ){
	cin >> shr >> target;
	router.addTunnel( Tunnel(shr, target) );
      }
    }
    R.push_back( router );
  }

  return 1;
}

void send(int hostAddress, int groupAddress, int packetID, int TTL ){
  set<int> g = H[ hostAddress].group;
  if ( find( g.begin(), g.end(), groupAddress ) == g.end() ) return ;

  /* floyd All Pairs Shortest Path */
  vector<vector<int> > d;
  d.resize( R.size() );
  for ( int i = 0; i < R.size(); i++ ){
    d[i].resize( R.size() );
    for ( int j = 0; j < R.size(); j++ ){
      if ( i == j ) d[i][j] = 0;
      else d[i][j] = INT_MAX;
    }
  }
  for ( int i = 0; i < R.size(); i++ ){
    vector<Tunnel> tunnel = R[i].tunnel;
    for ( int j = 0; j < tunnel.size(); j++ ){
      d[i][routerID[tunnel[j].target]] = tunnel[j].threshold;
    }
  }
  int n = R.size();
  for( int k = 0; k < n; k++ ){
    for( int i = 0; i < n; i++ ){
      if( d[i][k] == INT_MAX ) continue;
      for( int j = 0; j < n; j++){
	if( d[k][j] == INT_MAX ) continue;
	if( d[i][j] == INT_MAX || d[i][k] + d[k][j] < d[i][j]){
	  d[i][j] = d[i][k] + d[k][j];
	}
      }
    }
  }
  
  int start = H[ hostAddress ].routerID;

  for ( int j = 0; j < n; j++ ){
    if ( d[start][j] <= TTL ){
      Router router = R[ j ];
      for ( int i = 0; i < router.hostID.size(); i++ ){
	Host host = H[ router.hostID[i] ];
	if ( find( host.group.begin(), host.group.end(), groupAddress ) != host.group.end() ){
	  M.push_back( Message( host.address, packetID, TTL - d[start][j] ));
	}
      }
    }
  }

}

void work(){
  int query, hostAddress, groupAddress, packetID, TTL;
  char ch;
  cin >> query;

  for ( int i = 0; i < query; i++ ){
    cin >> ch;
    if ( ch == 'J' ){
      cin >> hostAddress >> groupAddress;
      H[ hostAddress ].join( groupAddress );
    }else if ( ch == 'L' ){
      cin >> hostAddress >> groupAddress;
      H[ hostAddress ].leave( groupAddress );
    }else if ( ch == 'S' ){
      cin >> hostAddress >> groupAddress >> packetID >> TTL;
      send ( hostAddress, groupAddress, packetID, TTL );
    }
  }

  sort( M.begin(), M.end() );

  for ( int i = 0; i < M.size(); i++ ){
    cout << M[i].hostAddress << " " << M[i].packetID << " " << M[i].remain << endl;
  }

}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Network #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
