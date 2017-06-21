// @JUDGE_ID:  17051CA  540  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>

int t;

int read(){
  cin >> t;
  if(t==0) return 0;
  return 1;
}

void work(){
  queue<int> team_queue[1000];
  queue<int> q;
  
  map<int, int> team_map;
  map<int, bool> team_in_queue;

  int k, e;
  for(int i=0; i<t; i++){
    cin >> k;
    for(int j=0; j<k; j++){
      cin >> e;
      team_map[e] = i;
    }
  }
  
  string line;
  int teamN;

  while(1){
    cin >> line;

    if(line=="STOP") break;

    if(line=="ENQUEUE"){
      cin >> e;
      teamN = team_map[e];
      team_queue[teamN].push(e);
      if(!team_in_queue[teamN]){
	q.push(teamN);
	team_in_queue[teamN] = true;
      }
    }else if(line=="DEQUEUE"){
      teamN = q.front();

      cout << team_queue[teamN].front() << endl;
      team_queue[teamN].pop();

      if(team_queue[teamN].empty()){
	q.pop();
	team_in_queue[teamN] = false;
      }
    }
  }
}

main(){
  for(int i=1; read(); i++){
    cout << "Scenario #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
