// @JUDGE_ID:  17051CA  144  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>

class Student{
 public:
  int id;
  int payment;

  Student(int i){
    id = i;
    payment = 0;
  }

};

int N, K;

int read(){
  cin >> N >> K;
  if( N==0 && K == 0 ) return 0;
  return 1;
}

void work(){
  queue<Student> q;

  for ( int i = 0; i < N; i++ ){
    Student s = Student(i+1);
    q.push(s);
  }

  vector<int> leave;

  int store = 0;
  int cnt = 1;

  while ( !q.empty() ){
    Student s = q.front(); q.pop();

    if(store==0){
      store = cnt;
      cnt++;
      if(cnt>K) cnt = 1;
    }

    if ( s.payment + store >= 40 ){
      leave.push_back( s.id );
      store = s.payment + store - 40;
    }else{
      s.payment += store;
      q.push( s );
      store = 0;
    }

  }

  for ( int i = 0; i < leave.size(); i++ ){
    printf("%3d", leave[i]);
  }
  cout << endl;

}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
