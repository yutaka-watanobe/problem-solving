// Simulation
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cassert>

#define MAX 1001

void split ( vector<string> &d, const string &s, char c ) {
  string t = "";
  d.clear();
  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back(t);
}

class Team{
    public:
    string name;
    int wingame, winset, lostset, point, less;

    Team(){}
    Team( string name ): name(name){
	wingame = winset = lostset = point = 0;
    }

    void validate(){
	less = winset - lostset;
    }

    void add( int ws, int ls, int p ){
	winset += ws;
	lostset += ls;
	point += p;
    }

    bool operator <  ( const Team &t ) const{
	if ( wingame == t.wingame ){
	    if ( less == t.less ){
		if ( point == t.point ){
		    return name < t.name;
		} else {
		    return point > t.point;
		}
	    } else {
		return less > t.less;
	    }
	} else {
	    return wingame > t.wingame;
	}
    }

    void print(){
	while ( name.size() < 20 ) name += ' ';
	cout << name;
	printf("%5d%5d%10d\n", wingame, less, point);

    }
};

int T;
Team buffer[MAX];
map<string, int> N_I; // name to index

void simulate(){
    string line, team1, team2;
    int M; cin >> M;
    getline( cin, line );

    int points1, points2, winset1, winset2, lostset1, lostset2;
    int p1, p2;
    for ( int i = 0; i < M; i++ ){
	team1 = team2 = "";
	points1 = points2 = winset1 = winset2 = lostset1 = lostset2 = 0;
	getline ( cin , line );
	int current = 0;
	while ( line[current] != '-' ) team1 += line[current++];
	current++;
	while ( line[current] != ':' ) team2 += line[current++];
	current++;

	vector<string> scores;
	split(scores, line.substr( current, line.size()-current), ' ');
	for ( int s = 0; s < scores.size(); s++ ){
	    string play = scores[s];
	    vector<string> points;
	    split( points, play, '-' );
	    p1 = atoi(points[0].c_str());
	    p2 = atoi(points[1].c_str());
	    
	    //	    cout << p1 << "-" << p2 << endl;
	    points1 += p1;
	    points2 += p2;
	    if ( p1 > p2 ){
		winset1++; lostset2++;
	    } else if ( p1 < p2 ){
		winset2++; lostset1++;
	    } else {
		assert( false );
	    }
	}

	if ( winset1 > winset2 ){
	    buffer[ N_I[team1] ].wingame++;
	} else if ( winset1 < winset2 ) {
	    buffer[ N_I[team2] ].wingame++;
	} else {
	    assert( false );
	}


	buffer[ N_I[team1] ].add( winset1, lostset1, points1);
	buffer[ N_I[team2] ].add( winset2, lostset2, points2);
    }

    for ( int i = 0; i < T; i++ ) buffer[i].validate();
    sort( buffer, buffer + T );

    for ( int i = 0; i < T; i++ ){
	buffer[i].print();
    }

}

bool read(){
    cin >> T;
    if ( T == 0 ) return false;
    string line;
    getline( cin, line );
    for ( int i = 0; i < T; i++ ){
	getline( cin, line );
	N_I[ line ] = i;
	buffer[i] = Team( line );
    }
    
    return true;
}

main(){
    while ( read() ) simulate();
}
