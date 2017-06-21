#include<iostream>
#include<string>

using namespace std;

bool isPZ( string str ){
    if ( str.size() == 1 ){
	if( 'p' <= str[0] && str[0] <= 'z' )  return true;
    }
    return false;
}

bool isCorrect( string str ){
    if ( isPZ( str ) ) return true;

    if ( str[0] == 'N' ){
	if ( str.size() >= 2 ){
	    if ( isCorrect( str.substr( 1, str.size()-1) ) ) return true;
	    else return false;
	} else return false;
    }

    if ( str[0] == 'C' || str[0] == 'D' || str[0] == 'E' || str[0] == 'I' ){
	if ( str.size() >= 3 ){
	    for ( int d = 1; d < str.size() - 1; d++ ){
		if ( isCorrect( str.substr(1, d) ) &&
		     isCorrect( str.substr(d+1, str.size()-d-1) ) ) return true;
	    }
	}
    }


    return false;
}

main(){
    string line;
    while ( cin >> line ){
	if ( isCorrect( line ) ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}
