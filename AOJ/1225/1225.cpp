#include<iostream>
#include<string>
#include<map>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )
#define MAX 1000
#define INFTY (1<<21)

class Deal{
    public:
    string name, type;
    char item;
    int value;

    Deal(string n="", string t="", char i=' ', int v=0): name(n), type(t), item(i), value(v){}
};

Deal D[MAX];
int n;
map<string, pair<int, int> > P;

void compute(){
    int maxd[26], mind[26], totald[26], cnt[26], maxv, minv, mi;
    rep(i, 26) { 
	maxd[i] = -1;
	mind[i] = INFTY;
	totald[i] = 0;
	cnt[i] = 0;
    }

    bool used[MAX];
    rep(i, n) used[i] = false;

    for ( int cur = 0; cur < n; cur++ ){
	maxv = mi = -1;
	minv = INFTY;
	for ( int i = 0; i < cur; i++ ){
	    if ( used[i] ) continue;
	    if ( D[cur].item != D[i].item ) continue;
	    if ( D[cur].name == D[i].name ) continue;
	    if ( D[cur].type == "SELL" && D[i].type == "BUY"){
		if ( D[cur].value <= D[i].value && maxv < D[i].value ){
		    maxv = D[i].value;
		    mi = i;
		}
	    } else if ( D[cur].type == "BUY" && D[i].type == "SELL" ){
		if ( D[cur].value >= D[i].value && minv > D[i].value ){
		    minv = D[i].value;
		    mi = i;
		}
	    }
	}

	if ( mi == -1 ) continue;
	if ( D[cur].type == "SELL"){
	    int d = (maxv + D[cur].value)/2;
	    totald[D[cur].item - 'A'] += d;
	    maxd[D[cur].item - 'A'] = max( d,  maxd[D[cur].item - 'A']);
	    mind[D[cur].item - 'A'] = min( d,  mind[D[cur].item - 'A']);
	    cnt[D[cur].item - 'A']++;
	    P[D[cur].name].second += d;
	    P[D[mi].name].first += d;
	} else {
	    int d = (minv + D[cur].value)/2;
	    totald[D[cur].item - 'A'] += d;
	    maxd[D[cur].item - 'A'] = max( d,  maxd[D[cur].item - 'A']);
	    mind[D[cur].item - 'A'] = min( d,  mind[D[cur].item - 'A']);
	    cnt[D[cur].item - 'A']++;
	    P[D[cur].name].first += d;
	    P[D[mi].name].second += d;
	}
	used[mi] = used[cur] = true;
    }

    for ( int i = 0; i < 26; i++ ){
	if ( totald[i] == 0 ) continue;
	cout << (char)('A' + i) << " " <<  mind[i] << " " << totald[i]/cnt[i] << " " << maxd[i] <<endl;
    }
    cout << "--" << endl;
    for ( map<string, pair<int, int> >::iterator it = P.begin(); it != P.end(); it++ ){
	string name = (*it).first;
	pair<int, int> p = (*it).second;
	cout << name << " " << p.first << " " << p.second << endl;
    }
    cout << "----------" << endl;
}


main(){
    while( cin >> n && n ){
    P = map<string, pair<int, int> >();
	rep(i, n){
	    cin >> D[i].name >> D[i].type >> D[i].item >> D[i].value;
	    P[D[i].name] = make_pair(0, 0);
	}
	compute();
    }
}
