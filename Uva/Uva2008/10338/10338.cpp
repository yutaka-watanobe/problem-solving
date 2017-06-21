#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long llong;

llong F[21];

void init(){
    F[0] = 1;
    for ( int i = 1; i <= 20; i++ ) F[i] = F[i-1]*i;
}

llong compute(){
    int C[26];
    for ( int i = 0; i < 26; i++ ) C[i] = 0;
    string str; cin >> str;
    for ( int i = 0; i < str.size(); i++ ) C[str[i]-'A']++;
    llong ans = F[(int)str.size()];
    for ( int i = 0; i < 26; i++ ){
	if ( C[i] ){
	    ans /= F[C[i]];
	}
    }
    return ans;
}

int main(){
    int tcase; cin >> tcase;
    init();

    for ( int i = 1; i <= tcase; i++ ){
	cout << "Data set " << i << ": " << compute() << endl;
    }
    return 0;
}
