#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 40
#define EMPTY (0)

class Player{
    public:
    int id, score;
    Player(){}
    Player(int id, int score): id(id), score(score){}

    bool operator < ( const Player &p ) const{
	if ( score == p.score ) return id < p.id;
	else return score > p.score;
    }
};

int nplayer;
Player P[MAX];

int getScore(){
    int C[10][3], F[10]; /* contents, frame */

    for ( int i = 0; i < 10; i++ ){
	for ( int j = 0; j < 3; j++ ) C[i][j] = EMPTY;
    }

    for ( int i = 0; i < 10; i++ ){
	cin >> C[i][0]; 
	if ( C[i][0] == 10 && i < 9 ) continue;
	cin >> C[i][1]; 
	if ( i == 9 && C[i][0] + C[i][1] >= 10 ) {
	    cin >> C[i][2]; 
	}
    }
    
    /* compute frame score */
    for ( int i = 0; i < 10; i++ ) F[i] = C[i][0] +  C[i][1] + C[i][2];

    /* add bonus */
    for ( int i = 0; i < 8; i++ ){
	if ( C[i][0] == 10 ) {
	    if ( C[i+1][0] == 10 ) F[i] += C[i+1][0] + C[i+2][0];
	    else F[i] += C[i+1][0] + C[i+1][1];
	} else 	if (C[i][0] + C[i][1] == 10  ){
	    F[i] += C[i+1][0];
	}
    }
    if ( C[8][0] == 10 ) F[8] += C[9][0] + C[9][1];
    else if ( C[8][0] + C[8][1] == 10 ) F[8] += C[9][0];

    int total = 0;
    for ( int i = 0; i < 10; i++ ) total += F[i];
    return total;
}

main(){
    int id;
    while( cin >> nplayer, nplayer ){
	for ( int i = 0; i < nplayer; i++ ){
	    cin >> id;
	    P[i] = Player(id, getScore() );
	}
	sort( P, P + nplayer );
	for ( int i = 0; i < nplayer; i++ ){
	    cout << P[i].id << " " << P[i].score << endl;
	}
    }
}
