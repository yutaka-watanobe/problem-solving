#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int L;

double sp;

void sternBrocot(int x=0, int y=1, int z=1, int w=0){
  //    if ( w > 0 && y > 0&& !(1.0*x/y < sp && sp < 1.0*z/w) ) return;
    int num = x+z;
    int den = y+w;
    if ( num > L || den > L) return;
    sternBrocot(x, y, num, den);
    cout << num << "/" << den << endl;
    sternBrocot(num, den, z, w);
}

main(){
    while( cin >> L ){
	cout << "--------------" << endl;
	sternBrocot();
    }
}
