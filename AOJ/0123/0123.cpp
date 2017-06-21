#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static string GRADE[8] = {"AAA", "AA", "A", "B", "C", "D", "E", "NA"};
static int T5[7] = {3550, 3750, 4000, 4300, 5000, 5500, 7000};
static int T10[7] = {7100, 7700, 8300, 8900, 10500, 11600, 14800};

int parse( double t, int type ){
    int M = (int)(t*100);
    if ( type == 5 ){
	for ( int i = 0; i < 7; i++ )
	    if ( M < T5[i] ) return i;
    } else {
	for ( int i = 0; i < 7; i++ )
	    if ( M < T10[i] ) return i;
    }
    return 7;
}
int main(){
    double t1, t2;
    while( cin >> t1 >> t2 ){
	cout << GRADE[max(parse(t1, 5), parse(t2,10))] << endl;
    }
    return 0;
}
