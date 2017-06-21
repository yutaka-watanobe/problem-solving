#include<iostream>
#include<string>
using namespace std;
#define MAX 70

int getMatch(string s1, string s2){
    int size1 = s1.size();
    int size2 = s2.size();
    int i, j, cnt;
    int maxm = 0;
    for ( int s = 0; s < size2; s++ ){
	cnt = 0;
	for ( i = 0, j = s; i < size1 && j < size2; i++, j++ ){
	    if ( s1[i] == s2[j] ) cnt++;
	}
	maxm = max(maxm, cnt);
    }
    for ( int s = 1; s < size1; s++ ){
	cnt = 0;
	for ( j = 0, i = s; i < size1 && j < size2; i++, j++ ){
	    if ( s1[i] == s2[j] ) cnt++;
	}
	maxm = max(maxm, cnt);
    }
    return maxm;
}

void compute(){
    string S[MAX];
    int n; cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> S[i];

    int maxm = 0;
    for ( int i = 0; i < n-1; i++ ){
	for ( int j = i+1; j < n; j++ ){
	    maxm = max( maxm, getMatch(S[i], S[j]) );
	}
    }
    cout << maxm << endl;
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) compute();
    return 0;
}
