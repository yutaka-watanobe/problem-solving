#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    int JOI, IOI;
    while( cin >> str ){
	JOI = IOI = 0;
	for ( int i = 0; i < str.size()-2; i++ ){
	    if ( str.substr(i, 3) == "JOI" ) JOI++;
	    if ( str.substr(i, 3) == "IOI" ) IOI++;
	}
	cout << JOI << endl;
	cout << IOI << endl;

    }
    return 0;
}
