#include<iostream>
#include<string>
#include<map>
#include<cassert>
using namespace std;

map<string, int> T;
bool isUnknown;
int cursor;
string line;

bool isDigit( char ch ){
    return ( '0' <= ch && ch <= '9' );
}

bool isLower( char ch ){
    return ( 'a' <= ch && ch <= 'z' );
}

int getDigit(){
    string digit = "";
    while( isDigit(line[cursor]) ){
	digit += line[cursor++];
    }
    if ( digit == "" ) digit = "1";
    return atoi( digit.c_str());
}
int molecular(){
    assert( line[cursor] == '(') ;
    cursor++;

    if ( line[cursor] == '(' ) {
	int w = molecular();
	assert( line[cursor] == ')');
	cursor++;
	return w*getDigit();
    } else {
	string str ="";
	int total = 0;
	while(1){
	    if ( line[cursor] == ')' ) break;

	    str += line[cursor++];
	    if ( isLower(line[cursor]) ) str += line[cursor++];

	    total += (T[str])*getDigit();
	}

	cursor++;
	return total*getDigit();
    }
}

void makeTable(){
    string name;
    int x;
    while(1){
	cin >> name;
	if ( name == "END_OF_FIRST_PART" ) break;
	cin >> x;
	T[name] = x;
    }
}

main(){
    makeTable();
    while(1){
	cin >> line;
	if ( line == "0" ) break;
	line = "(" + line + ")1";
	isUnknown = false;
	cursor = 0;
	int w = molecular();
	if ( isUnknown ) cout << "UNKNOWN" << endl;
	else cout << w << endl;
    }
}