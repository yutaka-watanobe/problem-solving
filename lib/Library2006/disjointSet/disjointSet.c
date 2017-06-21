/****************
 * disjoint set *
 * Solved 273,  *
 ****************/
/* work */
#include<stdio.h>
#include<iostream>
#include<vector>

class DisjointSet{
 public:
  vector<int> rank, p;

  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
  }

  void merge(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if(rank[x] > rank[y]){
      p[y] = x;
    }else{   
      p[x] = y;
      if(rank[x] == rank[y]){
	rank[y] = rank[y] + 1;
      }
    }
  }

  int findSet(int x){
    if(x != p[x]){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }
};

main(){
  DisjointSet dset = DisjointSet(10);

  for(int i=0; i<10; i++){
    dset.makeSet(i);
  }

  dset.merge(0, 1);
  dset.merge(4, 5);
  dset.merge(1, 2);
  dset.merge(3, 6);
  dset.merge(3, 8);
  dset.merge(6, 9);

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      if(dset.findSet(i) == dset.findSet(j) ) cout << i << "==" << j << endl;
      else cout << i << "!=" << j << endl;
    }
  }
}
