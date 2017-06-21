#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define REP(i,e) for ( int i = 0; i < (int)(e); i++)
typedef long long llong;
#define MAX 1000000

void generalize(string &formula ){
    REP(i, formula.size() ){
	if ( !isdigit(formula[i]) && formula[i] != '-' ) formula[i] = ' ';
    }
}

void addNList(int buffer[], int &size, string formula ){
    generalize(formula);
    stringstream sin(formula);
    int n;
    sin >> n;
    while( sin >> n ) buffer[size++] = n;
}

void addIList(int buffer[], int &size, string formula ){
    generalize(formula);
    stringstream sin(formula);
    int n, s, d;
    sin >> n >> s >> d;
    REP(i, n) buffer[size++] = s + i*d;
}

void addRList(int buffer[], int &size, string formula){
    generalize(formula);
    stringstream sin(formula);
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
	REP(i, line.size() ) if ( line[i] == '+' ) line[i] = ' ';
	
	size = 0;
	
	stringstream sin(line);
	while( sin >> formula ){
	    if ( formula[0] == 'N' ) addNList(buffer, size, formula);
	    else if ( formula[0] == 'I' ) addIList(buffer, size, formula);
	    else if ( formula[0] == 'R' ) addRList(buffer, size, formula);
	}
	
	sort( buffer, buffer + size );

	cout << "Case " << tcase++ << ": " << buffer[index-1] << endl;
    }
    return 0;
}
