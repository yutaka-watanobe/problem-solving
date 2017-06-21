// @JUDGE_ID:  17051CA  577  C++
// @begin_of_source_code
/* Simulation - Window Manager */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
/* mode */
#define ORIGINAL 0
#define ZOOM 1
/* mouse */
#define NORMAL 0
#define DOWN 1
/* locate */
#define NOTHING 0
#define CLOSE_AREA 1
#define ZOOM_AREA 2
#define MOTION_AREA 3
#define DATA_AREA 4

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

class Window{
 public:
  int id;
  int x1, y1, x2, y2; /* left, top, right, bottom */
  int ox1, oy1, ox2, oy2; /* original size */
  int mode;

  Window(){}
  Window(int id, int x1, int y1, int x2, int y2): 
    id(id), x1(x1), y1(y1), x2(x2), y2(y2){
    ox1 = x1;
    oy1 = y1;
    ox2 = x2;
    oy2 = y2;
    mode = ORIGINAL;
  }

  int getLocation( int x, int y ){
    /* Close ? */
    if ( x1 <= x && x <= x1+24 && y1 <= y && y <= y1 + 24 ){
      return CLOSE_AREA;
    }

    /* Zoom ? */
    if ( x2-24 <= x && x <= x2 && y1 <= y && y <= y1 + 24 ){
      return ZOOM_AREA;
    }

    /* Motion ? */
    if ( x1+25 <= x && x <= x2-25 && y1 <= y && y <= y1 + 24){
      return MOTION_AREA;
    }

    /* Data ? */
    if ( x1 <= x && x <= x2 && y1+25 <= y && y <= y2 ){
      return DATA_AREA;
    }

    return NOTHING;
  }

  void zoom(){
    mode = ZOOM;
    x1 = y1 = 0;
    x2 = y2 = 1023;
  }

  void original(){
    mode = ORIGINAL;
    x1 = ox1;
    y1 = oy1;
    x2 = ox2;
    y2 = oy2;
  }

  void move( int x, int y ){
    if ( mode == ORIGINAL ){
      x1 += x;
      x2 += x;
      y1 += y;
      y2 += y;
      ox1 = x1;
      oy1 = y1;
      ox2 = x2;
      oy2 = y2;
    }
  }

  void printLocation(){
    cout << x1 << ", " << y1 << ", " << x2 << ", " << y2 << endl;
  }
};

class Mouse{
 public:
  int state;

  Mouse(){
    state = NORMAL;
  }

 
};

class WINP{
 public:
  vector<Window> W;
  Window empty_window;
  Mouse mouse;
  int id_cnt;
  Window *selected_window;
  pair<int, int> point;
  int location;

  WINP(){
    mouse = Mouse();
    id_cnt = 0;
    empty_window = Window(-1, 0, 0, 0, 0);
    location = NOTHING;
  }

  void CR(int l, int t, int r, int b ){
    Window w = Window(id_cnt, l, t, r, b);
    W.insert( W.begin(), w );
    selected_window = &W[0];
    cout << "Created window " << id_cnt << " at ";
    cout << l << ", " << t << ", " << r << ", " << b << endl;
    id_cnt++;
  }

  void DN(int x, int y){
    mouse.state = DOWN;
    if (press( x, y ) ){
      cout << "Selected window " << (*selected_window).id << endl;
    }
    point = pair<int, int>(x, y);
  }

  void UP( int x, int y ){

    if ( location == CLOSE_AREA && (*selected_window).id != -1 ){
      if ( (*selected_window).getLocation(x, y) == CLOSE_AREA ){
	cout << "Closed window " << (*selected_window).id << endl;
	removeWindow( (*selected_window).id );
      }
    }

    if ( location == ZOOM_AREA && (*selected_window).id != -1 ){
      if (  (*selected_window).getLocation(x, y) == ZOOM_AREA ){
	if( (*selected_window).mode == ORIGINAL ){
	  (*selected_window).zoom();
	}else {
	  (*selected_window).original();
	}
	cout << "Resized window " << (*selected_window).id << " to ";
	(*selected_window).printLocation();
      }
    }

    if ( location == MOTION_AREA  && (*selected_window).id != -1){
      if ( (*selected_window).mode == ORIGINAL ){
	int xp = point.first;
	int yp = point.second;
	(*selected_window).move( x - xp, y - yp );
	cout << "Moved window " << (*selected_window).id << " to ";
	(*selected_window).printLocation();
      }
    }

    mouse.state = NORMAL;
  }

  void AT( int x, int y ){
    if ( mouse.state == DOWN && location == MOTION_AREA && (*selected_window).id != -1){
      int xp = point.first;
      int yp = point.second;
      (*selected_window).move( x - xp, y - yp );
      cout << "Moved window " << (*selected_window).id << " to ";
      (*selected_window).printLocation();
      point.first = x;
      point.second = y;
    }
  }

  void RE(){
    for ( int i = W.size() - 1; i >= 0; i-- ){
      Window w = W[i];
      cout << "Window " << w.id << " at ";
      w.printLocation();
    }
  }

  bool press( int x, int y ){
    Window selected;
    for ( int i = 0; i < W.size(); i++ ){
      location = W[i].getLocation( x, y );
      if ( location ) {
	selected = W[i];
	W.erase( W.begin() + i );
	goto next;
      }
    }
    
    location = NOTHING;
    selected_window = &empty_window;
    return false;
    
  next:;
    W.insert( W.begin(), selected );
    selected_window = &W[0];
    return true;
  }

  void removeWindow(int id){
    for ( int i = 0; i < W.size(); i++ ){
      if ( W[i].id == id ){
	W.erase( W.begin() + i );
	return ;
      }
    }
  }
};

string line;
WINP winp;

int read(){
  getline( cin, line );
  if ( line == "ZZ" ) return 0;
  return 1;
}

void work(){
  vector<string> com;
  split( com, line );
  string command = com[0];

  int x, y, l, t, r, b;

  if ( command == "CR" ){
    l = atoi( com[1].c_str() );
    t = atoi( com[2].c_str() );
    r = atoi( com[3].c_str() );
    b = atoi( com[4].c_str() );
    winp.CR( l, t, r, b);
  }else if ( command == "DN" ){
    x = atoi( com[1].c_str() );
    y = atoi( com[2].c_str() );
    winp.DN( x, y );
  }else if ( command == "UP" ){
    x = atoi( com[1].c_str() );
    y = atoi( com[2].c_str() );
    winp.UP( x, y );
  }else if ( command == "AT" ){
    x = atoi ( com[1].c_str() );
    y = atoi ( com[2].c_str() );
    winp.AT( x, y );
  }else if ( command == "RE" ){
    winp.RE();
  }

}

main(){
  winp = WINP();
  while( read() ){
    if ( line.size() == 0 ) continue;
    work();
  }
}
// @end_of_source_code
