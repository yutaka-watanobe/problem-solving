#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define MAX 1000
#define AMAX 100

class Team{
    public:
    int id, aff, acc, pen;
    Team( int i = 0, int f = 0, int a = 0, int p = 0 ):
	id(i), aff(f), acc(a), pen(p){}

    bool operator < ( const Team &t ) const {
	if ( acc == t.acc ){
	    if ( pen == t.pen ) {
		return id < t.id;
	    } else return pen < t.pen;
	} else return acc > t.acc;
    }
};

Team T[MAX];
int n;

void compute(){
    sort( T, T + n );
    int selected[AMAX] = {0};
    
    int nselected = 0;

    for ( int i = 0; i < n; i++ ){
	int aff = T[i].aff;
	int id = T[i].id;
	if ( nselected < 10 ){
	    if ( selected[aff] < 3 ){
		nselected++;
		selected[aff]++;
		cout << id << endl;
	    }
	} else if ( nselected < 20 ){
	    if ( selected[aff] < 2 ){
		nselected++;
		selected[aff]++;
		cout << id << endl;
	    }
	} else if ( nselected < 26 ){
	    if ( selected[aff] == 0 ){
		nselected++;
		selected[aff]++;
		cout << id << endl;
	    }
	}
    }


}

main(){
    while ( cin >> n &&  n ){
	for ( int i = 0; i < n; i++ ){
	    cin >> T[i].id >> T[i].aff >> T[i].acc >> T[i].pen;
	    assert( 1 <= T[i].id && T[i].id <= 1000 );
	    assert( 1 <= T[i].aff && T[i].aff <= 1000 );
	}
	compute();
    }
}
