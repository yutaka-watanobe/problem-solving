#include<iostream>
#include<string>

using namespace std;

int count( string str, string t, int &curr ){
    int cnt = 0;
    for( ; curr + t.size() - 1 < str.size(); cnt++, curr += t.size() ){
	if( str.substr(curr, t.size()) != t ) break;
    }
    return cnt;
}

bool isA( string str, int curr ){
    if ( str.substr(0, curr) != ">'" ) return false;
    int cnt = count(str, "=", curr);
    if ( cnt < 1 || str[curr++] != '#' ) return false;
    if ( cnt != count(str, "=", curr) ) return false;
    return ( curr == str.size()-1 && str[curr] == '~');
}

bool isB( string str, int curr ){
    if ( str.substr(0, curr) != ">^" ) return false;
    int cnt = count(str, "Q=", curr);
    return ( cnt && curr == str.size()-2 && str.substr(str.size()-2, 2) == "~~");
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) {
	string snake; cin >> snake;
	if ( isA(snake, 2) ) cout << "A" << endl;
	else if ( isB(snake, 2) ) cout << "B" << endl;
	else cout << "NA" << endl;
    }
    return 0;
}
