#include<iostream>
#include<string>
using namespace std;

string line;
int pos;

bool parse(){
    if ( pos >= line.size() ) return false;

    char ch = line[pos];

    if ( islower(ch) ) return true;
    else if ( ch == 'N' ){
	pos++;
	return parse();
    } else {
	pos++;
	bool left = parse();
	if ( !left ) return false;
	pos++;
	bool right = parse();
	return left && right;
    }
}

bool check(){
    pos = 0;
    if ( !parse() ) return false;
    return pos == line.size()-1;
}

int main(){
    while(1){
	getline(cin, line);
	if ( cin.eof() ) break;
	if ( check()) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
    return 0;
}
