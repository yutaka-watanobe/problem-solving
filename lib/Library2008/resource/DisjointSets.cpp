// begin_of_source
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
  
  void union( int x, int y ){
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
// end_of_source
