#include<iostream>
#include<map>
#include<string>
using namespace std;

main(){
    map<char, int> M;

    M[' '] = 0;
    M['I'] = 1;
    M['V'] = 5;
    M['X'] = 10;
    M['L'] = 50;
    M['C'] = 100;
    M['D'] = 500;
    M['M'] = 1000;

    string line;
    while( cin >> line ){
	line += ' ';
	int sum = 0;
	for ( int i = 0; i < line.size()-1; i++ ){
	    if ( M[line[i]] < M[line[i+1]] ){
		sum -= M[line[i]]; 
	    } else {
		sum += M[line[i]]; 
	    }
	}
	cout << sum << endl;
    }
}
