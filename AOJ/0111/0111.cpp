#include<iostream>
#include<map>
using namespace std;

map<char, string> C1;
map<string, char> C2;

void init(){
    string c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-\'?";
    string s[32] = {"00000",
		    "00001",
		    "00010",
		    "00011",
		    "00100",
		    "00101",
		    "00110",
		    "00111",
		    "01000",
		    "01001",
		    "01010",
		    "01011",
		    "01100",
		    "01101",
		    "01110",
		    "01111",
		    "10000",
		    "10001",
		    "10010",
		    "10011",
		    "10100",
		    "10101",
		    "10110",
		    "10111",
		    "11000",
		    "11001",
		    "11010",
		    "11011",
		    "11100",
		    "11101",
		    "11110",
		    "11111"};

    for ( int i = 0; i < c.size(); i++ ){
	C1[c[i]] = s[i];
    }

    C2["101"] = ' ';
    C2["000000"] = '\'';
    C2["000011"] = ',';
    C2["10010001"] = '-';
    C2["010001"] = '.';
    C2["000001"] = '?';
    C2["100101"] = 'A';
    C2["10011010"] = 'B';
    C2["0101"] = 'C';
    C2["0001"] = 'D';
    C2["110"] = 'E';
    C2["01001"] = 'F';
    C2["10011011"] = 'G';
    C2["010000"] = 'H';
    C2["0111"] = 'I';
    C2["10011000"] = 'J';
    C2["0110"] = 'K';
    C2["00100"] = 'L';
    C2["10011001"] = 'M';
    C2["10011110"] = 'N';
    C2["00101"] = 'O';
    C2["111"] = 'P';
    C2["10011111"] = 'Q';
    C2["1000"] = 'R';
    C2["00110"] = 'S';
    C2["00111"] = 'T';
    C2["10011100"] = 'U';
    C2["10011101"] = 'V';
    C2["000010"] = 'W';
    C2["10010010"] = 'X';
    C2["10010011"] = 'Y';
    C2["10010000"] = 'Z';
}

string getCode(string str){
    string s = "";
    for ( int i = 0; i < str.size(); i++ ){
	s += C1[str[i]];
    }
    return s;
}

void convert(string code){
    string str = "";
    for ( int i = 0; i < code.size(); i++ ){
	str += code[i];
	if ( C2[str] != '\0' ){
	    cout << C2[str];
	    str = "";
	} 
    }
    if ( C2[str] != '\0' ){
	cout << C2[str];
    }
    cout << endl;

}

main(){
    init();
    string line;
    while(1){
	getline(cin, line);
	if ( cin.eof() ) break;
	string code = getCode(line);
	convert(code);
    }
}
