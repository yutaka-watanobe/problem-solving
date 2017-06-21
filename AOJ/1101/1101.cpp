#include<iostream>
#include<string>

using namespace std;
string line, str, com;
int cursor;

void forward(){
    if ( cursor == str.size()-1 ) return;
    str[cursor] = str[cursor+1];
    str[++cursor] = '^';
} 

void backward(){
    if ( cursor == 0 ) return;
    str[cursor] = str[cursor-1];
    str[--cursor] = '^';
}

void forwardWord(){
    int i = cursor+1;
    while( i < str.size() && str[i] == ' ') { str[i-1] = str[i++]; };
    while( i < str.size() && str[i] != ' ') { str[i-1] = str[i++]; };
    cursor = i-1;
    str[cursor] = '^';
}

void backwardWord(){
    int i = cursor-1;
    while( i >= 0 && str[i] == ' ' ) { str[i+1] = str[i--]; }
    while( i >= 0 && str[i] != ' ' ) { str[i+1] = str[i--]; }
    cursor = i+1;
    str[cursor] = '^';
} 

void deleteC(){
    if ( cursor >= str.size()-1 ) return;
    str.erase(  cursor+1, 1 );
}

bool hasWord(){
    int i = cursor + 1;
    while ( i < str.size() ){
	if ( str[i] != ' ' ) return true;
	i++;
    }
    return false;
}

void deleteWord(){
    if ( !hasWord() ) return;
    int i = cursor + 1;
    while( str[i] == ' ' ) str.erase( i, 1 );
    while( i < str.size() && str[i] != ' ' ) str.erase( i, 1 );
}

void insert( string w ){
    str.insert( cursor, w );
    cursor += w.size();
}

void simulate(){
    getline( cin, str );
    str = '^' + str;
    cursor = 0;
    int n; cin >> n; getline( cin, line);
    for ( int i = 0; i < n; i++ ){
	getline( cin, com );
	if ( com == "forward char" ) forward();
	else if ( com == "backward char" ) backward();
	else if ( com == "forward word" ) forwardWord();
	else if ( com == "backward word" ) backwardWord();
	else if ( com == "delete char" ) deleteC();
	else if ( com == "delete word" ) deleteWord();
	else {
	    int s = 0; 
	    string w = "";
	    while( com[s] != '"' ) s++;
	    s++;
	    while( com[s] != '"' ) { w += com[s++]; }
	    insert(w);
	}
    }
    cout << str << endl;

}

int main(){
    int tcase; cin >> tcase;
    getline( cin, line );
    for ( int i = 0; i < tcase; i++ ) simulate();
    return 0;
}
