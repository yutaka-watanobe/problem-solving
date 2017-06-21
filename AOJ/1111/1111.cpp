#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MAX 1024

class Rule{
    public:
    bool permit;
    char s[16];
    Rule(bool p=false):permit(p){}

    void check(string a, bool &acc){
	rep(i, 16){
	    if ( s[i] == '?' ) continue;
	    if ( s[i] != a[i]) return;
	}
	acc = permit;
    }

};
int n, m;
Rule R[MAX];

bool accept(string s){
    bool acc = false;
    rep(i, n) R[i].check(s, acc);
    return acc;
}

main(){
    string p, s, d;
    while( cin >> n >> m){
	if ( n == 0 && m == 0 ) break;
	rep(i, n){
	    cin >> p >> s >> d;
	    R[i] = Rule( p=="permit");
	    rep(a, 8) R[i].s[a] = s[a];
	    rep(a, 8) R[i].s[a+8] = d[a];
	}
	vector<pair<pair<string, string>, string> > ans;
	rep(i, m){
	    cin >> s >> d >> p;
	    if ( accept(s+d) ) ans.push_back(make_pair(make_pair(s, d), p));
	}
	cout << ans.size() << endl;
	rep(i, ans.size()){
	    cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
	    
	}
    }
}
