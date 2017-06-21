#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )

vector<string> P;
int N, M;

bool exist(string str){
    for ( int i = 0; i < P.size(); i++ ){
	if ( str.size() <= P[i].size() &&
	     str == P[i].substr(0, str.size())) return true;
    }
    return false;
}

bool convert(string str, string &t){
    bool f;
    int p, e;
    //cout << "1 " << str << endl;
    if ( str[str.size()-1] == '.' ){
	if ( str[str.size()-2] != '.' ){
	    str = str.substr(0, str.size()-1);
	}
    }
    while(1){
	if ( (p = str.find("/./")) == string::npos ) break;
	str.replace(p+1, 2, "");
    }
    //cout << "2 " << str << endl;

    while(1){
	if ( (p = str.find("/..")) == string::npos ) break;
	if ( exist(str.substr(0, p+1) ) && p){
	    e = p + 3;
	    p--;
	    while( str[p] != '/') p--;
	    str.replace(p, e-p, "");
	} else return false;
	//cout << str << endl;
    }
    //cout << "3 " << str << endl;
    t = str;

    for ( int i = 0; i < P.size(); i++ ){
	if ( P[i] == t ) return true;
    }
    if ( t[t.size()-1] == '/' ) t += "index.html";
    else t += "/index.html";
    for ( int i = 0; i < P.size(); i++ ){
	if ( P[i] == t ) return true;
    }

    return false;
}

main(){
    string path, t1, t2;
    while( cin >> N >> M && (N || M) ){
	P.clear();
	rep(i, N) { cin >> path; P.push_back(path); }
	rep(i, M){
	    cin >> t1 >> t2;
	    string c1, c2;

	    if ( convert(t1, c1) && convert(t2, c2) ){
		//		cout << c1 << endl;
		//		cout << c2 << endl;
		if ( c1 == c2 ) cout << "yes" << endl;
		else cout << "no" << endl;
	    } else {
		cout << "not found" << endl;
	    }
	    //    cout << endl;
	}
    }
}

