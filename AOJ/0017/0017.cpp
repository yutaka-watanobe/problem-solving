#include<iostream>
#include<string>
using namespace std;

bool valid(string line){
  string t[3] = {"the", "this", "that"};
  for ( int i = 0; i < 3; i++ ){
    if ( line.find(t[i]) != string::npos ) return true;
  }
  return false;
}

void move(string &line){
  for ( int i = 0; i < line.size(); i++ ){
    if ( line[i] == 'a' ) line[i] = 'z';
    else if ( 'b' <= line[i] && line[i] <= 'z' ){
      line[i] = (char)(line[i]-1);
    }
  }
}
main(){
  string line;
  while(1){
    getline(cin, line);
    if ( cin.eof() ) break;
    while(1){
      if ( valid(line) ) {
	cout << line << endl;
	break;
      }
      move(line);
    }
  }
}
