#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

#define N 5

set<int> expression();
set<int> term();

set<int> S[N];
set<int> U;

int p;
string exp;

set<int> intersect(set<int> s1, set<int> s2){
    set<int> r;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

set<int> _union(set<int> s1, set<int> s2){
    set<int> r;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

set<int> difference(set<int> s1, set<int> s2){
    set<int> r;
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

set<int> symmetric(set<int> s1, set<int> s2){
    set<int> r;
    set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(r, r.begin()));
    return r;
}

set<int> complement(set<int> s1){
    set<int> r;
    set_difference(U.begin(), U.end(), s1.begin(), s1.end(), inserter(r,r.begin()));
    return r;
}

bool isOperator(char ch){
    return (ch == 'u' || ch == 'i' || ch == 'd' || ch == 's' );
}

set<int> expression(){
    set<int> s = term();

    while( isOperator(exp[p]) ){
	if ( exp[p] == 'u' ) { p++; s = _union(s, term()); }
	else if ( exp[p] == 'i' ) { p++; s = intersect(s, term()); }
	else if ( exp[p] == 'd' ) { p++; s = difference(s, term()); }
	else if ( exp[p] == 's' ) { p++; s = symmetric(s, term()); }
    }
    
    return s;
}

set<int> term(){
    set<int> s;
    char name;
    if ( exp[p] == 'c' ){
	p++; 
	//name = exp[p++]; 
	//return complement( S[name-'A'] );
	return complement( term() );
    } else if ( exp[p] == '(' ){
	p++; s = expression(); p++;
	return s;
    } else {
	name = exp[p++];
	return S[name-'A'];
    }
}

bool compute(){
    for ( int i = 0; i < 5; i++ ) S[i].clear();
    U.clear();

    char name;
    int n, x;
    while(1){
	cin >> name >> n;
	if ( cin.eof() ) return false;
	if ( name == 'R' ) break;
	for ( int i = 0; i < n; i++ ){
	    cin >> x;
	    S[name-'A'].insert(x);
	    U.insert(x);
	}
    }

    p = 0;
    cin >> exp;

    set<int> result = expression();
    set<int>::iterator it;
    if ( result.size() == 0 ) cout << "NULL" << endl;
    else{
      for ( it = result.begin(); it != result.end(); it++ ) {
	if ( it != result.begin() ) cout << " ";
	cout << *it;
      }
      cout << endl;
    }
    return true;
}

int main(){
  while(compute());
}




