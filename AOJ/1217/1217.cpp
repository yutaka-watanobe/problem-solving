#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
#define MAX 1000

class Node{
    public:
    int parent;
    vector<int> children;
    Node(){}
};

Node N[MAX];
map<string, int> N_I;
int n;
string line;

void makeTree(){
    for ( int i = 0; i < n; i++ ) N[i] = Node();
    string name;
    int P[MAX], pr;
    N[0].parent = -1;
    for ( int i = 0; i < n; i++ ){
	getline(cin, line);
	int ns = 0;
	while( line[ns] == ' ') ns++;
	name = line.substr(ns, line.size()-ns);
	N_I[name] = i;
	P[ns] = i;
	if ( i == 0 ) continue;
	pr = P[ns-1];
	N[i].parent = pr;
	N[pr].children.push_back(i);
    }
}

bool parse( int u, int target ){
    if ( u == -1 ) return false;
    if ( u == target ) return true;
    if ( parse(N[u].parent, target) ) return true;
    return false;
}

bool check(string s_str, string com, string t_str){
    int s = N_I[s_str];
    int t = N_I[t_str];
    if ( com == "child" ) return N[s].parent == t;
    else if ( com == "parent" )	return N[t].parent == s;
    else if ( com == "sibling" ) return N[t].parent == N[s].parent;
    else if ( com == "ancestor" ) return parse(t, s);
    else if ( com == "descendant" ) return parse(s, t);
}

main(){
    int m;
    string s, com, t, tmp;
    while( cin >> n >> m && n && m){
	getline(cin, line);
	makeTree();
	for ( int i = 0; i < m; i++ ) {
	    getline(cin, line);
	    stringstream sin(line);
	    sin >> s >> tmp >> tmp >> com >> tmp >> t;
	    t = t.substr(0, t.size()-1);
	    if ( check(s, com, t) ) cout << "True" << endl;
	    else cout << "False" << endl;
	}
	cout << endl;
    }
}
