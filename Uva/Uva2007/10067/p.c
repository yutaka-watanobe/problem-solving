// @JUDGE_ID:  17051CA  10067  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h> 
#include<vector>
#include<slist>
#include<queue>


bool forbidden[10000];
bool visited[10000];

int bfs(int, int);

void work(){
  int k, start, end, f;
  int a, b, c, d;
  
  cin >> a >> b >> c >> d;
  start = 1000*a + 100*b + 10*c + d;
  cin >> a >> b >> c >> d;
  end = 1000*a + 100*b + 10*c + d;

  for(int i=0; i<10000; i++) {forbidden[i] = false; visited[i] = false;}

  cin >> k;
  for(int i=0; i<k; i++){
    cin >> a >> b >> c >> d;
    f = 1000*a + 100*b + 10*c + d;
    forbidden[f] = true;
  }

  cout << bfs(start, end) << endl;
}

int bfs(int s, int t){
  queue<int> q;
  int cost[10000] = {0};

  int u, v;
  q.push(s);
  visited[s] = true;
  int a, b, c, d, ta, tb, tc, td;

  while(!q.empty()){
    u = q.front(); q.pop();

    if(u==t) return cost[u];
    
    a = u/1000;
    b = (u%1000)/100;
    c = (u%100)/10;
    d = u%10;

    /* 1000 */
    ta = a;
    ta++; if(ta==10) ta = 0;
    v = 1000*ta+100*b+10*c+d;
    if(!forbidden[v] && !visited[v]){ 
      q.push(v); visited[v] = true; cost[v] = cost[u]+1;
    }
    ta = a;
    ta--; if(ta==-1) ta = 9;
    v = 1000*ta+100*b+10*c+d;
    if(!forbidden[v] && !visited[v]) { 
      q.push(v); visited[v] = true; cost[v] = cost[u]+1;
    }
    /* 100 */
    tb = b;
    tb++; if(tb==10) tb = 0;
    v = 1000*a+100*tb+10*c+d;
    if(!forbidden[v] && !visited[v]) { 
      q.push(v); visited[v] = true; cost[v] = cost[u]+1;
    }
    tb = b;
    tb--; if(tb==-1) tb = 9;
    v = 1000*a+100*tb+10*c+d;
    if(!forbidden[v] && !visited[v]) { 
      q.push(v); visited[v] = true;  cost[v] = cost[u]+1;
    }
    /* 10 */
    tc = c;
    tc++; if(tc==10) tc = 0;
    v = 1000*a+100*b+10*tc+d;
    if(!forbidden[v] && !visited[v]) { 
      q.push(v); visited[v] = true; cost[v] = cost[u]+1;
    }
    tc = c;
    tc--; if(tc==-1) tc = 9;
    v = 1000*a+100*b+10*tc+d;
    if(!forbidden[v] && !visited[v]) {
      q.push(v); visited[v] = true;  cost[v] = cost[u]+1;
    }
    /* 1 */
    td = d;
    td++; if(td==10) td = 0;
    v = 1000*a+100*b+10*c+td;
    if(!forbidden[v] && !visited[v]) { 
      q.push(v); visited[v] = true;  cost[v] = cost[u]+1;
    }
    td = d;
    td--; if(td==-1) td = 9;
    v = 1000*a+100*b+10*c+td;
    if(!forbidden[v] && !visited[v]) { 
      q.push(v); visited[v] = true;  cost[v] = cost[u]+1;
    }
  }

  return -1;

}
main(){
  int n;
  cin >> n;
  for(int i=0; i<n ;i++){
    work();
  }
}

// @end_of_source_code
