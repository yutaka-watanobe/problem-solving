#include<iostream>
#include<queue>
#include<cassert>
#include<climits>
using namespace std;
#define REP(i, n) for ( int i = 0; i < (int)n; i++ )
#define CMAX 10 // cap max

class Car{
    public:
    int id, stay, back;
    Car(){}
    Car(int id, int stay): id(id), stay(stay){}
};

int cap, ncar;
bool isfull;

Car P[CMAX][2];
int incar, C[CMAX];
bool isfast;

bool isFull(){
    return incar == cap*2;
}

void deq(int id, int i ){
    if (isfast) isfast = false;
    else cout << " ";
    cout << id;
    C[i]--; incar--;
}

void dequeue(int current){
    if ( incar == 0 ) return;

    for ( int i = 0; i < cap; i++ ){
	if ( C[i] == 0 ) continue;
	if ( P[i][0].back <= current ){
	    deq(P[i][0].id, i);
	    if ( C[i] == 0 ) continue;
	    P[i][0] = P[i][1];
	    if ( P[i][0].back <= current ){
		deq(P[i][0].id, i);
	    }
	}
    }
}

void enqueue( Car car ){
    int target = -1;
    for ( int i = 0; i < cap; i++ ){
	if ( C[i] == 0 ) {target = i; break;}
    }
    if ( target != -1 ) { 
	P[target][0] = car; C[target]++; incar++;
	return;
    }
    REP(i, cap) assert(C[i] > 0);

    // rule 1
    int mind = INT_MAX;
    for ( int i = 0; i < cap; i++ ){
	if ( C[i] == 2 ) continue;
	if ( P[i][0].back < car.back ) continue;
	int d = P[i][0].back -  car.back;
	if ( d < mind ){
	    target = i;
	    mind = d;
	}
    }
    if ( target != -1 ){
	P[target][1] = P[target][0];
	P[target][0] = car; C[target]++; incar++;
	return;
    }

    // rule 2
    mind = INT_MAX;
    for ( int i = 0; i < cap; i++ ){
	if ( C[i] == 2 ) continue;
	if ( P[i][0].back >= car.back ) continue;
	int d = car.back - P[i][0].back;
	if ( d < mind ){
	    target = i;
	    mind = d;
	}
    }
    assert( target != -1 );
    P[target][1] = P[target][0];
    P[target][0] = car; C[target]++; incar++;
}

void trace(int c){
    return;
    cout << endl;
    cout << "time " << c << "   incar = " << incar << endl;
    for ( int i = 0; i < cap; i++ ){
	cout << "P" << i << "  ";
	for ( int j= 0; j < C[i]; j++ ){
	    Car c = P[i][j];
	    cout << "(" << c.id << "," << c.back << ")";
	}
	cout << endl;
    }
}

void simulate(){
    int current = 0;
    int id = 0;
    isfast = true;
    incar = 0;
    for ( int i = 0; i < cap; i++ ) C[i] = 0;

    queue<Car> Q;

    while(1){
	trace(current);
	if ( ncar == 0 && incar == 0 && Q.empty() ) break;
	dequeue(current);
	if ( current % 10 == 0 && ncar ){
	    int stay; cin >> stay;
	    Q.push(Car(++id, stay));
	    ncar--;
	}

	while( !isFull() && !Q.empty() ){
	    Car c = Q.front(); Q.pop();
	    c.back = c.stay + current;
	    enqueue(c);
	}
	current++;
    }
    cout << endl;
}

int main(){
    while(1){
	cin >> cap >> ncar;
	if ( cap == 0 && ncar == 0 ) break;
	simulate();
    }
    return 0;
}
