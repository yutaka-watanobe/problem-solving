// DP
#include<iostream>
#include<string>
#include<set>
using namespace std;

#define MAX 300

void compute( string input){
    string str = "";
    set<char> s;
    set<char>::iterator it;
    for ( int i = 0; i < input.size(); i++ ){
	if ( isalpha(input[i]) ) s.insert(input[i]);
    }
    for ( it = s.begin(); it != s.end(); it++ )	str += (*it);

    long long T[26][MAX];
    for ( int i = 0; i < 26; i++ ) {
	for ( int j = 0; j <= str.size(); j++ ){
	    T[i][j] = 0;
	}
    }

    for ( int i = 0; i < str.size(); i++ ){
	T[str[i]-'A'][1] = 1;
    }

    for ( int j = 2; j <= str.size(); j++ ){
	for ( int i = 0; i < 26; i++ ){
	    if ( T[i][1] == 0 ) continue;
	    int target = i+1;
	    for ( int k = i-1; k >= 0; k-- ){
		int source = k+1;
		if ( 5 * source <= 4 * target ){
		    T[i][j] += T[k][j-1];
		}
	    }
	}
    }

    int len;

    for ( len = str.size(); len >= 1; len-- ){
	for ( int i = 25; i >= 0; i-- ){
	    if ( T[i][len] ){
		int sum = 0;
		for ( int a = 0; a < 26; a++ ) sum += T[a][len];
		cout << len << " " << sum << endl;
		return;
	    }
	}
    }
}

int main(){
    int tcase; cin >> tcase;
    string input;
    getline(cin, input);
    for ( int i = 0; i < tcase; i++ ){
	getline(cin, input);
	compute(input);
    }
    return 0;
}
