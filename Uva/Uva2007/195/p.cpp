// @JUDGE_ID:  46878RE  195  C++
// @begin_of_source_code
// Simple Permutation
// 小さい順に A a B b C c D c E e,,,,
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> buffer;
char alpha[52];

void init(){
    for ( int i = 0; i < 26; i++ ){
	alpha[2 * i] = 'A' + i;
	alpha[2 * i +1] = 'a' + i;
    }
}

void input(){
    string line;
    cin >> line;
    
    buffer.clear();

    for ( int i = 0; i < line.size(); i++ ){
	int value;
	if ( isupper(line[i]) ) value = (line[i] - 'A') * 2;
	else value = (line[i] - 'a') * 2 + 1;
	buffer.push_back(value);
    }
}

void work(){
    sort( buffer.begin(), buffer.end() );

    while( 1 ){
	for (int i = 0; i < buffer.size(); i++ ) printf("%c", alpha[buffer[i]]);
	printf("\n");

	if ( !next_permutation(buffer.begin(), buffer.end()) ) break;

    }
}


main(){
    init();
    int tcase;
    cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	work();
    }
}
// @end_of_source_code
