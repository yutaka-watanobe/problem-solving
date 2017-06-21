#include<iostream>
using namespace std;

#define MAX 10

struct Guess{
    int value, hit, blow;
};

Guess G[MAX];
int n;

void play( int target, int source, int &hit, int &blow ){
    int t[4], s[4];
    t[3] = target/1000; target %= 1000;
    t[2] = target/100; target %= 100;
    t[1] = target/10; target %= 10;
    t[0] = target;

    s[3] = source/1000; source %= 1000;
    s[2] = source/100; source %= 100;
    s[1] = source/10; source %= 10;
    s[0] = source;
    
    hit = blow = 0;
    for ( int i = 0; i < 4; i++ ){
	if ( t[i] == s[i] ){
	    hit++; t[i] = -1; s[i] = -1;
	}
    }

    for ( int i = 0; i < 4; i++ ){
	if ( s[i] == -1 ) continue;
	for ( int j = 0; j < 4; j++ ){
	    if ( t[j] == -1 ) continue;
	    if ( t[j] == s[i] ){
		s[i] = t[j] = -1;
		blow++;
	    }
	}
    }
}

bool parse( int v ){
    int hit, blow;
    for ( int i = 0; i < n; i++ ){
	play(v, G[i].value, hit, blow);
	if ( !(hit == G[i].hit && blow == G[i].blow) )  return false;
    }
    return true;
}

void compute(){
    int cnt = 0;
    int ans;
    for ( int v = 0; v <= 9999; v++ ){
	if ( parse(v) ){
	    cnt++;
	    ans = v;
	}
    }
    if ( cnt == 0 ) cout << "impossible" << endl;
    else if ( cnt == 1 ){
	cout << ans/1000; ans %= 1000;
	cout << ans/100; ans %= 100;
	cout << ans/10; ans %= 10;
	cout << ans << endl;
    } else {
	cout << "indeterminate" << endl;
    }

}

void input(){
    cin >> n;
    char ch;
    for ( int i = 0; i < n; i++ ){
	cin >> G[i].value >> G[i].hit >> ch >> G[i].blow;
    }
}

int main(){
    /*
    int s, t, h, b;
    while(1){
	cin >> s >> t;
	play( s, t, h, b);
	cout << h << "/" << b << endl;
    }
    */

    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	input();
	compute();
    }
    return 0;
}
