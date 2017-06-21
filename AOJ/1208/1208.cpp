#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int L;
vector<pair<int, int> > R;

double sp;

void sternBrocot(int x=0, int y=1, int z=1, int w=0){
    if ( w > 0 && y > 0&& !(1.0*x/y < sp && sp < 1.0*z/w) ) return;
    int num = x+z;
    int den = y+w;
    if ( num > L || den > L) return;
    sternBrocot(x, y, num, den);
    R.push_back(make_pair(num, den));
    sternBrocot(num, den, z, w);
}

main(){
    int p, n;
    while( cin >> p >> n && p && n ){
	L = n;
	R.clear();
	sp = sqrt(p);
	sternBrocot();
	pair<int, int> r1, r2;
	for ( int i = 0; i < R.size()-1; i++ ){
	    r1 = R[i];
	    r2 = R[i+1];
	    if ( 1.0*r1.first/r1.second < sp &&
		 sp < 1.0*r2.first/r2.second ){
		cout << r2.first << "/" << r2.second << " ";
		cout << r1.first << "/" << r1.second << endl;
	    }
	}
    }
}
