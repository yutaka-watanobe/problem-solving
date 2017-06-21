#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 1000

class Program{
    public:
    int begin, end, air, video;
    Program(){}
    Program( int begin, int end, int air, int video): begin(begin), end(end), air(air), video(video){}

    bool operator < ( const Program &p ) const{
	return begin < p.begin;
    }
};

class Overlap{
    public:
    vector<Program> P;
    int end;

    Overlap(){
	end = -1;
    }

    void insert( Program pro ){
	end = max( end, pro.end );
	P.push_back(pro);
    }

    int getScore(){
	if ( P.size() == 1 ){
	    return max( P[0].air, P[0].video );
	}
	int score = 0;
	for ( int i = 0; i < P.size()-1; i++ ){
	    for ( int j = i+1; j <P.size(); j++ ){
		score = max( score, max( P[i].air + P[j].video, P[i].video + P[j].air) );
	    }
	}
	return score;
    }
};

int N;
Program P[MAX];
Overlap O[MAX];
int osize;

int compute(){
    int osize = 0;
    sort( P, P + N );

    O[osize++] = Overlap();
    O[osize-1].insert(P[0]);

    for ( int i = 1; i < N; i++ ){
	if ( P[i].begin < O[osize-1].end  ){
	    O[osize-1].insert( P[i] );
	} else {
	    O[osize++] = Overlap();
	    O[osize-1].insert( P[i] );
	}
    }

    int sum = 0;
    for ( int i = 0; i < osize; i++ ){
	sum += O[i].getScore();
    }
    return sum;
}

int main(){
    string name;
    int hh, mm, begin, end, air, video;
    char ch;
    while ( cin >> N && N ){
	for ( int i = 0; i < N; i++ ){
	    cin >> name;
	    cin >> hh >> ch >> mm; begin = hh*60 + mm;
	    cin >> hh >> ch >> mm; end = hh*60 + mm;
	    cin >> air >> video;
	    P[i] = Program(begin, end, air, video);
	}
	cout << compute() << endl;
    }
    return 0;
}
