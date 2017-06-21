#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10
class Team{
    public:
    char name;
    int id, win, defeat, draw;
    Team( int id=0, char name=' ', int win=0, int defeat=0, int draw=0 ): id(id), name(name), win(win), defeat(defeat), draw(draw){}
    bool operator < ( const Team &t ) const{
	if ( win == t.win ){
	    if ( defeat == t.defeat ) return id < t.id;
	    else return defeat < t.defeat;
	} else return win > t.win;
    }
};

main(){
    Team T[MAX];
    int n, x;
    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ) {
	    T[i] = i;
	    cin >> T[i].name;
	    T[i].defeat = T[i].win = T[i].draw = 0;
	    for ( int j = 0; j < n-1; j++ ){
		cin >> x;
		if ( x == 0 ) T[i].win++;
		else if ( x == 1 ) T[i].defeat++;
		else if ( x == 2 ) T[i].draw++;
	    }
	}
	stable_sort( T, T + n );
	for ( int i = 0; i < n; i++ ){
	    cout << T[i].name << endl;
	}
    }
}
