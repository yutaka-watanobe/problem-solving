#include<iostream>
#include<string>
#include<cassert>

using namespace std;

bool checkLetters( string str ){
    bool hasM, hasE;
    hasM = hasE = false;
    for ( int i = 0; i < str.size(); i++ ){
	if ( str[i] == 'M' ){
	    if ( hasM || hasE ) return false;
	    hasM = true;
	} else if ( str[i] == 'E' ){
	    if ( !hasM || hasE ) return false;
	    hasE = true;
	} else if ( str[i] == '?' ){

	} else return false;
    }
    return (hasM && hasE);
}

bool isTheorem( string str ){
    //Cheack for exact ?* one M ?* exact one E ?*;
    if ( !checkLetters( str ) ) return false;

    int x, y, z, i;
    x = y = z = 0;
    i = 0;
    while ( str[i++] == '?' ) x++;
    assert( str[i-1] == 'M');
    while ( str[i++] == '?' ) y++;
    assert( str[i-1] == 'E');
    while ( i < str.size() && str[i++] == '?' ) z++;

    if ( x == 0 || y == 0 || z == 0 ) return false;
    
    return ( x + y ) == z;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	string line; cin >> line;
	if ( isTheorem(line) ) cout << "theorem" << endl;
	else cout << "no-theorem" << endl;
    }
}
