#include<iostream>
using namespace std;

int cnt, n, s;
bool used[10];

void rec(int pos, int t, int sum ){
    if ( t == n ){
	if ( sum == s ) cnt++;
	return;
    }
    if ( pos > 9 ) return;

    rec(pos+1, t, sum);
    rec(pos+1, t+1, sum + pos);
}   
 
main(){
    while( cin >> n >> s ){
	if ( n == 0 && s == 0 ) break;
	cnt = 0;
	rec(0,  0, 0);
	cout << cnt << endl;
    }
}
