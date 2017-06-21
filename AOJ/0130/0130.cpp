#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void compute(string line){
    char buffer[2100];
    int p = 1025;
    int l = p, r = p;
    buffer[p] = line[0];
    for ( int i = 3; i < line.size(); i+=3 ){
	if ( line[i-1] == '>' ) p++;
	else p--;
	buffer[p] = line[i];
	l = min(l, p); r = max(r, p);
    }
    for ( int i = l; i <= r; i++ ) cout << buffer[i];
    cout << endl;
}

main(){
    int tcase; cin >> tcase;
    string line;
    for ( int i = 0; i < tcase; i++ ) { cin >> line; compute(line); }
}
