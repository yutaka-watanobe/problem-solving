#include<iostream>
#include<string>

/*
<exp> = <term> { (+|-) <term>}
<term> = <factor> { (*|/) <factor>}
<factor> = (<exp>) | number 
 */

using namespace std;

int expression();
int term();
int factor();

string exp;
int p;

int expression(){
    int value = term();
    while( exp[p] == '+' || exp[p] == '-' ){
	if ( exp[p] == '+' ) { p++; value += term(); }
	else { p++; value -= term(); }
    }
    return value;
}

int term(){
    int value = factor();
    while( exp[p] == '*' || exp[p] == '/' ){
	if ( exp[p] == '*' ) { p++; value *= factor(); }
	else { p++; value /= factor(); }
    }
    return value;
}

int factor(){
    int value = 0;
    if ( exp[p] == '(' ){
	p++; value = expression(); p++;
    } else {
	while( isdigit(exp[p]) ) { value = value*10 + exp[p] - '0'; p++;}
    }
    return value;
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	cin >> exp;
	p = 0;
	cout << expression() << endl;
    }
    return 0;
}
