#include<iostream>
#include<string>
#include<set>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )

set<string> P;

bool exist(string s){
    for ( set<string>::iterator it = P.begin(); it != P.end(); it++ ){
	if ( s.size() <= (*it).size() && s == (*it).substr(0, s.size())) 
	    return true;
    }
    return false;
}

bool convert(string s, string &t){
    bool f;
    int p, e;

    if ( s.size() >= 2 && s.substr(s.size()-2, 2) == "/." ) s = s.substr(0, s.size()-1);

    for(; (p = s.find("/./")) != string::npos; s.replace(p+1, 2, ""));
    for(; (p = s.find("/..")) != string::npos; ){
	if ( exist(s.substr(0, p+1)) && p){
	    for ( e = p+3, p--; s[p] != '/'; p--);
	    s.replace(p, e-p, "");
	} else return false;
    }
    t = s;
    if ( P.find(t) != P.end()) return true;
    t += (t[t.size()-1]=='/')?"index.html":"/index.html";
    if ( P.find(t) != P.end()) return true;

    return false;
}

main(){
    int N, M;
    string path, t1, t2;
    while( cin >> N >> M && (N || M) ){
	P.clear();
	rep(i, N) { cin >> path; P.insert(path); }
	rep(i, M){
	    cin >> t1 >> t2;
	    string c1, c2;
	    if ( convert(t1, c1) && convert(t2, c2) ){
		cout << ((c1==c2)?"yes":"no") << endl;
	    } else {
		cout << "not found" << endl;
	    }
	}
    }
}

