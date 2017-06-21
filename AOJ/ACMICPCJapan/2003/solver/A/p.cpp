#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void shiftRight( string &line ){
    line = line[line.size()-1] + line.substr(0, line.size()-1);
}

void shiftLeft( string &line ){
    line = line.substr(1, line.size()-1 ) + line[0];
}

void swapHalf( string &line ){
    int mid = line.size()/2;
    if ( line.size() % 2 == 0 )
	line = line.substr(mid, line.size()-mid) + line.substr(0, mid); 
    else 
	line = line.substr(mid + 1, mid) + line[mid] + line.substr(0, mid); 
}

void reverse( string &line){
    reverse( line.begin(), line.end() );
}

void decrement( string &line ){
    for ( int i = 0; i < line.size(); i++ ){
	if ( isalpha(line[i]) ) continue;
	if ( line[i] == '0' ) line[i] = '9';
	else line[i]--;
    }
}

void increment( string &line ){
    for ( int i = 0; i < line.size(); i++ ){
	if ( isalpha(line[i]) ) continue;
	if ( line[i] == '9' ) line[i] = '0';
	else line[i]++;
    }
}


main(){
    int tcase; cin >> tcase;
    string command, line;

    for ( int i = 0; i < tcase; i++ ){
	cin >> command >> line;
	
	for ( int c = command.size()-1; c >= 0; c-- ){
	    if ( command[c] == 'J' ) shiftRight( line );
	    else if ( command[c] == 'C' ) shiftLeft( line );
	    else if ( command[c] == 'E' ) swapHalf( line );
	    else if ( command[c] == 'A' ) reverse( line );
	    else if ( command[c] == 'P' ) decrement( line );
	    else if ( command[c] == 'M' ) increment( line );
	}

	cout << line << endl;
    }
}