#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define MAX 101
using namespace std;

class edge{
    public:
    int city, time;
    int cost;
    edge(){}
    edge( int city, int time, int cost ): city(city), time(time), cost(cost){}
};

int size;
vector<edge> graph[MAX][13];
int startCity, goalCity;

map<string, int> S_I;

int getTimeIndex( int time ){
    return time - 18;
    time = time % 24;
    if ( time <= 6 ) return time + 6;
    else return time - 18;
}

int getID( string name ){
    if ( S_I.find( name ) == S_I.end() ){
	S_I[ name ] = size++;
    }
    return S_I[ name ];
}

void add( int s, int stime, int t, int ttime, int cost){
    //    cout << "[" << s << "][" << stime << "]" << " --> ";
    //    cout << "[" << t << "][" << ttime << "]" << cost << endl;
    graph[s][stime].push_back( edge(t, ttime, cost ));
}

int dijkstra(){
    
    int d[MAX][13];
    bool visited[MAX][13];
    for ( int i = 0; i < size; i++ ){
	for ( int j = 0; j < 13; j++ ){
	    d[i][j] = INT_MAX;
	    visited[i][j] = false;
	}
    }
    
    for ( int j = 0; j < 13; j++ ){
	d[startCity][j] = 0;
    }

    while ( 1 ){
	int mincost = INT_MAX;

	int city, time;

	for ( int i = 0; i < size; i++ ){
	    for ( int j = 0; j < 13; j++ ){
		if ( !visited[i][j] && mincost > d[i][j] ){
		    mincost = d[i][j];
		    city = i;
		    time = j;
		}
	    }
	}

	if ( mincost == INT_MAX ) break;

	//	cout << city << "-" << time << endl;
	visited[city][time] = true;

	vector<edge> edges = graph[city][time];
	for ( int n = 0; n < edges.size(); n++ ){
	    edge e = edges[n];
	    if ( !visited[e.city][e.time] && d[city][time] + e.cost < d[e.city][e.time] ){
		d[e.city][e.time] = d[city][time] + e.cost;
	    }
	}
    }

    int mincost = INT_MAX;
    for ( int j = 0; j < 13; j++ ){
	if ( d[goalCity][j] < mincost ) mincost = d[goalCity][j];
    }

    return mincost;
}

void work(){
    int cost = dijkstra();

    if ( cost == INT_MAX ){
	cout << "There is no route Vladimir can take." << endl;
    } else {
	cout << "Vladimir needs " << cost << " litre(s) of blood." << endl;
    }
}


void read(){
    for ( int i = 0; i < MAX; i++ ){
	for ( int j = 0; j < 13; j++ ){
	    graph[i][j].clear();
	}
    }
    size = 0;
    int k; 

    int start, time;
    string source, target;
    S_I = map<string, int>();

    cin >> k;
    for ( int i = 0; i < k; i++ ){
	cin >> source >> target >> start >> time;

	int s = getID( source );
	int t = getID( target );

	if ( 0 <= start && start <= 6 ) start += 24;

	if ( start < 18 ) continue;
	if ( (start + time) >= 24 && 6 < (start + time) % 24 ) continue;

	add( s, getTimeIndex( start ), t, getTimeIndex(start + time), 0);

    }
    // connect time

    for ( int i = 0; i < size; i++ ){
	for ( int s = 0;  s < 13; s++ ){
	    for ( int t = 0; t < 13; t++ ){
		if ( s == t ) continue;
		if ( s < t ){
		    add(i, s, i, t, 0);
		} else {
		    add(i, s, i, t, 1);
		}
	    }
	}
    }

    string sc, gc; cin >> sc >> gc;
    startCity = S_I[sc];
    goalCity = S_I[gc];
}


main(){
  int tcase; cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
      cout << "Test Case " << i << "." << endl;
      read();
      work();
  }
}
