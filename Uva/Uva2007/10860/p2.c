#include<iostream>
#include<vector>
#include<string>
#define MAX 10002

using namespace std;

string line;

int match( int cursor, string target ){
  int tsize = target.size();
  if ( cursor - tsize < 0 ) return -1;

  for ( int i = 0; i < tsize; i++ ){
    if ( target[ tsize - i - 1] != line[ cursor - i ] ) return -1;
  }

  return cursor - tsize;
}


void work(){

  int n;
  cin >> line; line = ' ' + line;
  cin >> n;

  vector<string> buffer;
  
  for ( int i = 0; i < n; i++ ) {
    string str; cin >> str;
    buffer.push_back( str );
  }
  
  int size = line.size();
  int cost[ MAX ];
  for ( int i = 0; i <= size; i++ ) cost[i] = INT_MAX;
  
  cost[0] = 0;

  for ( int cursor = 1; cursor <= size; cursor++ ){
    for ( int i = 0; i < buffer.size(); i++ ){
      string target = buffer[i];

      int pos = match( cursor, target );
      if ( pos != -1 ){
	if ( cost[pos] != INT_MAX ){
	  cost[cursor] = min( cost[cursor], cost[pos] + 1);
	}
      }
    }
    /*
    for ( int i = 0; i < size; i++ ){
      int x = cost[i];
      if ( x == INT_MAX ) cout << "x ";
      else cout << x << " ";
    }
    cout << endl;*/
  }

  if ( cost[ size -1] == INT_MAX ) cout << "Not possible." << endl;
  else {
    cout << cost[size-1] << "." << endl;
  }
}

main(){
  int tcase; cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    cout << "Set " << i << ": ";
    work();
  }
}
