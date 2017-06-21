#include<iostream>
#include<string>
#define rep(i, n) for ( int i = 0; i < n; i++ )
using namespace std;
#define MAX 100
/*
  4
3 0 2 5
  1
 */
class Cube{
    public:
    int f[6];
    Cube(){
	f[4] = 1; f[0] = 3;f[1] = 6; f[2] = 5; f[5] = 4; f[3] = 2;
    }
    void roll(int i, int j, int k, int l){
	int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }

    void roll_front(){ roll(0, 4, 5, 1);} // roll_x * 3;
    void roll_back(){ rep(i, 3) roll_front();}
    void roll_right(){ roll(1, 2, 4, 3);}
    void roll_left(){ rep(i, 3) roll_right();}

    void init(int top, int front){
	rep(i, 6){
	    rep(j, 4){
		if ( top == f[4] && front == f[0] ) return;
		roll(1, 2, 4, 3); //z
	    }
	    if ( i % 2 == 0 ) roll(0, 2, 5, 3);//y
	    else roll(0, 1, 5, 4);//x
	}
    }
};

void simulate(int n){
    static const int N = 205;
    int t, f;
    int T[N][N], H[N][N];
    rep(i, N) rep(j, N)	T[i][j] = H[i][j] = 0;
    
    rep(i, n){
	cin >> t >> f;
	Cube c = Cube();
	c.init(t, f);
	int pi = 100;
	int pj = 100;
	
	bool rolled = true;
	while(rolled){
	    int dir = -1;
	    static const int di[4] = {0, 1, 0, -1};
	    static const int dj[4] = {-1, 0, 1, 0};
	    static const int fd[4] = {3, 0, 2, 5};
	    static const int td[3] = {4, 5, 6};
	    rep(t, 3) rep(r, 4){
		if ( td[t] == c.f[fd[r]] && H[pi][pj] > H[pi+di[r]][pj+dj[r]]) dir = r;
	    }
	    if ( dir == 0 ){ c.roll_left(); pj--; }
	    else if ( dir == 1 ){ c.roll_front(); pi++; }
	    else if ( dir == 2 ){ c.roll_right(); pj++; }
	    else if ( dir == 3 ){ c.roll_back(); pi--; }
	    rolled = (dir != -1);	    
	}
	H[pi][pj]++;
	T[pi][pj] = c.f[4];
    }

    int cnt[7];
    rep(i, 7) cnt[i] = 0;
    rep(i, N) rep(j, N) cnt[T[i][j]]++; 
    for ( int i = 1; i <= 6; i++ ){
	if ( i > 1 ) cout << " ";
	cout << cnt[i];
    }
    cout << endl;
}

main(){
    int n;
    while( cin >> n , n) simulate(n);
}



