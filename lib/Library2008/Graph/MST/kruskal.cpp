// solved 908, 11631, 11747
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

int N;

int kruskal(vector<Edge> edges){ // vector<Edge> &mst
    int totalCost = 0;
    sort( edges.begin(), edges.end() );
    
    DisjointSet dset = DisjointSet( N + 1);
    
    for ( int i = 0; i < N; i++ ) dset.makeSet( i );
    
    int source, target;
    for ( int i = 0; i < edges.size(); i++ ){
        Edge e = edges[i];
        if ( dset.findSet( e.source ) != dset.findSet( e.target ) ){
            //mst.push_back( e );
	    totalCost += e.cost;
            dset.merge( e.source, e.target );
        }
    }
    return totalCost;
}

int main(){
    int M, K, before, source, target, cost;

    int tcase = 0;
    while( cin >> N ){
	before = 0;
	for  ( int i = 0; i < N-1; i++ ){
	    cin >> source >> target >> cost;
	    before += cost;
	}
	vector<Edge> edges;
	cin >> K;
	for ( int i = 0; i < K; i++ ){
	    cin >> source >> target >> cost;
	    edges.push_back(Edge(source, target, cost));
	}
	cin >> M;
	for ( int i = 0; i < M; i++ ){
	    cin >> source >> target >> cost;
	    edges.push_back(Edge(source, target, cost));
	}
	if ( tcase ) cout << endl;
	cout << before << endl;
	cout << kruskal(edges) << endl;

	tcase++;
    }
}
