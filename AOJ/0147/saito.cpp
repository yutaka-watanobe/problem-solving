#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

enum EventType{
  LEAVE, ARRIVE
};

class Event{
public:
  int time;
  EventType type;
  int gid;

  Event(int time, EventType type, int gid) : time(time), type(type), gid(gid){
  }

  bool operator<(const Event &e) const{
    if(time == e.time)
      return type > e.type;
    return time > e.time;
  }
};

const int SEAT_NUM = 17;

int n;
int used[SEAT_NUM];
priority_queue<Event> eq;
queue<int> gq;
bool countStart;

void seat(int id, int num){
  int cnt = 0;
  for(int i = 0; i < SEAT_NUM; ++i){
    if(used[i] == -1)
      ++cnt;
    else
      cnt = 0;
    if(cnt == num){
      for(int j = 0; j < num; ++j)
        used[i-j] = id;
      break;
    }
  }
}

void unseat(int id){
  for(int i = 0; i < SEAT_NUM; ++i)
    if(used[i] == id)
      used[i] = -1;
}

bool canSeat(int num){
  int cnt = 0;
  for(int i = 0; i < SEAT_NUM; ++i){
    if(used[i] == -1)
      ++cnt;
    else
      cnt = 0;
    if(cnt == num)
      return true;
  }
  return false;
}

void arrive(int time, int id){
  int number = (id % 5 == 1 ? 5 : 2);
  if(gq.empty() && canSeat(number)){
    seat(id, number);
    int finishTime = time + 17*(id%2) + 3*(id%3) + 19;
#ifdef DEBUG
    cout << "  they finished eating at " << finishTime << endl;
#endif
    eq.push(Event(finishTime, LEAVE, id));
  }
  else{
#ifdef DEBUG
    cout << "  couldn't seat" << endl;
#endif
    if(id == n-1) countStart = true;
    gq.push(id);
  }
}

void leave(int time, int id){
  unseat(id);
  
  while(!gq.empty()){
    int gid = gq.front();
    int number = (gid % 5 == 1 ? 5 : 2);
    if(canSeat(number)){
      if(gid == n-1) countStart = false;
      seat(gid, number);
      gq.pop();
      eq.push(Event(time + 17*(gid&1) + 3*(gid%3) + 19 + 1, LEAVE, gid));
    }
    else
      break;
  }
}

int compute(void){
  int ans = 0, curr = 0;
  countStart = false;
  while(!eq.empty()){
    Event e = eq.top();
    eq.pop();

    if(countStart)
      ans += e.time - curr;
    curr = e.time;

#ifdef DEBUG
    cout << "Event : " << e.time << ' '
         << (e.type == ARRIVE ? "arrive " : "leave ")
         << e.gid << endl;
#endif
    
    if(e.type == ARRIVE)
      arrive(e.time, e.gid);
    else if(e.type == LEAVE)
      leave(e.time, e.gid);
    else
      assert(false);

#ifdef DEBUG
    cout <<"    ";
    for(int i = 0; i < SEAT_NUM; ++i)
      if(used[i] == -1)
        cout << "_ ";
      else
        cout << used[i] << ' ' ;
    cout << endl;
#endif
  }
  return ans;
}

void init(void){
  fill(used, used+SEAT_NUM, -1);
}

int main(void){
  while( cin >> n ){
    ++n;
    
    init();
    for(int i = 0; i < n; ++i)
      eq.push(Event(i*5, ARRIVE, i));
    
    cout << compute() << endl;
  }
  return 0;
}


