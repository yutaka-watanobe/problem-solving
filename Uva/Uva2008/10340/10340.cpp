#include<iostream>
#include<string>
using namespace std;

bool check( string &s, string &t ){
    if ( s.size() > t.size() ) return false;
    
    int j = 0;
    for ( int i = 0; i < s.size(); i++ ){
	while( j < t.size() && t[j] != s[i] ) j++;
	if ( j >= t.size() ) return false;
	j++;
    }
    return true;
}

int main(){
    string s, t;
    while ( cin >> s >> t ){
	if ( check( s, t ) ) cout << "Yes" << endl;
	else cout << "No" << endl;
    }

    return 0;
}
