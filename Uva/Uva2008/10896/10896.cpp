#include<iostream>
#include<sstream>
using namespace std;

main(){
    int tcase; cin >> tcase;
    string line, target;
    getline( cin, line );

    for ( int i = 0; i < tcase; i++ ){
	getline( cin, line );
	getline( cin, target );

	for ( int s = 0; s < 26; s++ ){
	    string source = line;
	    //	    cout << "source " << source << endl;
	    for ( int i = 0; i < source.size(); i++ ){
		if ( isalpha(source[i]) ) {
		    int t = source[i]-'a'-s;
		    if ( t < 0 ) t += 26;
		    source[i] = t + 'a';
		}
	    }
	    stringstream sin(source);
	    string str;
	    while( sin >> str ){
		if ( str == target ) cout << (char)(s + 'a');
	    }
	}
	cout << endl;
    }

}
