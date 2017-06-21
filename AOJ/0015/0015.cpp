#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

main(){
    int tcase, m; cin >> tcase;
    string s1, s2, s3;
    for ( int i = 0; i < tcase; i++ ){
	cin >> s1 >> s2; s3 = "";
	m = max(s1.size(), s2.size());
	while( s1.size() < m ) s1 = '0' + s1;
	while( s2.size() < m ) s2 = '0' + s2;
	int c = 0;
	for ( int i = m-1; i >= 0; i-- ){
	    char ch = ((s1[i]-'0')+(s2[i]-'0')+c)%10 + '0';
	    c = ((s1[i]-'0')+(s2[i]-'0')+c)/10;
	    s3 += ch;
	}
	if ( c ) s3 += c+'0';
	reverse(s3.begin(), s3.end());
	while( s3.size() > 1 && s3[0] == '0' ) s3.erase(s3.begin());
	if ( s3.size() > 80 ) cout << "overflow" << endl;
	else cout << s3 << endl;
    }
}
