// @JUDGE_ID:  17051CA  245  C++
// @begin_of_source_code
// String simulation
#include<stdio.h>
#include<list>
#include<string>
#include<cassert>

using namespace std;

list<string> buffer;

string line;
int cursor;

void updateWord(){
    int n = 0;
    while ( isdigit( line[cursor] ) ){
	n *= 10, n += line[cursor++] - '0';
    }
    cursor--;

    list<string>::iterator pos = buffer.begin();
    for (int i = 1; i < n; i++ ) pos++;

    buffer.push_front(*pos);
    buffer.erase(pos);
} 

void addWord(){
    string str = "";
    while ( isalpha(line[cursor]) ){
	str += line[cursor++];
    }
    cursor--;
    buffer.push_front(str);
}


main(){
    char ch;
    while ( 1 ){
	getline( cin , line ); if ( line == "0" ) break;

	line += '\n';

	for ( cursor = 0; cursor < line.size(); cursor++ ){
	    if ( !isalnum( line[cursor] ) ){
		printf("%c", line[cursor]);
		continue;
	    }

	    if ( isdigit( line[cursor] ) ){
		updateWord();
	    } else {
		addWord();
	    }

	    printf("%s", buffer.front().c_str());
	}
    }
}
// @end_of_source_code
