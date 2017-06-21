#include<iostream>
#include<string>
using namespace std;

main(){
  string line;
  while( getline(cin, line) ){
    if ( cin.eof() ) break;
    cout << " " + line << endl;
  }
}
