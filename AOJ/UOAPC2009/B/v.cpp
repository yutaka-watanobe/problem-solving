#include<iostream>
#include<string>
#include<cassert>
using namespace std;
main(){
  string line;
  while(1){
    getline(cin, line);
    if ( line== "0" ) break;
    cout << line << endl;
    assert( line[line.size()-1] != ' ');
  }
}
