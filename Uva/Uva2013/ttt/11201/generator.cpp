#include<iostream>
using namespace std;


int limit;
char buffer[7];
int counter[26];

string str1 = "bcdfghjklmnpqrstvwxyz";
string str2 = "aeiou";

double table[26] = {12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01,	0.70, 6.25, 0.44, 0.00, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02,	0.22, 0.90, 0.52};

double total[26];
int number[26];
double avg[8][26];

double getSBC(){
    double t = 0.0;
    for ( int i = 0; i < limit; i++ ){
	t += (i+1)*table[ buffer[i] ];
    }
    return t;
}

void generate( int pos ){
    if ( pos + 1 == limit ) {
	//	for ( int i = 0; i < limit; i++ )cout << buffer[i];
	//	cout << "  " << buffer[0]-'a' << endl;
	total[buffer[0]-'a'] += getSBC();
	number[buffer[0]-'a']++;
	return;
    }

    if ( pos%2 == 0 ){
	for ( int i = 0; i < 5; i++ ){
	    buffer[pos] = str2[i];
	    counter[str2[i]]++;
	    if ( counter[str2[i]] <=  2 ) generate( pos+1 );
	    counter[str2[i]]--;
	}
    } else {
	for ( int i = 0; i < 21; i++ ){
	    buffer[pos] = str1[i];
	    counter[str1[i]]++;
	    if ( counter[str1[i]] <=  2 ) generate( pos+1 );
	    counter[str1[i]]--;
	}
    }
}

void init(){
    for ( int i = 1; i <= 7; i++ ){
	limit = i;
	for ( int a = 0; a < 26; a++ ){
	    total[a] = 0.0;
	    number[a] = 0;
	}
	for ( int c = 0; c < 26; c++ ) counter[c] = 0;

	generate(0);

	for ( int a = 0; a < 26; a++ ){
	    avg[i][a] = total[a]/number[a];
	}

    }


    for ( int a = 0; a < 26; a++ ){
	for ( int i = 1; i <= 7; i++ ){
	    printf("%.2lf ", avg[i][a]);
	}
	cout << endl;
    }
}

main(){
    init();
}
