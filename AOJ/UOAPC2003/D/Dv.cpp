#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define N 5

vector<int> expression();
vector<int> term();

vector<int> S[N];
vector<int> U;

int p;
string exp;

vector<int> intersect(vector<int> s1, vector<int> s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector<int> r;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

vector<int> _union(vector<int> s1, vector<int> s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector<int> r;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

vector<int> difference(vector<int> s1, vector<int> s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector<int> r;
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

vector<int> symmetric(vector<int> s1, vector<int> s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector<int> r;
    set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

vector<int> complement(vector<int> s1){
    sort(s1.begin(), s1.end());
    sort(U.begin(), U.end());
    vector<int> r;
    set_difference(U.begin(), U.end(), s1.begin(), s1.end(), inserter(r,r.begin()));
    return r;
}

bool isOperator(char ch){
    return (ch == 'u' || ch == 'i' || ch == 'd' || ch == 's' );
}

vector<int> expression(){
    vector<int> s = term();

    while( isOperator(exp[p]) ){
	if ( exp[p] == 'u' ) { p++; s = _union(s, term()); }
	else if ( exp[p] == 'i' ) { p++; s = intersect(s, term()); }
	else if ( exp[p] == 'd' ) { p++; s = difference(s, term()); }
	else if ( exp[p] == 's' ) { p++; s = symmetric(s, term()); }
    }
    
    return s;
}

vector<int> term(){
    vector<int> s;
    char name;
    if ( exp[p] == 'c' ){
	p++; 
	name = exp[p++]; 
	return complement( S[name-'A'] );
    } else if ( exp[p] == '(' ){
	p++; s = expression(); p++;
	return s;
    } else {
	name = exp[p++];
	return S[name-'A'];
    }
}

void compute(){
    for ( int i = 0; i < 5; i++ ) S[i].clear();
    U.clear();

    char name;
    int n, x;
    while(1){
	cin >> name >> n;
	if ( name == 'R' ) break;
	for ( int i = 0; i < n; i++ ){
	    cin >> x;
	    S[name-'A'].push_back(x);
	    U.push_back(x);
	}
    }

    int p = 0;
    cin >> exp;

    vector<int> result = expression();

    for ( int i = 0; i < result.size(); i++ ){
	if ( i ) cout << " ";
	cout << result[i];
    }
    cout << endl;
}

int main(){
    compute();
}
