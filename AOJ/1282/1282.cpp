#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<map>
using namespace std;

vector<string> L;
int size[52];
map<pair<int, int>, int> V;
map<pair<int, int>, bool> A; 

int idx(char ch){
    if ( 'a' <= ch ) return ch - 'a';
    else return ch - 'A' + 26;
}

int getInt(string str, int &p ){
    string num = "";
    while( isdigit(str[p]) ) num += str[p++];
    if ( num.size() ) return atoi(num.c_str());
    int n = idx(str[p]);
    p += 2;
    int v = getInt(str, p);
    if ( v == -1 || size[n] <= v || !A[make_pair(n, v)] ) return -1;
    return V[make_pair(n, v)];
}

int compute(){
    for ( int i = 0; i < 52; i++ ) size[i] = 0;
    V = map<pair<int, int>, int>();
    A = map<pair<int, int>, bool>();
    for ( int i = 0; i < L.size() ;i++ ) {
	string line = L[i];
	if ( line.find('=') != string::npos ) {
	    int e = 0; while( line[e] != '=' ) e++;
	    e++;
	    int r = getInt(line, e);
	    int pos = 2;
	    int li = getInt(line, pos);
	    if ( li == -1 || r == -1 || li >= size[idx(line[0])]) return i+1;
	    V[make_pair(idx(line[0]), li)] = r;
	    A[make_pair(idx(line[0]), li)] = true;
	} else {
	    int pos = 2;
	    size[idx(line[0])] = getInt(line, pos);
	}
    }
    return 0;
}

main(){
    string str;
    while( cin >> str ){
	if ( str == "." ) break;
	L.clear(); L.push_back(str);
	while( cin >> str ){
	    if ( str == "." ) break;
	    L.push_back(str);
	}
	cout << compute() << endl;
    }
}
