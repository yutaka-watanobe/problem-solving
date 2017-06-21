#include<stdio.h>
#include<string>
#include<iostream>
#include<map>

using namespace std;

map<string, char> M;

void init(){
    M[".-"] = 'A';
    M["-..."] = 'B';
    M["-.-."] = 'C';
    M["-.."] = 'D';
    M["."] = 'E';
    M["..-."] = 'F';
    M["--."] = 'G';
    M["...."] = 'H';
    M[".."] = 'I';
    M[".---"] = 'J';
    M["-.-"] = 'K';
    M[".-.."] = 'L';
    M["--"] = 'M';
    M["-."] = 'N';
    M["---"] = 'O';
    M[".--."] = 'P';
    M["--.-"] = 'Q';
    M[".-."] = 'R';
    M["..."] = 'S';
    M["-"] = 'T';
    M["..-"] = 'U';
    M["...-"] = 'V';
    M[".--"] = 'W';
    M["-..-"] = 'X';
    M["-.--"] = 'Y';
    M["--.."] = 'Z';
    M["-----"] = '0';
    M[".----"] = '1';
    M["..---"] = '2';
    M["...--"] = '3';
    M["....-"] = '4';
    M["....."] = '5';
    M["-...."] = '6';
    M["--..."] = '7';
    M["---.."] = '8';
    M["----."] = '9';
    M[".-.-.-"] = '.';
    M["--..--"] = ',';
    M["..--.."] = '?';
    M[".----."] = '\'';
    M["-.-.--"] = '!';
    M["-..-."] = '/';
    M["-.--."] = '(';
    M["-.--.-"] = ')';
    M[".-..."] = '&';
    M["---..."] = ':';
    M["-.-.-."] = ';';
    M["-...-"] = '=';
    M[".-.-."] = '+';
    M["-....-"] = '-';
    M["..--.-"] = '_';
    M[".-..-."] = '\"';
    M[".--.-."] = '@';

    /*
    map<string, char>::iterator pos;
    for ( pos = M.begin(); pos != M.end(); pos++ ){
	cout << (*pos).first << " " << (*pos).second << endl;
	}*/
}

void compute(){
    char ch, pre;
    
    pre = 'a';
    string str = "";
    int nspace = 0;

    while (1){
	scanf("%c", &ch);
	if ( ch == '\n' ) break;

	if ( ch == ' ' ){
	    if ( str.size() ){
		cout << M[str];
		str = "";
	    }
	    nspace++;
	} else {
	    if ( nspace ){
		for ( int i = 0; i < nspace/2; i++ ) cout << " ";
		nspace = 0;
	    }
	    str += ch;
	}
	pre = ch;
    }
    if ( str.size() ) cout << M[str];
    cout << endl;
}

main(){
    init();
    char ch;
    int tcase; scanf("%d", &tcase);
    scanf("%c", &ch);
    for ( int i = 0; i < tcase; i++ ){
	if ( i ) cout << endl;
	cout << "Message #" << i+1 << endl;
	compute();
    }
}
