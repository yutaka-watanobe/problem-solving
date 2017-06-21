#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define MAX 4001

string str1, str2;

void lcs(){
    int T[MAX], NT[MAX];
    int h = str1.size();
    int w = str2.size();

    for ( int j = 0; j <= w; j++ ) T[j] = 0;

    int ans = 0;
    for ( int i = 1; i < h; i++ ){
	for ( int j = 1; j < w; j++ ){
	    if ( str1[i] == str2[j] ){
		NT[j] = T[j-1] + 1;
		ans = max(ans, NT[j]);
	    } else {
		NT[j] = 0;
	    }
	}
	for ( int j = 1; j < w; j++ ) T[j] = NT[j];
    }
    cout << ans << endl;
}

main(){
    while( cin >> str1 ){
	cin >> str2;
	str1 = ' ' + str1;
	str2 = ' ' + str2;
	lcs();
    }
}
