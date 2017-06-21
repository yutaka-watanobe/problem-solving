#include<iostream>

using namespace std;

#define MAX 1000

int n, cnt;

int dfs( int d ){
    cnt++;
    int back = 1;
    for ( int r = 0; r < 3; r++ ){
	int m = max(d+1, back+1);
	if ( m <= n ){   
	    back = max(back, dfs( m )+1);
	}
    }
    return back;
}
 
void compute(){
    cnt = 0;
    dfs(1);
    cout << cnt << endl;
}

int main(){
    while( cin >> n ) compute();
    return 0;
}
