#include<iostream>
#include<string>
using namespace std;

string toLowerCamel(string str){
    string l = "";
    char pre = ' ';
    for ( int i = 0; i < str.size(); i++ ){
	if ( isalpha(str[i]) ){
	    if ( pre == '_' ) l += toupper(str[i]);
	    else l += str[i];
	}
	pre = str[i];
    }
    l[0] = tolower(l[0]);
    return l;
}

main(){
    string name;
    char com;
    while(1){
	cin >> name >> com;
	if ( com == 'X' ) break;
	string l = toLowerCamel(name);
	if ( com == 'L' ) cout << l << endl;
	else if ( com == 'U' ){
	    l[0] = toupper(l[0]);
	    cout << l << endl;
	} else if ( com == 'D' ){
	    for ( int i = 0; i < l.size(); i++ ){
		if ( 'A' <= l[i] && l[i] <= 'Z' ){
		    cout << "_";
		    cout << (char)(tolower(l[i]));
		} else cout << l[i];
	    }
	    cout << endl;
	}
    }
}
