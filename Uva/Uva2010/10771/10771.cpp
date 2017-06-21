#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
#define MAX  2000

int n, m, k, s, pos;
vector<char> T;

void next(){
  pos = (pos+k)%(T.size());

}

void pre(){
    if ( pos == 0 ) pos = T.size()-1;
    else pos--;
}
void simulate(){
    T.clear();
    s = n + m;
    for ( int i = 0; i < n ; i++ ) T.push_back('G');
    for ( int i = 0; i < m; i++ ) T.push_back('K');

    pos = -1;

    char ch;
    for ( int step = 0; step < s-1; step++ ){
	next();
	char ch = T[pos];
	T.erase(T.begin() + pos);	
	pre();
	next();
	if ( T[pos] == ch ) T[pos] = 'G';
	else T[pos] = 'K';
    }
    if ( T[0] == 'K' ) cout << "Keka" << endl;
    else if ( T[0] == 'G' )cout << "Gared" << endl;
    else assert(false);
    
}

main(){
    while(1){
	cin >> n >> m >> k;
	if ( n == 0 && m == 0 && k == 0 ) break;
	simulate();
    }
}
