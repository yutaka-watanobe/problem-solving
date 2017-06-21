#include<iostream>
#include<string>
using namespace std;

main(){
    int n;
    string str;
    while( cin >> n && n ){
	cin >> str;
	int d = str.size()/n;
	for ( int i = 0; i < str.size(); i+= d ){
	    reverse( str.begin() + i, str.begin() + (i+d) );
	}
	cout << str << endl;
    }
}
