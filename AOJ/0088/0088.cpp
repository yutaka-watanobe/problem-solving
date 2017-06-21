#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char, string> M1;
string M2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-\'?";

void init(){
    string list = " \',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string codes[32] = {"101", "000000", "000011", "10010001",
			"010001", "000001", "100101", "10011010",
			"0101", "0001", "110", "01001", "10011011",
			"010000", "0111", "10011000", "0110",
			"00100", "10011001", "10011110", "00101",
			"111", "10011111", "1000", "00110",
			"00111", "10011100", "10011101", "000010",
			"10010010", "10010011", "10010000"};
    for ( int i = 0; i < list.size(); i++ ) M1[list[i]] = codes[i];
}

int getValue(string str){
    int v = 0, p = 1;
    for ( int i = 4; i >= 0; i-- ){
	if ( str[i] == '1' ) v += p;
	p *= 2;
    }
    return v;
}

main(){
    init();
    string line; 
    while(1){
	getline(cin, line);
	if ( cin.eof() ) break;
	string code = "";
	for ( int i = 0; i < line.size(); i++ ){
	    code += M1[line[i]];
	}
	while( code.size()%5 != 0 ) code+= "0";
	
	for ( int i = 0; i < code.size(); i+=5 ){
	    cout << M2[getValue( code.substr(i,5))];
	}
	cout << endl;
    }
}
