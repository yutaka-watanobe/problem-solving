#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int n;
string seq;
set<string> D;
map<string, vector<string> > M;
vector<string> ans;

void dfs(int cur, vector<string> path){
    if ( cur == seq.size() ){
	string s = "";
	for ( int i = 0; i < path.size(); i++ ){
	    if ( i ) s += ' ';
	    s += path[i];
	}
	ans.push_back(s);
	return;
    }

    string target = "";
    for ( int i = cur; i < cur + 50 && i < seq.size(); i++ ){
	target +=  seq[i];
	if ( D.find(target) != D.end() ){
	    vector<string> v = M[target];
	    for ( int j = 0; j < v.size(); j++ ){
		vector<string> np = path;
		np.push_back(v[j]);
		dfs(i+1, np);
	    }
	}
    }
}

void compute(){
    cin >> seq;
    vector<string> path;
    ans.clear();

    dfs(0, path);

    for ( int i = 0; i < ans.size(); i++ ){
	cout << ans[i] << "." << endl;
    }
    cout << "--" << endl;
}

string getNumber(string str){
    string num = "";
    for ( int i = 0; i < str.size(); i++ ){
	char ch = str[i];
	if ( 'a' <= ch && ch <='c' ) num += '2';
	if ( 'd' <= ch && ch <='f' ) num += '3';
	if ( 'g' <= ch && ch <='i' ) num += '4';
	if ( 'j' <= ch && ch <='l' ) num += '5';
	if ( 'm' <= ch && ch <='o' ) num += '6';
	if ( 'p' <= ch && ch <='s' ) num += '7';
	if ( 't' <= ch && ch <='v' ) num += '8';
	if ( 'w' <= ch && ch <='z' ) num += '9';
    }
    return num;
}

main(){
    string str, number;
    while( cin >> n && n){
	D.clear();
	M = map<string, vector<string> >();
	for ( int i = 0; i < n; i++ ){
	    cin >> str;
	    number = getNumber(str);
	    D.insert(number);
	    M[number].push_back(str);
	}
	compute();
    }
}
