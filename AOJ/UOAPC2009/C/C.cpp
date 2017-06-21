#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;
vector<string> buffer;
static const string ENTER = "ENTER";
int row, cursor;
string buff;

void del(){
    if ( cursor == buffer[row].size() ) { // EOL
	if ( row < buffer.size()-1 ){
	    buffer[row] += buffer[row+1];
	    buffer.erase(buffer.begin() + (row+1));
	}
    } else {
	buffer[row].erase(buffer[row].begin() + cursor );
    }
} 

void cut(){
    if ( cursor == buffer[row].size() ){
	del();
	buff = ENTER;
    } else {
	buff = buffer[row].substr(cursor);
	buffer[row].erase(cursor);
	cursor = (int)buffer[row].size();
    }
}

void insert(){
    if ( buff == ENTER ){
	if ( cursor == buffer[row].size() ){
	    buffer.insert(buffer.begin() + row+1, "");
	    row++; cursor = 0;
	} else {
	    string nstr = buffer[row].substr(cursor);
	    buffer[row].erase(cursor);
	    buffer.insert(buffer.begin() +row+1, nstr);
	    row++; cursor = 0;
	}
    } else {
	buffer[row].insert( cursor, buff );
	cursor += (int)buff.size();
    }
}

void trace(){
    cout << "-------------------------------------" << endl;

    for ( int i = 0; i < buffer.size(); i++ ){
	string s = buffer[i];
	for ( int j = 0; j < s.size(); j++ ){
	    if ( i == row && j == cursor ){
		if ( s[j] == ' ' ) cout << "_";
		else cout << (char)toupper(s[j]);
	    } else {
		cout << s[j];
	    }
	}
	if ( i == row && cursor == s.size() ) cout << "X";
	cout << endl;
    }

    cout << "-------------------------------------" << endl;
}

void simulate( char com ){
    if ( com == 'a' ) {
	cursor = 0;
    } else if ( com == 'e' ){
	cursor = (int)buffer[row].size();
    } else if ( com == 'p' ){
	if ( row == 0 ) cursor = 0;
	else { row--; cursor = 0;}
    } else if ( com == 'n' ){
	if ( row == buffer.size()-1 ) cursor = 0;
	else {row++; cursor = 0;}
    } else if ( com == 'f' ){
	if ( cursor < buffer[row].size() ) cursor++;
	else {
	    assert( cursor == buffer[row].size() );
	    if ( row < buffer.size()-1 ){ row++; cursor = 0;}
	}
    } else if ( com == 'b' ){
	if ( cursor > 0 ) cursor--;
	else {
	    assert( cursor == 0 );
	    if ( row > 0 ) { row--; cursor = buffer[row].size(); }
	}
    } else if ( com == 'd' ) {
	del();
    } else if ( com == 'k' ) {
	cut();
    } else if ( com == 'y' ) {
	insert();
    } else {
	assert( false );
    }

    //    trace();
}

int main(){
    string line;

    while(1){
	getline(cin, line);
	if ( line == "END_OF_TEXT" ) break;
	buffer.push_back(line);
    }

    row = cursor = 0;
    buff = "";
    char command;
    int ncom = 0;
    int maxs = 0;
    int maxl = 0;
    while( cin >> command ){
      if ( command == '-' ) break;
      simulate(command);
      ncom++;
      maxl = max ( maxl, (int)buffer.size() );
      for (int i =0; i < buffer.size(); i++ ){
	maxs = max( maxs, (int)buffer[i].size() );
      }
    }

   

    for ( int i = 0; i < buffer.size(); i++ ){
	cout << buffer[i] << endl;
    }

    //    cout << "ncom = " << ncom << endl;
    //    cout << "maxl = " << maxl << endl;
    //    cout << "maxs = " << maxs << endl;
    return 0;
}
