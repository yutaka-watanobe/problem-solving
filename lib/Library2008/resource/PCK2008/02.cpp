#include<iostream>
#include<cassert>
using namespace std;

void play(string game){
    int A, B;
    A = B = 0;
    for ( int i = 1; i < game.size(); i++ ) {
	if ( game[i] == 'A' ) A++;
	else B++;
    }
    if ( A > B ) A++;
    else if ( A < B ) B++; 
    else assert( false );

    cout << A << " " << B << endl;
}

int main(){
    string game;
    while( cin >> game && game != "0") play(game);
    return 0;
}
