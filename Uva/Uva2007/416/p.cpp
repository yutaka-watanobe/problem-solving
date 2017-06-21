#include<string>
#include<iostream>
#define MAX 20

using namespace std;

int n;
string illumination[MAX];
string buffer[MAX];
string life[MAX];

bool canbe( string str, int number, string l ){
    string target = illumination[number];

    for ( int i = 0; i < 7; i++ ){
	if ( str[i] == 'Y' && target[i] == 'N' ) return false;
	if ( target[i] == 'Y' && str[i] == 'N' && l[i] =='Y' ) return false;
    }

    return true;
}


bool rec( int pos, int number ){
    if ( pos == n) return true;

    if ( number  < 0 ) return false;

    if ( canbe( buffer[pos], number, life[pos-1] )){
	if ( rec( pos+1, number-1 ) ) return true;
    }

    return false;
}

void work(){
    for ( int i = 9; i >=0; i-- ){
	if ( canbe(buffer[0], i , life[0]) ){
	    if ( rec( 1, i-1 ) ){
		cout << "MATCH" << endl;
		return;
	    }
	}
    }
    cout << "MISMATCH" << endl;
}

bool read(){
    cin >> n;
    if ( n == 0 ) return false;

    for ( int i = 0; i < 7; i++ ) life[i] = false;
    for ( int i = 0; i < n; i++ ){
	cin >> buffer[i];
	if ( i == 0 ){
	    life[i] = buffer[i];
	} else {
	    life[i] = buffer[i-1];
	    for ( int s = 0; s < 7; s++ ){
		if ( buffer[i][s] == 'Y' ) {
		    life[i][s] = 'Y';
		}
	    }
	}
    }
    return true;
}

main(){
    illumination[0] = "YYYYYYN";
    illumination[1] = "NYYNNNN";
    illumination[2] = "YYNYYNY";
    illumination[3] = "YYYYNNY";
    illumination[4] = "NYYNNYY";
    illumination[5] = "YNYYNYY";
    illumination[6] = "YNYYYYY";
    illumination[7] = "YYYNNNN";
    illumination[8] = "YYYYYYY";
    illumination[9] = "YYYYNYY";
    while ( read() ) work();
}

