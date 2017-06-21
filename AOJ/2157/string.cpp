#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
string source, target;

int ans = (1<<21);

string shift(string str, int s, int e){
    while(1){
	if ( str[s] == target[s] ) break;
	for ( int j = s; j <= e; j++ ){
	    if ( str[j] == '9' ) str[j] = '0';
	    else str[j]++;
	}
    }
    return str;
}

void rec(string s, int pos, int cnt){

    if ( s == target ){
	ans = min(ans, cnt);
	return;
    }
    if ( pos >= n ) return;
    if ( cnt >= ans ) return;
    //    if ( pos ){
    //	if ( s.substr(0, pos) != target.substr(0, pos) ) return;
    //    }

    for ( int end = pos; end <= n-1; end++ ){
	string next = s;
	if ( s[pos] == target[pos] ){
	    rec(next, pos+1, cnt);
	} else {
	    next = shift(s, pos, end);
	    rec(next, pos+1, cnt+1);
	}
    }


    

}

main(){
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	cin >> source >> target;
	ans = (1<<21);
	rec(source, 0, 0);
	cout << ans << endl;
    }
}
