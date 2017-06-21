#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long ullong;

struct Number{
    ullong numerator, denominator;
};

void simulate(){
    Number left, center, right;
    left.numerator = 0;
    left.denominator = 1;
    right.numerator = 1;
    right.denominator = 0;
    center.numerator = 1;
    center.denominator = 1;

    string command; cin >> command;
    for ( int i = 0; i < command.size(); i++ ){
	char ch = command[i];
	if ( ch == 'L' ){
	    right = center;
	} else {
	    left = center;
	}
	center.numerator = left.numerator + right.numerator;
	center.denominator = left.denominator + right.denominator;
    }
    cout << center.numerator << "/" << center.denominator << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) simulate();
}
