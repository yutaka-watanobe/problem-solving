// @JUDGE_ID:  17051CA  660  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<stl.h>
#include<string>
#define WAITING 0
#define WORKING 1

class Request{
 public:
  int request_time;
  int start_time;
  int end_time;
  int total_time;
  int origin, destination, weight;
  int state;
  Request(){}
  Request( int t, int o, int d, int w ): request_time(t), origin(o), destination(d), weight(w){
    state = WAITING;
    start_time = -1;
  }
};

class Robot{
 public:
  int location;
  int weight_limit;
  int total_time;

  bool working;
  int request_id;
  int task;

  Robot(){}
  Robot(int weight_limit): weight_limit(weight_limit){
    working = false;
    location = 1;
    total_time = 0;
  }
  
  void work( int &request_count ){
    task--;
    if ( task == 0 ){
      working = false;
      request_count++;
    }
  }

  void setTask(int id, int destination, int cost){
    total_time += cost;
    request_id = id;
    location = destination;
    task = cost;
    working = true;
  }

};

class AlphaCentauri{
 public:
  int n, m;
  vector<Robot> R;
  vector<Request> Q;
  int current_time;
  int request_size;
  int request_count;

  int getDistance( int source, int target ){
    if ( target == source ) return 0;
    else if ( target > source ){
      return target - source;
    }else if ( target < source ){
      return n - ( source - target );
    }
  }

  void request(){
    for ( int i = 0; i < Q.size(); i++ ){
      if ( Q[i].request_time > current_time ) return;
      if ( Q[i].state == WAITING ){
	if ( Q[i].start_time == -1 ) Q[i].start_time = current_time;
	int cost = INT_MAX;
	int candidate_id = -1;
	for ( int r = 0; r < R.size(); r++ ){
	  if ( !R[r].working && Q[i].weight <= R[r].weight_limit ){
	    int d = getDistance( R[r].location, Q[i].origin );
	    if ( cost > d ){
	      cost = d;
	      candidate_id = r;
	    }
	  }
	}
	if ( candidate_id != -1 ){
	  int task =  cost + getDistance( Q[i].origin, Q[i].destination ) + 10;
	  R[candidate_id].setTask( i, Q[i].destination,  task);
	  
	  Q[i].end_time = current_time + task;
	  Q[i].total_time = Q[i].end_time - Q[i].start_time;
	  Q[i].state = WORKING;
	}
      }
    }
  }
  
  void parseTime(){
    for ( int i = 0; i < R.size(); i++ ){
      if ( R[i].working )  R[i].work( request_count);
    }
  }
  
  void start(){
    while ( 1 ){
      current_time++;
      parseTime();
      request();
      if ( request_count == request_size ) break;
    }
  }
  
  void work(){
    current_time = 0;
    request_count = 0;
    
    start();
    
    /* waiting time */
    int total_working_time = 0;
    for ( int i = 0; i < Q.size(); i++ ){
      total_working_time += Q[i].total_time;
    }
    printf("Average wait time   = ");
    printf( "%.3f minutes", total_working_time*1.0/ Q.size() );
    printf("\n");
    
    /* utilization */
    double total_utilization = 0;
    for ( int i = 0; i < R.size(); i++ ){
      total_utilization += (1.0*R[i].total_time ) / (current_time - Q[0].start_time) * 100;
    }
    printf("Average utilization = ");
    printf( "%.3f", total_utilization*1.0/R.size() );
    printf(" %%\n");
  }

  int read(){
    /* init */
    R.clear();
    Q.clear();
    
    scanf("%d %d", &n, &m);
    if ( n == 0 && m == 0 ) return 0;
    
    int t, o, d, w;
    for ( int i = 0; i < m; i++ ){
      scanf("%d", &w );
      R.push_back( Robot( w ) );
    }
    
    while ( 1 ){
      scanf("%d %d %d %d", &t, &o, &d, &w );
      if ( t == -1 && o == -1 && d == -1 && w == -1 ) break;
      Q.push_back( Request( t, o, d, w ) );
    }
    
    request_size = Q.size();
    
    return 1;
  }
};

main(){
  AlphaCentauri AC;

  for ( int i = 1; AC.read(); i++ ){
    cout << "Simulation " << i << endl;
    AC.work();
    cout << endl;
  }
}
// @end_of_source_code


