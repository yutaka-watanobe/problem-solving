#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    if ( b == 0 ) return a;
    return gcd(b, a%b);
}

int getNumber(){
    int n, f;
    char ch;
    cin >> n >> ch >> f;
    return 10*n + f;
}

void compute(){
    int x1, x2, y1, y2, dx, dy, w, h, g;
    x1 = getNumber();
    y1 = getNumber();
    x2 = getNumber();
    y2 = getNumber();
    w = max(x1, x2) - min(x1, x2);
    h = max(y1, y2) - min(y1, y2);
    g = gcd(w, h);
    dx = (x2-x1)/g;
    dy = (y2-y1)/g;

    int px = x1;
    int py = y1;
    int cnt = 0;
    while(1){
	if ( px % 10 == 0 && py % 10 == 0 ) cnt++;
	if ( px == x2 && py == y2 ) break;
	px += dx;
	py += dy;
    }

    cout << cnt << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int t = 1; t <= tcase; t++ ) compute();
}
