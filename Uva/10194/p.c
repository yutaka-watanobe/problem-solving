// @JUDGE_ID:  17051CA  10194  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

void tolower(string &s){
  for(int i=0; i<s.size(); i++) 
    s[i] = tolower(s[i]);
}

class Team{
 public:
  int points, games, wins, ties, losses, difference, scored, against, goal_difference;
  string name;

  Team(string name): name(name){
    points = games = wins = ties = losses = difference = scored = against = 0;
  }

  void setDifference(){
    goal_difference = scored - against;
  }

};

class TeamSortCriterion{
 public:
  bool operator() ( const Team &t1, const Team &t2 ) const {
    if ( t1.points > t2.points ) return true;
    else if ( t1.points < t2.points ) return false;
    else if ( t1.points == t2.points ){
      if ( t1.wins > t2.wins ) return true;
      else if ( t1.wins < t2.wins ) return false;
      else if ( t1.wins == t2.wins ) {
	if ( t1.goal_difference > t2.goal_difference ) return true;
	else if ( t1.goal_difference < t2.goal_difference ) return false;
	else if ( t1.goal_difference == t2.goal_difference ) {
	  if ( t1.scored > t2.scored ) return true;
	  else if ( t1.scored < t2.scored ) return false;
	  else if ( t1.scored == t2.scored ){
	    if ( t1.games < t2.games ) return true;
	    else if ( t1.games > t2.games ) return false;
	    else if ( t1.games == t2.games ) {
	      string t1name = t1.name;
	      string t2name = t2.name;
	      tolower( t1name );
	      tolower( t2name );
	      if ( t1name < t2name ) return true;
	      else return false;
	    }
	  }
	}
      }
    }
  }
};

string line;
string tournament_name;
int number_of_game;

map<string, int> M; /* team name - > index */
vector<Team> T;

int read(){
  int n;
  getline( cin, tournament_name );
  getline ( cin, line );
  n = atoi( line.c_str() );

  T.clear();
  M = map<string, int>();

  for ( int i = 0; i < n; i++ ){
    getline( cin, line );
    M[line] = i;
    T.push_back( Team( line ) );
  }
  getline( cin, line );
  number_of_game = atoi( line.c_str() );

}

void play(){
  getline( cin , line );
  string t1_name, t2_name;
  string tmp = "";
  int t1_p, t2_p;

  int pos;
  for ( pos = 0; pos < line.size(); pos++ ){
    char ch = line[pos];
    if ( ch == '#' ){
      t1_name = tmp;
      tmp = "";
    }else if ( ch == '@' ){
      t1_p = atoi(tmp.c_str());
      tmp = "";
      break;
    }else{
      tmp += ch;
    }
  }
  
  for ( pos++; pos < line.size(); pos++ ){
    char ch = line[pos];
    if ( ch == '#' ){
      t2_p = atoi(tmp.c_str());
      tmp = "";
    }else{
      tmp += ch;
    }
  }
  t2_name = tmp;

  /* cout << t1_name << "," << t1_p << "," << t2_name << "," << t2_p << endl;  */

  if ( t1_p > t2_p ){
    T[ M[t1_name] ].points += 3;
    T[ M[t1_name] ].wins++;
    T[ M[t2_name] ].losses++;
  }else if ( t1_p < t2_p ){
    T[ M[t2_name] ].points += 3;
    T[ M[t2_name] ].wins++;
    T[ M[t1_name] ].losses++;
  }else if ( t1_p == t2_p ){
    T[ M[t1_name] ].points += 1;
    T[ M[t2_name] ].points += 1;
    T[ M[t1_name] ].ties += 1;
    T[ M[t2_name] ].ties += 1;
  }

  T[ M[t1_name] ].scored += t1_p;
  T[ M[t2_name] ].scored += t2_p;
  T[ M[t1_name] ].against += t2_p;
  T[ M[t2_name] ].against += t1_p;
  T[ M[t1_name] ].games++;
  T[ M[t2_name] ].games++;
  
}

void work(){
  for ( int i = 0; i < number_of_game; i++ ){
    play();
  }

  for ( int i = 0; i < T.size(); i++ ) T[i].setDifference();

  sort( T.begin(), T.end(), TeamSortCriterion() );
  
  cout << tournament_name << endl;


  for ( int i = 0; i < T.size(); i++ ){
    Team t = T[i];
    cout << i+1 << ") ";
    cout << t.name << " " << t.points << "p, " << t.games << "g ";
    cout << "(" << t.wins << "-" << t.ties << "-" << t.losses << "), ";
    cout << t.goal_difference << "gd (" << t.scored << "-" << t.against << ")" << endl;
    
  }
}

main(){
  int t;
  getline( cin, line );
  t = atoi( line.c_str() );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
