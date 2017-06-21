// @JUDGE_ID:  17051CA  2345  C++
// @begin_of_source_code
/* Simulation of University Entrance Examination */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#define FAIL 0

class Student{
 public:
  int id;
  int region, score;
  queue<int> priority;
  int accepted;

  Student(){}
  Student( int id, int region, int score, queue<int> priority ): 
    id(id), region(region), score(score), priority(priority){
    accepted = 0;
  }

  bool operator < ( const Student &s ) const {
    return score < s.score;
  }

  int getNextPriority(){
    if ( priority.empty() ) return -1;
    int next = priority.front(); priority.pop();
    return next;
  }
};

class FDU{
 public:
  int id;
  int region;
  int capacity;
  set<pair<double, int> > candidate;

  FDU(){}
  FDU( int id, int region, int capacity ): id(id), region(region), capacity(capacity ){
    candidate.clear();
  }
  
  void insert( int studentID, vector<Student> &studentList, queue<int> &studentQueue){
    studentList[ studentID ].accepted = id;

    pair<double, int> score_ID;
    if ( studentList[ studentID ].region == region ){
      /* 地域ルールの適用 */
      score_ID = make_pair( (double)studentList[ studentID ].score*10.0/7.0, studentID );
    }else{
      score_ID = make_pair( (double)studentList[ studentID ].score, studentID );
    }

    candidate.insert( score_ID );

    if ( candidate.size() <= capacity ) return;

    int overID = candidate.begin()->second;
    candidate.erase( candidate.begin() );
    studentList[overID].accepted = FAIL;
    studentQueue.push( overID );
  }
};

int N, M;
vector<Student> studentList;
vector<FDU> universities;

void printResult(){
  for ( int i = 0; i < N; i++ ){
    if ( studentList[i].accepted == FAIL ) cout << "not accepted" << endl;
    else cout << studentList[i].accepted << endl;
  }
}

void work(){

  queue<int> studentQueue;
  for ( int i = 0; i < N; i++ ) studentQueue.push( i );

  while ( !studentQueue.empty() ){
    int studentID = studentQueue.front(); studentQueue.pop();
    int target = studentList[ studentID ].getNextPriority();
    if ( target == -1 ) continue;
    universities[ target ].insert( studentID, studentList, studentQueue );
  }

  printResult();
}

int read(){
  cin >> N >> M;
  int region, k, capacity, q;
  int score;
  studentList.clear();
  universities.clear();
  for ( int i = 0; i < N; i++ ){
    cin >> region >> score >> k;
    queue<int> priority;
    for ( int j = 0; j < k; j++ ){
      cin >> q;
      priority.push( q );
    }
    studentList.push_back( Student( i, region, score, priority ) );
  }
  universities.resize( M + 1 );
  for ( int i = 1; i <= M; i++ ){
    cin >> region >> capacity;
    universities[i] = FDU( i, region, capacity );
  }
}

main(){
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    read();
    work();
    cout << endl;
  }
}
// @end_of_source_code
