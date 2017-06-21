#include<iostream>
#include<stdio.h>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;

void compute(string line){
    stringstream sin(line);
    string str;
    double S[100]; // stack;
    int top = 0;
    double arg1, arg2;
    while( sin >> str ){
	if ( str == "+" ){
	    arg1 = S[top]; top--;
	    arg2 = S[top]; top--;
	    S[++top] = (arg1 + arg2);
	} else if ( str == "-" ){
	    arg1 = S[top]; top--;
	    arg2 = S[top]; top--;
	    S[++top] = (arg2 - arg1);
	} else if ( str == "*" ){
	    arg1 = S[top]; top--;
	    arg2 = S[top]; top--;
	    S[++top] = (arg1 * arg2);
	} else if ( str == "/" ){
	    arg1 = S[top]; top--;
	    arg2 = S[top]; top--;
	    S[++top] = (arg2 / arg1);
	} else {
	    S[++top] = atoi(str.c_str()) * 1.0;
	}
    }
    printf("%.8lf\n", S[top]);
}

main(){
    string line;
    while( getline( cin, line ) ) compute( line );
}
