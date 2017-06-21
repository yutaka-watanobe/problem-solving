#include<iostream>
#include<string>

using namespace std;

string T[3][2], S[3];

bool check( char target, int w ){
    int left, right;
    for ( int i = 0; i < 3; i++ ){
	left = right = 0;
	
	for ( int s = 0; s < T[i][0].size(); s++ ){
	    if ( T[i][0][s] == target ) left += w;
	}
	
	for ( int s = 0; s < T[i][1].size(); s++ ){
	    if ( T[i][1][s] == target ) right += w;
	}

	if ( S[i] == "even" ){
	    if ( !(left == right) ) return false;
	} else if ( S[i] == "up" ){
	    if ( !(left > right) ) return false;
	} else if ( S[i] == "down" ){
	    if ( !(left < right) ) return false;
	}
    }

    return true;
}


void compute(){
    for ( char c = 'A'; c <= 'L'; c++ ){
	if ( check( c, -1) ){
	    cout << c << " is the counterfeit coin and it is light." << endl;
	    break;
	} else if ( check( c, 1 ) ){
	    cout << c << " is the counterfeit coin and it is heavy." << endl;
	    break;
	}
    }
}

void input(){
    for ( int i = 0; i < 3; i++ ){
	cin >> T[i][0] >> T[i][1] >> S[i];
    }
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) {
	input();
	compute();
    }
    return 0;
}
