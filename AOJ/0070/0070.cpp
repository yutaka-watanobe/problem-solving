#include<iostream>
using namespace std;

bool used[10];
int n, s, cnt;

void rec( int pos, int sum ){
	if ( pos <= 0 ){
	    if ( sum == s ) cnt++;
	    return;
	}

	if ( sum > s ) return;
	
	int md = 0;
	for ( int i = 1; i <= pos; i++ ) md += i*9;
	if ( md + sum < s ) return;


	for ( int i = 9; i >= 0; i-- ){
	    if ( used[i] ) continue;
	    used[i] = true;
	    rec( pos - 1, sum + pos*i);
	    used[i] = false;
	}

    }
main(){
  
  while( cin >> n >> s ){
    cnt = 0;
    for ( int i = 0; i < 10; i++ ) used[i] = false;	    
    rec(n, 0);
    cout << cnt << endl;
  }
}
