#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define REP(i,e) for ( int i = 0; i < (int)(e); i++)
typedef long long llong;
#define MAX 1000000

void addNList(int buffer[], int &size, stringstream &sin){
    int n;
    sin >> n;
    REP(i, n) sin >> buffer[size++];
}

void addIList(int buffer[], int &size, stringstream &sin ){
    int n, s, d;
    sin >> n >> s >> d;
    REP(i, n) buffer[size++] = s + i*d;
}

void addRList(int buffer[], int &size, stringstream &sin){
    llong n, l, h, s;
    sin >> n >> l >> h >> s;
    llong sub = h - l + 1;
    for ( int i = 0; i < n; i++ ){
	s = (s*17 + 11) & 0x00000000ffffffffll;
	buffer[size++] = s%sub + l;
    }
}

int main(){
    int index, size, tcase;;
    int buffer[MAX];
    string line, formula;
    tcase = 1;
    while( cin >> index && index ){
	cin >> line;
	REP(i, line.size() ) {
	    if ( isdigit(line[i]) || line[i] == '-' ) continue;
	    if ( line[i] == 'I' || line[i] == 'N' || line[i] == 'R' ) continue;
	    line[i] = ' ';
	}
	
	size = 0;
	
	stringstream sin(line);
	char f;
	while( sin >> f ){
	    if ( f == 'N' ) addNList(buffer, size, sin);
	    else if ( f == 'I' ) addIList(buffer, size, sin);
	    else if ( f == 'R' ) addRList(buffer, size, sin);
	}
	
	sort( buffer, buffer + size );

	cout << "Case " << tcase++ << ": " << buffer[index-1] << endl;
    }
    return 0;
}
