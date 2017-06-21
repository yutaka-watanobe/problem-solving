#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long ullong;

struct Number{ ullong num, den; };

void simulate(){
    Number left, center, right;
    left.num = 0;
    left.den = 1;
    right.num = 1;
    right.den = 0;
    center.num = 1;
    center.den = 1;
    string command; 
    cin >> command;
    for ( int i = 0; i < command.size(); i++ ){
	char ch = command[i];
	if ( command[i] == 'L' ) right = center;
	else left = center;
	center.num = left.num + right.num;
	center.den = left.den + right.den;
    }
    cout << center.num << "/" << center.den << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) simulate();
}
