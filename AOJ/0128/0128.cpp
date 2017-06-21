#include<iostream>
#include<string>

using namespace std;

string number[10] = {"* = ****",
                     "* =* ***",
		     "* =** **",
		     "* =*** *",
		     "* =**** ",
		     " *= ****",
		     " *=* ***",
		     " *=** **",
		     " *=*** *",
		     " *=**** "};
int main(){
    string str;
    int tc = 0;
    while( cin >> str ){
	while( str.size() < 5 ) str = "0" + str;
	if ( tc++ ) cout << endl;
	for ( int i = 0; i < 8; i++ ){
	    for ( int j = 0; j < 5; j++ ){
		cout << number[str[j]-'0'][i];
	    }
	    cout << endl;
	}
    }

    return 0;
}
