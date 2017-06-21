#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define NSTATION 100
#define INFTY INT_MAX

class Train {
public:

  int from, to;
  int departure, arrive;

  Train( int f, int t, int d, int a ) : from(f), to(t), departure(d), arrive(a) {}
  Train() {}

};

class Move {
public:

  int requiredBlood;
  int to;
  int arrive;

  Move( int r, int t, int a ) : requiredBlood(r), to(t), arrive(a) {}
  Move() {}

  bool operator < ( const Move &m ) const {
    if ( requiredBlood < m.requiredBlood ) return true;
    if ( requiredBlood > m.requiredBlood ) return false;
    if ( arrive < m.arrive ) return true;
    return false;
  }

};

class TFromDuskTillDawn {
public:

  int nconnection;
  
  map<string, int> stationMap;
  vector<Train> stations[NSTATION];
  int distance[NSTATION];

  int startStation, terminateStation;

  void input() {
    stationMap.clear();
    for ( int i = 0; i < NSTATION; i++ ) stations[i].clear();

    cin >> nconnection;
    for ( int i = 0; i < nconnection; i++ ) {
      Train train = readTrain();

      // 乗れない電車は無視する (テストデータを, すべて引っ掛かるように作ること).
      if ( train.departure >= 6 && train.departure < 18 ) continue;
      if ( train.arrive - train.departure > 12 ) continue;
      if ( train.arrive%24 > 6 && train.arrive%24 <= 18 ) continue;

      if ( train.departure < 6 )
	train.departure += 24, train.arrive += 24;

      stations[train.from].push_back(train);
    }

    string station;
    cin >> station; startStation = getStationID(station);
    cin >> station; terminateStation = getStationID(station);
  }

  int getStationID( string &name ) {
    if ( stationMap.find(name) != stationMap.end() )
      return stationMap[name];

    const int newID = stationMap.size();
    stationMap[name] = newID;
    return newID;
  }

  Train readTrain() {
    string from ,to;
    int departure, time;

    cin >> from >> to >> departure >> time;

    return Train(getStationID(from), getStationID(to), departure, departure+time);
  }

  void work() {
    multiset<Move> PQ;

    fill(&distance[0], &distance[NSTATION], INFTY);

    PQ.insert(Move(0, startStation, 18));

    while ( !PQ.empty() ) {
      const Move curr = *PQ.begin(); PQ.erase(PQ.begin());

      const int now = curr.arrive;
      const int here = curr.to;

      if ( distance[here] != INFTY ) continue;
      distance[here] = curr.requiredBlood;

      if ( here == terminateStation ) break;

      for ( int i = 0; i < stations[here].size(); i++ ) {
	Train &train = stations[here][i];

	if ( distance[train.to] != INFTY ) continue;

	if ( train.departure >= now )
	  PQ.insert(Move(curr.requiredBlood, train.to, train.arrive));
	else
	  PQ.insert(Move(curr.requiredBlood + 1, train.to, train.arrive));
      }
    }

    if ( distance[terminateStation] == INFTY )
      cout << "There is no route Vladimir can take." << endl;
    else
      cout << "Vladimir needs " << distance[terminateStation] << " litre(s) of blood." << endl;
  }

};

int main() {
  TFromDuskTillDawn TFDTD;
  int nrecord;

  cin >> nrecord;

  for ( int ncase = 1; ncase <= nrecord; ncase++ ) {
    TFDTD.input();

    cout << "Test Case " << ncase << "." << endl;
    TFDTD.work();
  }

  return 0;
}
