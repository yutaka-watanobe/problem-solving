// trivial problem 
// PE??
#include<iostream>
#include<string>
#include<vector>
#define MAX 1001

void split ( vector<int> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back( atoi(t.c_str())); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back( atoi(t.c_str()));
}

int size;
int buffer[MAX]; 

void init(){
  for ( int i = 0; i < size; i++ ) buffer[i] = 0;
}

void compute(){
  string line;
  cin >> size;
  init();

  getline( cin, line );
  
  for ( int i = 0; i < size; i++ ){
    getline( cin, line );

    vector<int> neighbour;
    split( neighbour, line );
    
    buffer[i] = neighbour.size();
  }
  getline( cin, line );


  int minValue;
  minValue = INT_MAX;

  for ( int i = 0; i < size; i++ ){
    if ( minValue > buffer[i] ) minValue = buffer[i];
  }

  bool isFirst = true;
  for ( int i = 0; i <size; i++ ) {
    if ( buffer[i] == minValue ){
      cout << i+1 << " ";
      //      if ( isFirst ) cout << " ";
      isFirst = false;
    }
  }
  cout << endl;
}

main(){
  int tcase; cin >> tcase;
  for ( int i = 0; i < tcase; i++ ) compute();
}
