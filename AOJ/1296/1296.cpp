#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
#define MAX 10
pair<string, string> M[MAX];
int n;
string source, target;

string getNext(string str, string s, string t ){
    int i = 0;
    while( i+s.size()-1< str.size() ){
	if ( str.substr(i, s.size() ) == s ){
	    str.replace(i, s.size(), t);
	    i += t.size();
	} else i++;
    }
    return str;
}

int bfs(){
    queue<string> Q;
    map<string, int> D;
    map<string, bool> V;
    Q.push(source);
    D[source] = 0; V[source] = true;
    string u, v, s, t;
    while(!Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u == target ) return D[u];
	for ( int i = 0; i < n; i++ ){
	    s = M[i].first; t = M[i].second;
	    v = getNext(u, s, t);
	    if ( !V[v] && v.size() <= target.size()){
		D[v] = D[u] + 1;
		V[v] = true;
		Q.push(v);
	    }
	}
    }
    return -1;
}

main(){
    while ( cin >> n && n ){
	for ( int i = 0; i < n; i++ ) cin >> M[i].first >> M[i].second;
	cin >> source >> target;
	cout << bfs() << endl;
    }
}

