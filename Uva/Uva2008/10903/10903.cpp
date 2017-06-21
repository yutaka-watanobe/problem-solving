#include<iostream>
#include<string>
using namespace std;
static const int MAX = 100;

int n, win[MAX+1], loose[MAX+1];

int judge( string h1, string h2 ){
    if ( h1 == "rock" ){
	if ( h2 == "scissors" ) return 1;
	if ( h2 == "paper" ) return 2;
    } else if ( h1 == "paper" ){
	if ( h2 == "rock" ) return 1;
	if ( h2 == "scissors" ) return 2;
    } else if ( h1 == "scissors" ){
	if ( h2 == "paper" ) return 1;
	if ( h2 == "rock" ) return 2;
    }
    return 0;
}

void compute(){
    for ( int i = 1; i <= n; i++ ){
	win[i] = loose[i] = 0;
    }

    int k, p1, p2;
    string h1, h2;
    cin >> k;
    k = k*n*(n-1)/2;
    for ( int i = 0; i < k; i++ ){
	cin >> p1 >> h1 >> p2 >> h2;
	int j = judge(h1, h2);
	if ( j == 1 ) {
	    win[p1]++; loose[p2]++;
	} else if (j == 2) {
	    win[p2]++; loose[p1]++;
	}
    }

    for ( int i = 1; i <= n; i++ ){
	if ( win[i] + loose[i] == 0 ) cout << "-" << endl;
	else printf("%.3lf\n", 1.0*win[i]/(win[i]+loose[i]));
    }
}

main(){
    for ( int i = 0; cin >> n && n; i++ ){
	if ( i ) cout << endl;
	compute();
    }
}
