#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cmath>
#include<cassert>
#include<sstream>

using namespace std;

#define REP(i, b, e) for( int i = b; i < e; i++ )
#define rep(i, n) REP(i, 0, n)

static int T[5] = {9, 4, 4, 4, 7};

void compute(vector<string> lines){
    double total[5];
    rep(i, 5) total[i] = 0;

    for ( int i = 0; i < lines.size(); i++ ){
	double tmp[5];
	double tmp2[5];
	rep(a, 5) tmp[a] = tmp2[a] = 0;
	stringstream sin(lines[i]);
	int v;
	char u;
	int p = 0;
	double pu;
	for ( int j = 0; j < 5; j++ ) {
	    sin >> v >> u;
	    if ( u == 'g' ) tmp[j] += T[j]*v;
	    else if ( u == 'C' ) tmp[j] += v;
	    else if ( u == '%' ) { p += v; tmp2[j] = v; }
	    else assert(false);
	}

	double sum = 0;
	rep(j, 5) sum += tmp[j];
	pu = sum/(100-p);
	for ( int j = 0; j < 5; j++ ){
	    tmp[j] += pu*tmp2[j];
	}

	//rep(j, 5) cout << tmp[j] << " ";
	//cout << endl;

	rep(j, 5) total[j] += tmp[j];
    }

    double t = 0.0;
    rep(j, 5) t += total[j];
    
    printf("%d%%\n", (int)(100*total[0]/t+0.5));

}

main(){
    string line;
    vector<string> lines;
    while(1){
	lines.clear();
	while(1){
	    getline(cin, line);
	    if ( line == "-" ) break;
	    lines.push_back(line);
	}
	if ( lines.size() ==  0 ) break;
	compute(lines);
    }
}
