#include<iostream>
#define AVG 12.53
using namespace std;

double table[26] = {12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01,	0.70, 6.25, 0.44, 0.00, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02,	0.22, 0.90, 0.52};

double getSBC( string str ){
    double t = 0.0;
    for ( int i = 0; i < str.size(); i++ ){
	t += (i+1)*table[ str[i] ];
    }
    return t;
}

void compute(){
    string word; cin >> word;
    if ( getSBC( word ) < AVG ) cout << "below" << endl;
    else cout << "above or equal" << endl;
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}
