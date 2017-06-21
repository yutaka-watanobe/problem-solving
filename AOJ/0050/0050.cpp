#include<iostream>
#include<string>
using namespace std;

main(){
    string line;
    while( getline( cin, line) ){
      cout << line.size() << endl;
	string str = line;
	for ( int i = 0; i <= line.size()-5; i++ ){
	    if ( line.substr(i, 5) == "apple" ){
		str.replace(i, 5, "peach");
	    }
	    if ( line.substr(i, 5) == "peach" ){
		str.replace(i, 5, "apple");
	    }
	}
	cout << str << endl;
    }
}
