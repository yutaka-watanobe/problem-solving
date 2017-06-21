#include<iostream>
using namespace std;
#define rep(i, n) for ( int i = 0; i< n; i++ )

class Cube{
    public:
    int f[6];
    Cube(){}
    void roll_z(){ roll(1, 2, 4, 3);}
    void roll_y(){ roll(0, 2, 5, 3);}
    void roll_x(){ roll(0, 1, 5, 4);}
    void roll(int i, int j, int k, int l){
	int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }
};

void make( Cube c1){
  int n = 0;
    rep(i, 6){
	rep(j, 4){
	  cout << "\"";
	  rep(k, 6) cout << c1.f[k];
	  cout << "\"";
	  cout << ",";
	  c1.roll_z();
	}
	if ( i % 2 == 0 ) c1.roll_y();
	else c1.roll_x();
    }
}

main(){
  Cube c1;
  for ( int i = 0; i < 6; i++ ) c1.f[i] = i+1;
  make(c1);
}

