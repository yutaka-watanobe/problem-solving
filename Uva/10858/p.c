#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Fact{
 public:
  int n;
  int buffer[20];

  Fact(){
    n = 0;
  }

  void push_back(int x ){
    buffer[n++] = x;
  }

  int size(){
    return n;
  }

};

int N;
vector<Fact> results;

void rec( Fact v ){
  Fact tmp;


  for ( int i = 1; i < v.size(); i++ ){
    if ( v.buffer[i-1] > v.buffer[i] ) return;
  }

  int i = 2;
  while ( 1 ){
    int factor = i;
    
    tmp = v;
    int end = tmp.buffer[ tmp.size() - 1];
    int pre = tmp.buffer[ tmp.size() - 2];
    if ( end <= factor ) break;

    if ( end % factor == 0 && factor >= pre ){
      
      tmp.buffer[ tmp.size()-1 ] = factor;
      tmp.push_back( end/factor);

      rec( tmp );
    }

    i++;
  }

  if ( v.size() > 2 ){
    results.push_back( v );
  }

}

void work(){
  results.clear();

  Fact v;
  v.push_back(-1);
  v.push_back(N);

  rec( v );

  cout << results.size() << endl;
  for ( int j = 0; j < results.size(); j++ ){

    Fact r = results[j];
    for ( int i = 1; i < r.size(); i++ ){
      if ( i != 1 ) printf(" ");
      printf("%d", r.buffer[i]);
    }
    printf("\n");
  }

}

main(){

  while ( cin >> N ){
    if ( N == 0 ) break;
    work();
  }
}
