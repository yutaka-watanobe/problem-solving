#include<iostream>
using namespace std;

void print(int x){
    if ( x < 10 ) cout << 0;
    cout << x;
}

main(){
    int tcase; cin >> tcase;
    char ch;
    int h, m;
    for ( int i = 0; i < tcase; i++ ){
	cin >> h >> ch >> m;

	int t = 1440 - (60*h + m);
	
	h = t/60;
	m = t%60;

	if ( h > 12 ) h %= 12;

	print(h); cout << ":"; print(m); cout << endl;
    }
}
