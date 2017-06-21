#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)

bool T[256];
int P[256];

vector<string> compute(string text, string key){

    vector<string> ans;
    int k = key.size();
    rep(i, 256) P[i] = -1;
    int l = text.size();
    int r = -1;

    rep(i, 256) T[i] = false;
    rep(i, k) T[key[i]] = true;

    rep(i, k){
	rep(j, text.size()){
	    if ( key[i] == text[j] ) { 
		P[key[i]] = j; 
		l = min(l, j);
		r = max(r, j);
		break; 
	    }
	}
    }
    rep(i, k) if ( P[key[i]] == -1 ) return ans;
    for ( int i = l; i <= r; i++ ){
	if ( T[text[i]] ){
	    if ( P[text[i]] < i ) P[text[i]] = i;
	}
    }

    ans.push_back(text.substr(l, r-l+1));

    for ( int i = r+1; i < text.size(); i++ ){
	char ch = text[i];
	if ( T[ch] ){
	    r = i;
	    P[ch] = i;
	    l = r;
	    rep(t, k){
		if ( T[key[t]] ){
		    l = min(l, P[key[t]]);
		}
	    }
	    string c = text.substr(l, r-l+1);
	    if ( ans[0].size() == c.size() ) ans.push_back(c);
	    else if ( ans[0].size() > c.size() ){
		ans.clear();
		ans.push_back(c);
	    }
	}
    }

    return ans;
}

void output(string line){
    rep(i, line.size()){
	if ( i % 72 == 0 && i != 0 ) cout << endl;
	cout << line[i];
    }
    cout << endl;

}

main(){
    string text, line, key;
    while(1){
	text = "";
	while(1){
	    getline(cin, line);
	    if ( line.size() == 0 ) break;
	    text += line;
	}
	if ( text == "" ) break;
	getline(cin, key);
	getline(cin, line);
	vector<string> ans = compute(text, key);
	cout << ans.size() << endl;
	if ( ans.size() > 0 ){
	    cout << endl;
	    output(ans[0]);
	}
	cout << endl;
    }
}
