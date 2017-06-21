#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<map>

using namespace std;

string input;

string itoa(int x){
  char a[20];
  
  sprintf(a, "%d", x);

  return string(a);
}

string trim( string str ){
  while ( 1 ){
    if ( str[0] != '0' || str.size() == 1 ) break;

    str.erase( str.begin() );
  }

  return str;
}

void work(){
  map<string, bool> visited;

  visited[ input ] = true;

  int counter = 1;

  string current = input;
  string descending, ascending;

  cout << "Original number was " << current << endl;

  while ( 1 ){
    descending = current;
    ascending = current;
    
    sort( descending.begin(), descending.end(), greater<char>() );
    sort( ascending.begin(), ascending.end(), less<char>() );

    int sub = atoi( descending.c_str()) - atoi( ascending.c_str() );
    
    current = trim( itoa( sub ) );
    
    cout << trim(descending) << " - " << trim(ascending) << " = " << current << endl;

    if ( visited[ current ] ) {
      cout << "Chain length " << counter << endl;
      cout << endl;
      return;
    }

    visited[ current ] = true;
    counter++;
  }


}

bool read(){
  cin >> input;
  if ( input == "0" ) return false;
  return true;
}

main(){
  while ( read() ){
    work();
  }
}
