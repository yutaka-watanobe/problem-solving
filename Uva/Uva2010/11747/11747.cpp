// 11747:Heavy Cycle Edges:2.0:MST, Kruskal
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define MAX 1000000

class DisjointSet{
    public:
    DisjointSet(){}
    DisjointSet( int size ){
        rank.resize( size, 0 );
        p.resize( size, 0 );
    }
    
    void makeSet( int x ){
        p[x] = x;
        rank[x] = 0;
    }
    
    void merge( int x, int y ){
        link( findSet(x), findSet(y) );
    }
    
    int findSet( int x ){
        if ( x != p[x] ) p[x] = findSet( p[x] );
        return p[x];
    }
    
    bool isSameSet( int x, int y ){
        return ( findSet(x) == findSet(y) );
    }
    
    private:
    vector<int> rank, p;
    
    void link ( int x, int y ){
        if ( rank[x] > rank[y] ){
            p[y] = x;
        } else {
            p[x] = y;
            if ( rank[x] == rank[y] ) rank[y]++;
        }
    }
};

class Edge{
    public:
    int source, target, cost;
    Edge( int source=0, int target=0, int cost=0 ):
    source(source), target(target), cost(cost){}
    bool operator < ( const Edge &e ) const{
        return cost < e.cost;
    }
};


int kruskal(int N, vector<Edge> &edges, vector<Edge> &MST, vector<Edge> &kasu){
    sort( edges.begin(), edges.end() );
    
    DisjointSet dset = DisjointSet( N + 1);
    
    for ( int i = 0; i < N; i++ ) dset.makeSet( i );
    
    int source, target;
    for ( int i = 0; i < edges.size(); i++ ){
        Edge e = edges[i];
        if ( dset.findSet( e.source ) != dset.findSet( e.target ) ){
            MST.push_back( e );
            dset.merge( e.source, e.target );
        } else {
	    kasu.push_back( e );
	}
    }
    sort( kasu.begin(), kasu.end());
}

int main(){
    int N, M,  source, target, cost;

    while( cin >> N >> M && N && M){
	vector<Edge> edges, MST, kasu;
	for  ( int i = 0; i < M; i++ ){
	    cin >> source >> target >> cost;
	    edges.push_back(Edge(source, target, cost));
	}
	kruskal(N, edges, MST, kasu);
	if ( edges.size() == MST.size() ) cout << "forest" << endl;
	else {
	    bool isfirst = true;
	    for ( int i = 0; i < kasu.size(); i++ ){
		if ( !isfirst ) cout << " ";
		isfirst = false;
		cout << kasu[i].cost;
	    }
	    cout << endl;
	}

    }
}
