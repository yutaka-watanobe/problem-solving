#include<iostream>
#include<cfloat>
using namespace std;

#define NMAX 30
#define MMAX 10
#define TO_TARGET 0
#define TO_FLOOR 1
#define STOP 2

class Elevator{
    private:
    int cap, vel, pos, stopt;
    int state;
    public:
    Elevator(){}
    Elevvator( int c, int v, int p, int s): cap(c), vel(v), pos(p), stopt(s){
	state = TO_TARGET;
    }

    double getEstimatedTime(){

    }

    void activate(double t){

    }
};

int ndata[NMAX];
Elevator elevators[MMAX];
int N, M, dist, k, tx, ty, tz;
int total, saved;

void simulate(){
    double elaps = 0.0;
    int elv;
    double stime;

    saved = 0;

    while(1){
	getShortest(elv, stime);

	if (stime == FLT_MAX ) break;

	for ( int i = 0; i < N; i++ ){
	    elevators[i].activate(stime);
	}
    }

    printf("%d %.6lf\n", saved, elaps);
}

bool input(){
    int c, v, t, x;
    cin >> N >> M;

    if ( N == 0 ) return false;

    cin >> dist;

    total = 0;
    for ( int i = 0; i < N; i++ ){
	cin >> ndata[i];
	total += ndata[i];
    }

    for ( int i = 0; i < N; i++ ){
	cin >> c >> v >> t >> x;
	elevators[i] = Elevator( c, v, t, x );
    }

    cin >> k >> tx >> ty >> tz;
}

main(){
    while( input() ) simulate();
}
