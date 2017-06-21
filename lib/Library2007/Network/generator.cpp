#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

class edge{
public:
  int source, target, cap;
  edge(){}
  edge(int source, int target, int cap):source(source), target(target), cap(cap){}

};

main(){
  int size = 100;
  cout << size << endl;
  vector<edge> v;

  for ( int i = 0; i < size-1; i++ ){
    for (int j = i+1; j< size; j++ ){
      //      if ( i % 23 == 0 ) continue;
      //      if ( i % 51 == 0 ) continue;

      v.push_back( edge(i, j, 100+rand()%80 ));
    }
  }
  cout << v.size() << endl;
  for ( int i = 0; i < v.size(); i++ )
    cout << v[i].source << " " << v[i].target << " " << v[i].cap << endl;

}
