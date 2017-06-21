#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int index;

string expression( string &exp, int &pos){
    string result = "";
    while(1){
	string d = "";
	while( isdigit(exp[pos]) ) d += exp[pos++];
	int id;
	if ( d.size() == 0 ) id = 1;
	else id = atoi(d.c_str());
	string e = "";
	if ( exp[pos] == '(' ) {
	    pos++;
	    e = expression(exp, pos);
	} else {
	    while( pos < exp.size() && isalpha(exp[pos]) ) e += exp[pos++];
	}
	
	for ( int i = 0; i < id; i++ ) {
	    if ( result.size() <= index ) result += e;
	}
	
	if ( pos >= exp.size() || exp[pos] == ')' ){
	    pos++;
	    return result;
	}
    }
}

void compute(string exp){
  int pos = 0;
    string r =  expression(exp, pos);
    if ( r.size() <= index ) cout << "0" << endl;
    else cout << r[index] << endl;
}

main(){
  string exp;
    while(1){
	cin >> exp >> index;
	if ( exp == "0" && index == 0 ) break;
	compute(exp);
    }
}
