// @JUDGE_ID:  17051CA  488  C++
// @begin_of_source_code
#include<iostream>

void printWave( int h ){

    for ( int i = 1; i <= h; i++){
	for ( int j = 1; j <= i; j++){
	    cout << i;
	}
	cout << endl;
    }

    for ( int i = h-1; i >= 1; i--){
	for ( int j = 1; j <= i; j++ ){
	    cout << i;
	}
	cout << endl;
    }

}

void compute(){
    int amplitude, frequency;
    
    cin >> amplitude >> frequency;

    for ( int i = 0; i < frequency; i++ ){
	if ( i != 0 ) cout << endl;
	printWave ( amplitude );
    }
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
	cout << endl;
    }
}
// @end_of_source_code
