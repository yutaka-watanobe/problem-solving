#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
#define INFTY (1<<21)
int target;
string source;
vector<vector<string> > ans;
int diff;

void update(vector<int> c ){
    vector<string> s;
    for ( int i = 0; i < c.size()-1; i++ ){
	s.push_back(source.substr(c[i], c[i+1]-c[i]));
    }
    int sum = 0;
    for ( int i = 0; i < s.size(); i++ ) sum += atoi(s[i].c_str());

    if ( sum > target ) return;

    if ( target - sum == diff ){
	ans.push_back(s);
    } else if ( target - sum < diff ){
	diff = target - sum;
	ans.clear();
	ans.push_back(s);
    }
}

void rec(int pos, vector<int> c){
    if ( pos == source.size() ){
	c.push_back(pos);
	update(c);
	return;
    }
    rec(pos+1, c);
    c.push_back(pos);
    rec(pos+1, c);
}

void compute(){
    vector<int> c;
    c.push_back(0);
    diff = INFTY;
    ans.clear();
    rec(1, c);

    if ( diff == INFTY ) cout << "error" << endl;
    else if ( ans.size() > 1 ) cout << "rejected" << endl;    
    else { 
	cout << target - diff;
	for ( int i = 0; i < ans[0].size(); i++ ) cout << " " << ans[0][i];
	cout << endl;
    }
}

main(){
    while( cin >> target >> source){
	if ( target == 0 && source == "0" ) break;
	compute();
    }
}
