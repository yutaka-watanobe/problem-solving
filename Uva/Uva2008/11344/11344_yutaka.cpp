#include<iostream>
#include<string>
using namespace std;

int getRemainder( string str, int div ){
    if ( str.size() == 1 ) return (str[0] - '0') % div;
    int rem = str[0] - '0';
    for ( int i = 1; i < str.size(); i++ ){
	rem = (rem*10 + (str[i]-'0')) % div;
    }
    return rem;
}

void compute(){
    string line; cin >> line;
    bool isWonderful = true;
    int m, x;
    cin >> m;
    for ( int i = 0; i < m; i++ ){
	cin >> x;
	if ( getRemain(line, x) != 0 ) isWonderful = false;
    }
    cout << line << ((isWonderful) ? " - Wonderful." : " - Simple.") << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
}
