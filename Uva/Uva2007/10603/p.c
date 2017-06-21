// @JUDGE_ID:  17051CA  10603  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<set>
#include<map>
#include<stl.h>

class State{
 public:
  int value[3];

  State(){}
  State(int a, int b, int c){
    value[0] = a;
    value[1] = b;
    value[2] = c;
  }
  
  bool operator < ( const State &s ) const{
    if (s.value[0] == value[0] ){
      if ( s.value[1] == value[1] ){
	if ( s.value[2] < value[2] ) return true;
	else return false;
      } 
      else if ( s.value[1] < value[1] ) return true;
      else return false;
    }
    else if ( s.value[0] < value[0] ) return true;
    else return false;
  }
};

class Candidate{
 public:
  State state;
  int cost;
  Candidate(){}
  Candidate( State state, int cost): state(state), cost(cost){}

  bool operator < ( const Candidate &c ) const{
    return ( c.cost > cost );
  }
};

class Fill{
 public:
  int cap[3];
  int d;

  void read(){
    cin >> cap[0] >> cap[1] >> cap[2] >> d;
  }

  void pour(int source, int target, State current, State &next, int &val){
    next = current;
    if ( cap[target] - current.value[target] >= current.value[source] ){
      next.value[source] = 0;
      next.value[target] = current.value[target] + current.value[source];
      val = current.value[source];
    } else {
      next.value[target] = cap[target];
      next.value[source] = current.value[source] - (cap[target] - current.value[target]);
      val = cap[target] - current.value[target];
    }
  }

  void work(){
    multiset<Candidate> PQ;
    map<State, bool> used;

    State initial = State(0, 0, cap[2] );
    PQ.insert( Candidate(initial, 0 ) );
    used[initial] = true;
    Candidate candidate;
    State u, v;
    int cost, val;
    int totalAmount = 0;
    int answer = 0;

    while ( PQ.size() ){
      candidate = *(PQ.begin()); PQ.erase(PQ.begin());
      u = candidate.state;
      cost = candidate.cost;
      
      used[u] = true;

      if ( u.value[0] == d || u.value[1] == d || u.value[2] == d ){
	answer = d;
	totalAmount = cost;
	break;
      }
      if ( u.value[0] < d && answer < u.value[0] ){ answer = u.value[0]; totalAmount = cost;}
      if ( u.value[1] < d && answer < u.value[1] ){ answer = u.value[1]; totalAmount = cost;}
      if ( u.value[2] < d && answer < u.value[2] ){ answer = u.value[2]; totalAmount = cost;}
      
      pour(0, 1, u, v, val );
      if ( !used[v]) PQ.insert( Candidate(v, cost + val ) );
      pour(1, 0, u, v, val );
      if ( !used[v]) PQ.insert( Candidate(v, cost + val ) );
      pour(0, 2, u, v, val );
      if ( !used[v]) PQ.insert( Candidate(v, cost + val ) );
      pour(2, 0, u, v, val );
      if ( !used[v]) PQ.insert( Candidate(v, cost + val ) );
      pour(1, 2, u, v, val );
      if ( !used[v]) PQ.insert( Candidate(v, cost + val ) );
      pour(2, 1, u, v, val );
      if ( !used[v]) PQ.insert( Candidate(v, cost + val ) );

    }

    cout << totalAmount << " " << answer << endl;
  }

};

main(){
  Fill F;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    F.read();
    F.work();
  }
}

// @end_of_source_code


