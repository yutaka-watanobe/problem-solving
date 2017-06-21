#include<iostream>
#include<string>
using namespace std;
main(){
  string line;
  getline(cin, line);
  string str;
  bool isf = true;
  line += '.';

  for ( int i = 0; i < line.size(); i++ ){
    if ( line[i] == '.' ||
	 line[i] == ',' ||
	 line[i] == ' '  ){
      if ( 3 <= str.size() && str.size() <= 6 ){
	if ( !isf ) cout << " ";
	isf = false;
	cout << str;
      }
      str = "";
    } else str += line[i];
  }
  cout << endl;
}
