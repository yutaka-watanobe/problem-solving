#include<iostream>
#include<string>
#include<cassert>
using namespace std;

void convert( string &line ){
    for ( int i = 0; i <= (int)line.size() - 7; i++ ){
	if ( line.substr(i, 7) == "Hoshino" ){
	    line.replace(i, 7, "Hoshina");
	}
    }
}

int main(){
    int tcase; cin >> tcase;
    string line;
    getline( cin, line );
    for ( int i = 0; i < tcase; i++ ){
	getline( cin, line );
	assert( line.size() <= 1000 );
	convert(line);
	cout << line << endl;
    }
    return 0;
}
