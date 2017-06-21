#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 10
int n;
int source[MAX], target[MAX];
int ans = (1<<21);

void shift(int str[MAX], int s, int e){
    while(1){
	if ( str[s] == target[s] ) break;
	for ( int j = s; j <= e; j++ ){
	    str[j] = (str[j]+1)%10;
	}
    }
}

bool equals( int s1[MAX], int s2[MAX] ){
    for ( int i = 0; i < n; i++ ) if ( s1[i] != s2[i] ) return false;
    return true;
}
void rec(int s[MAX], int pos, int cnt){

    if ( equals(s, target) ){
	ans = min(ans, cnt);
	return;
    }
    if ( pos >= n ) return;
    if ( cnt >= ans ) return;

    for ( int end = pos; end <= n-1; end++ ){
	int next[MAX];
	for ( int i = 0; i < n; i++ ) next[i] = s[i];

	if ( s[pos] == target[pos] ){
	    rec(next, pos+1, cnt);
	} else {
	    shift(next, pos, end);
	    rec(next, pos+1, cnt+1);
	}
    }
}

main(){
    string s1, s2;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	cin >> s1 >> s2;
	for ( int i = 0; i < n; i++ ){
	    source[i] = s1[i] - '0';
	    target[i] = s2[i] - '0';
	}
	ans = (1<<21);
	rec(source, 0, 0);
	cout << ans << endl;
    }
}
