// @JUDGE_ID:  17051CA  10258  C++
// @begin_of_source_code
/* Simulation of Contest Scoreboard */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>
#define P_MAX 11
#define C_MAX 101

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

class Contestant{
 public:
  vector<bool> AC; /* accespted ? */
  vector<int> WA;  /* number wrong answer */
  int total_penalty;
  int total_solved;
  bool submitted;
  int id;
  
  Contestant(){}
  Contestant( int id ): id( id ){
    AC.clear();
    WA.clear();
    AC.resize( P_MAX, false );
    WA.resize( P_MAX, 0 );
    total_penalty = 0;
    total_solved = 0;
    submitted = false;
  }
  
  void submit( int problem, int time, string state ){
    submitted = true;
    if ( AC[ problem ] ) return;
    
    if ( state == "C" ){
      AC[ problem ] = true;
      total_penalty += time;
      total_penalty += WA[ problem ] * 20;
      total_solved++;
    } else if ( state == "I" ){
      WA[ problem ]++;
    }
  }
  
  bool operator < ( const Contestant &c ) const {
    if ( c.total_solved < total_solved ) {
      return true;
    } else if ( c.total_solved == total_solved ){
      if ( c.total_penalty > total_penalty ){
	return true;
      } else if ( c.total_penalty == total_penalty ){
	return c.id > id;
      } else {
	return false;
      }
    } else {
      return false;
    }
  }
  
};

vector<Contestant> C;

void init(){
  C.clear();
  C.resize( C_MAX );
  for ( int i = 0; i < C_MAX; i++ ){
    C[i] = Contestant( i );
  }
}

void work(){
  init();
  
  string line;
  vector<string> com;

  while ( 1 ){
    getline( cin, line );
    if ( line.size() == 0 || cin.eof() ) break;
    
    com.clear();
    split( com, line );

    int team = atoi( com[0].c_str() );
    int problem = atoi( com[1].c_str() );
    int time = atoi( com[2].c_str() );
    string state = com[3];

    C[ team ].submit( problem, time, state );

  }

  sort ( C.begin(), C.end() );

  for ( int i = 0; i < C.size(); i++ ){
    Contestant team = C[i];
    if ( team.submitted ){
      cout << team.id << " " << team.total_solved << " " << team.total_penalty << endl;
    }
  }
}

main(){
  string line;
  int t;
  getline( cin, line );
  t = atoi( line.c_str() ) ;
  getline( cin, line );

  for ( int i = 0; i < t; i++ ){
    if ( i  ) cout << endl;
    work();
  }
}
// @end_of_source_code
