#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define MAX 26

string line;
int cost[MAX], indeg[MAX];
string adj[MAX];

void input(){
    for ( int i = 0; i < MAX; i++ ){
	cost[i] = indeg[i] = 0;
	adj[i] = "";
    }
    char ch;
    while(1){
	getline(cin , line);
	if ( line.size() == 0 || cin.eof()) break;
	stringstream sin(line);
	sin >> ch; sin >> cost[ch-'A']; sin >> adj[ch-'A'];
    }
}

void compute(){
    
}

main(){
    int tcase; cin >> tcase;
    getline(cin, line);
    getline(cin, line);
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
}
