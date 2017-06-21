// there is an empty line!!!
#include<iostream>
#include<string>
#include<map>
#include<cmath>

using namespace std;

static const string qwerty = "`1234567890-=  qwertyuiop[]\\ asdfghjkl;'   zxcvbnm,./   ";
static const string QWERTY = "~!@#$%^&*()_+  QWERTYUIOP{}| ASDFGHJKL:\"   ZXCVBNM<>?   ";
static const string dvorak = "`123qjlmfp/[]  456.orsuyb;=\\ 789aehtdck-   0zx,inwvg'   ";
static const string DVORAK = "~!@#QJLMFP?{}  $%^>ORSUYB:+| &*(AEHTDCK_   )ZX<INWVG\"   ";


static const string home_Q_two = "asdfjkl;";
static const string HOME_Q_two = "ASDFJKL:";
static const string home_Q_one = "fghj";
static const string HOME_Q_one = "FGHJ";
static const string home_D = "ehtd";
static const string HOME_D = "EHTD";

double getDistance( int i1, int j1, int i2, int j2 ){
    return sqrt( (double)(i1-i2)*(i1-i2) + (j1-j2)*(j1-j2));
}

double getMin( string source, char target, map<char, pair<int, int> > &M ){
    double mind = 10000.0;

    for ( int i = 0; i < source.size(); i++ ){
	char s = source[i];
	mind = min( mind, getDistance(M[target].first, M[target].second, M[s].first, M[s].second) );
    }

    return mind*2;
}

main(){
    string line;

    /*
    for ( int i = 0; i < 56; i++ ){
	cout << dvorak[i] << " ";
	if ( (i+1)%14 == 0 ) cout<< endl;
    }

    for ( int i = 0; i < 56; i++ ){
	cout << DVORAK[i] << " ";
	if ( (i+1)%14 == 0 ) cout<< endl;
	}*/


    map<char, pair<int, int> > qM;
    map<char, pair<int, int> > dM;
    map<char, pair<int, int> > QM;
    map<char, pair<int, int> > DM;

    for ( int i = 0; i < 14*4; i++ ){
	qM[qwerty[i]].first = i/14;
	qM[qwerty[i]].second = i%14;
	QM[QWERTY[i]].first = i/14;
	QM[QWERTY[i]].second = i%14;
    }

    for ( int i = 0; i < 14*4; i++ ){
	dM[dvorak[i]].first = i/14;
	dM[dvorak[i]].second = i%14;
	DM[DVORAK[i]].first = i/14;
	DM[DVORAK[i]].second = i%14;
    }

    while( getline(cin, line) ){

	double sumQO = 0.0;
	double sumQT = 0.0;
	double sumD = 0.0;

	for ( int i = 0; i < line.size(); i++ ){
	    char ch = line[i];
	    if ( ch == ' ' ) continue;

	    if ( qM.find(ch) == qM.end() )
		sumQO += getMin(HOME_Q_one, ch, QM);
	    else
		sumQO += getMin(home_Q_one, ch, qM);

	    if ( qM.find(ch) == qM.end() )
		sumQT += getMin(HOME_Q_two, ch, QM);
	    else
		sumQT += getMin(home_Q_two, ch, qM);

	    if ( dM.find(ch) == dM.end() )
		sumD += getMin(HOME_D, ch, DM);
	    else
		sumD += getMin(home_D, ch, dM);
	}
	printf("%.2lf %.2lf %.2lf\n", sumQT, sumQO, sumD);
    }
}
