#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define REP(i, b, e) for ( int i = b; i < (int)e; i++ )
#define rep(i, n) REP(i, 0, n)
static const int TMAX = 50;
static const int PMAX = 10;

class Team{
public:
  int nsolved, p;
  int T[PMAX];
  int TR[PMAX];
  int id;
  Team(){}
  Team(int id):id(id){
    rep(i, PMAX) T[i] = TR[i] = 0;
    nsolved = p = 0;
  }

  bool operator < ( const Team &t) const{
    if ( nsolved == t.nsolved ){
      if ( p == t.p ){
	return id < t.id;
      } else return p < t.p;
    } else return nsolved > t.nsolved;
  }
};
int T, P, R;

void simulate(){
  Team TM[TMAX];
  int tid, pid, tim;
  string mes;
  rep(i, T) TM[i] = Team(i+1);
  rep(i, R){
    cin >> tid >> pid >> tim >> mes;
    tid--; pid--;
    if ( mes == "CORRECT" ){
      if ( TM[tid].T[pid] == 0 ){
	TM[tid].T[pid] = tim; 
	TM[tid].p += tim + 1200*TM[tid].TR[pid];
	TM[tid].nsolved++;
      }
    } else {
      TM[tid].TR[pid]++;
    }
  }
  sort(TM, TM+T);
  rep(i, T){
    cout << TM[i].id << " " << TM[i].nsolved << " " << TM[i].p << endl;
  }

}

main(){
  while(1){
    cin >> T >> P >> R;
    if ( T == 0 ) break;
    simulate();
  }
}
