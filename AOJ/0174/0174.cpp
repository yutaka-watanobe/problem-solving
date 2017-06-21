 #include<iostream>
using namespace std;

main(){
    string game;
    while( cin >> game && game != "0") {
	int A = 0, B = 0;
	for ( int i = 1; i < game.size(); i++ ) {
	    if ( game[i] == 'A' ) A++;
	    else B++;
	}
	(A > B) ? A++ : B++;
	cout << A << " " << B << endl;
    }
}
