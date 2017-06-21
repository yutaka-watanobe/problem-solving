#include<iostream>
using namespace std;

void convert(int x, int b){
    if ( x == 0 ) return;
    int p, l = x%10;
    if ( l < 0 ) l *= -1;
    if ( l == 0 ){
	p = 0;
    } else if ( x*b < 0 ){
	p = 10-l;
	x -= b*10;
    } else {
	p = l;
    }
    convert(x/10, b*(-1));
    cout << p;
}

main(){
    int x;
    while(1){
      cin >> x;
      if ( x== 0 ) break;
	convert(x, 1);
	cout << endl;
    }
}
