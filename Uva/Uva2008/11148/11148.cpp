#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int gcd( int x, int y ){
    int r;
    if ( x < y ) swap( x, y );
    
    while ( y > 0 ){
        r = x % y;
        x = y;
        y = r;
    }
    
    return x;
}

void compute(string line){
    stringstream sin(line);
    string statement;
    char tmp;
    int num, den, mul;
    int numerator = 1;
    int denominator = 1;
    while( sin >> statement ){

	int pos = 0;
	while( !isdigit(statement[pos]) && pos < statement.size() ) pos++;
	if ( pos == statement.size() ) continue;
	statement = statement.substr(pos, statement.size()-pos);

	if ( !isdigit(statement[0]) ) continue;

	if ( statement.find('-') != string::npos ) {
	    stringstream mdiv(statement);
	    mdiv >> mul >> tmp >> num >> tmp >> den;	    
	    numerator *= (mul*den+num);
	    denominator *= den;
	} else	if ( statement.find('/') != string::npos ) {
	    stringstream div(statement);
	    div >> num >> tmp >> den;
	    numerator *= num;
	    denominator *= den;
	} else {
	    stringstream val(statement);
	    val >> num;
	    numerator *= num;
	}
    }
    int GCD = gcd(numerator, denominator );
    numerator /= GCD;
    denominator /= GCD;

    if ( denominator == 1 ) {
	cout << numerator << endl;
    } else if ( numerator > denominator ){
	int mul = numerator / denominator;
	numerator = numerator % denominator;
	cout << mul << "-" << numerator << "/" << denominator << endl;
    } else {
	cout << numerator << "/" << denominator << endl;
    }
}

main(){
    int tcase; cin >> tcase;
    string line;
    getline( cin, line );
    for ( int i = 0; i < tcase; i++ ){
	getline( cin, line );
	compute(line);
    }
}
