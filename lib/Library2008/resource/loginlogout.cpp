#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define PMAX 1000 // number of PC
#define SMAX 10000 // number of Student
#define TMAX 1260

int npc, nstudent;
bool record[SMAX+1][TMAX+1];

void init(){
    for ( int i = 0; i <= nstudent; i++ ){
	for ( int t = 0; t <= TMAX; t++ ){
	    record[i][t] = false;
	}
    }
}

void compute(){
    int q; cin >> q;
    int total, s, e, m;
    for ( int i = 0; i < q; i++ ){
	cin >> s >> e >> m;
	total = 0;
	for ( int t = s; t < e; t++ ){
	    if ( record[m][t] ) total++;
	}
	cout << total << endl;
    }
}

void fill( int student, int start, int end ){
    for ( int t = start; t < end; t++ )	record[student][t] = true;
}

bool input(){
    cin >> npc >> nstudent;
    if ( npc == 0 && nstudent == 0 ) return false;
    init();
    map<pair<int, int>, int> login;
    int r, t, pc, student, state; 
    cin >> r;
    for ( int i = 0; i < r; i++ ){
	cin >> t >> pc >> student >> state;
	if ( state == 1 ){
	    login[make_pair(pc, student)] = t;
	} else {
	    fill( student, login[make_pair(pc, student)], t );
	}
    }
    return true;
}

main(){
    while( input()) compute();
}
