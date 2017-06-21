#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
using namespace std;

class Team{
    public:
    string name;
    int score, id;
    Team(){}
    Team( int id, int score, string name): id(id), score(score), name(name){}

    bool operator < ( const Team &t ) const{
		if ( score == t.score ) return id < t.id;
	return score > t.score;
    }
};

Team T[10];
int n;

void sort(){
    sort( T, T + n );
}

int main(){
    string name;
    int w, l, d;
    int tcase = 0;
    while (1){
	cin >> n;
	if ( n == 0 ) break;
	for ( int i = 0; i < n; i++ ){
	    cin >> name >> w >> l >> d;
	    assert( w + l + d == n-1 );
	    T[i] = Team(i, w*3+d, name);
	}
	sort();

	if ( tcase ) cout << endl;
	for ( int i = 0; i < n; i++ ){
	    cout << T[i].name << "," << T[i].score << endl;
	}
	tcase++;
    }


    return 0;
}
