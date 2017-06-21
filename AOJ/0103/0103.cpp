#include<iostream>
#include<string>
using namespace std;

int n;

void simulate(){
    int outc, score, runner;
    score = outc = runner = 0;
    string event;
    
    while(1){
	cin >> event;
	if ( event == "OUT" ) outc++;
	else if ( event == "HIT" ){
	    runner++;
	    if ( runner == 4 ){
		score++;
		runner--;
	    }
	} else if ( event == "HOMERUN" ) {
	    score += runner+1;
	    runner = 0;
	}

	if ( outc == 3 ) break;
    }
    cout << score << endl;
    
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ) simulate();
    return 0;
}
