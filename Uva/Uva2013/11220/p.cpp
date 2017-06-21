#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void compute(){
    string line, str;
    
    while (1){
	getline( cin, line );
	if ( line.size() == 0 || cin.eof() ) break;

	stringstream sin(line);
	
	int pos = 0;
	while( sin >> str ){
	    if ( str.size() <= pos ) continue;
	    cout << str[pos++];
	}	
	cout << endl;
    }
}

main(){
    int tcase; cin >> tcase;
    string line; 
    getline( cin, line );
    getline( cin, line );
    for ( int i = 0; i < tcase; i++ ){
	if ( i ) cout << endl;
	cout << "Case #" << i+1 << ":" << endl;
	compute();
    }
}
