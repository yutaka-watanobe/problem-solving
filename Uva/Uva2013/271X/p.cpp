#include<iostream>
#include<string>

using namespace std;

string line;


bool isCorrect( int s, int e){
    if( s == e && ( 'p' <= line[s] && line[s] <= 'z')  )  return true;


    if ( line[s] == 'N' ){
	if ( e > s ){
	    if ( isCorrect( s + 1, e ) ) return true;
	    else return false;
	} else return false;
    }

    if ( line[s] == 'C' || line[s] == 'D' || line[s] == 'E' || line[s] == 'I' ){
	if ( e > s + 1 ){
	    for ( int d = s+1; d <= e-1; d++ ){
		if ( isCorrect( s+1, d ) &&
		     isCorrect( d + 1, e ) ) return true;
	    }
	}
    }


    return false;
}

main(){

    while ( cin >> line ){
	if ( isCorrect( 0, line.size()-1 ) ) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}
