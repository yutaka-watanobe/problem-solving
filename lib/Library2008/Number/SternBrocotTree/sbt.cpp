// AOJ 1208
#include<iostream>
using namespace std;

int L;

void sternBrocot(int x=0, int y=1, int z=1, int w=0){
    int num = x+z;
    int den = y+w;
    if ( num > L || den > L) return;
    sternBrocot(x, y, x+z, y+w);
    cout << num << "/" << den << endl;
    sternBrocot(x+z, y+w, z, w);
}

main(){
    cin >> L;
    sternBrocot();
}
