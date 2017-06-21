#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define LIMIT 1440

string getString( int t ){
    string str = "";
    h = t/60;
    m = t%60;
    if ( h < 10 ) { str += '0'; str += h + '0';}
    else { str += (h/10 + '0'); str += (h%10 + '0' );}
    if ( m < 10 ) { str += '0'; str += m + '0';}
    else { str += (m/10 + '0'); str += (m%10 + '0' );}
    return str;
}
/*
string T[] = {


}
*/

void generate(){
    int h, m;
    string str;
    for ( int t = 0; t < LIMIT; t++ ){

	str = getString(t);

	for ( int i = 0; i < 2; i++ ){
	    if ( str[i] != str[4-i-1] ) goto next;
	}

	cout << " << str << " << endl;
    next:;
    }
}

void compute(){
    int h, m;
    char ch;
    cin >> h >> ch >> m;
    string str = getString(60*h + m);

    
}

main(){
    generate();
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}
