#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define NMAX 20
#define MMAX 100
#define KMAX 10

struct Menue{ string name; int limit; int rtime;};
class Order{
    public:
    int atime, k, nf;
    string D[KMAX];
    bool F[KMAX];
    Order(){
	
    }
};

int n, m;
Menue M[NMAX];
Order O[MMAX];

void simulate(){

}

main(){
    while(1){
	cin >> n >> m;
	if ( n == 0 && m == 0 ) break;
	rep(i, n) cin >> M[i].name >> M[i].limit >> M[i].rtime;
	rep(i, m){
	    cin >> O[i].atime >> O[i].k;
	    rep(j, O[i].k) {
		cin >> O[i].D[j];
		O[i].F[j] = false;
	    }
	    O[i].nf = 0;
	}
	simulate();
    }
}
