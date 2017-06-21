#include<iostream>
#include<string>

using namespace std;

int getIndex(string str){
    int w = str.size();
    int base = 0;
    int p = 1;
    for ( int i = 0; i < w-1; i++ ) p *= 2;

    while( p ){
	base += p-1;
	p /= 2;
    }
    
    p = 1;
    for ( int i = str.size()-1; i >= 0; i--, p*=2 ) if ( str[i] == '1') base += p;

    return base;
}

string message;

void convert(){
    char ch;
    string code, w;
    int len;

    while(1){
	w = "";
	len = 0;
	for ( int i = 0; i < 3; i++ ){ cin >> ch; w += ch;};
	int p = 1;
	for ( int i = 2; i >= 0; i--, p*=2 ) if ( w[i]=='1') len += p;
	if ( len == 0 ) break;

	while(1){
	    code = "";
	    bool end = true;
	    for ( int i = 0; i < len; i++ ) {
		cin >> ch; code += ch;
		if ( ch == '0' ) end = false;
	    }
	    if ( end ) break;
	    cout << message[getIndex(code)];
	}
    }
    cout << endl;
    getline(cin, message);
}

int main(){
    while(1){
	getline(cin, message );
	if ( cin.eof() || message.size() == 0 ) break;
	//	cout << message << endl;
	convert();
    }
    return 0;
}
