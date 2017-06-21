#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Line{
    public:
    int row, col;
    vector<string> words;
    string title;
    Line(){}

    void set(int r, int c, vector<string> w){
	row = r;
	col = c;
	words = w;
	title = words[col];
    }

    string getTitle(){
	return words[col];
    }

    bool operator < ( const Line &l ) const{
	if ( title == l.title ){
	    if ( row == l.row ) return col == l.col;
	    else return row < l.row;
	} else return title < l.title;
    }

    

    string toUpper(string str){
	for ( int i = 0; i < str.size(); i++ ) str[i] = toupper(str[i]);
	return str;
    }

    void print(){
	for ( int i = 0; i < words.size(); i++ ){
	    if ( i ) cout << " ";
	    if ( i == col ) cout << toUpper(words[i]);
	    else cout << words[i];
	}
	cout << endl;
    }
};

map<string, bool> IG;

string toLower(string str){
    for ( int i = 0; i < str.size(); i++ ) str[i] = tolower(str[i]);
    return str;
}

int main(){
    string line;

    while(1){
	getline(cin, line);
	if ( line == "::" ) break;
	IG[line] = true;
    }

    string word;
    vector<Line> L;

    while(1){
	getline( cin , line );
	if ( cin.eof() ) break;
	stringstream sin(line);
	vector<string> words;
	while( sin >> word) words.push_back(toLower(word));

	for ( int i = 0; i < words.size(); i++ ){
	    if ( IG[words[i]] ) continue;
	    L.push_back(Line());
	    L[L.size()-1].set(L.size()-1, i, words);
	}
    }

    sort( L.begin(), L.end() );
    for ( int i = 0; i < L.size(); i++ ) L[i].print();


    return 0;
}

