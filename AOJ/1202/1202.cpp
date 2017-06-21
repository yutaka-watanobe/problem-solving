// @JUDGE_ID:  17051CA  688 C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Segment{
 public:
  double y1, y2, x;
  int id;
  bool isEnd;

  Segment(){}
  Segment(int i, double xx, double y1, double y2, bool end){
    id = i;
    x = xx;
    y1 = y1;
    y2 = y2;
    isEnd = end;
  }
};

class Line{
 public:
  vector<Segment> v;
  vector<Segment> list;
  double x;

  Line(){
    v.clear();
    list.clear();
  }

  void addSegment(Segment seg){
    list.push_back(seg);
  }
  
  void setSegment(){
    v.clear();
    for(int i=0; i<list.size(); i++){
      createSegment( list[i] );
    }
  }

  void createSegment(Segment seg){
    Segment newSeg;
    for(int i=0; i<v.size(); i++){
      /*重なりがる場合*/
      if( (v[i].y2 >= seg.y2 && seg.y2 >= v[i].y1) && seg.y1<v[i].y1){
	newSeg.y1 = seg.y1;
	newSeg.y2 = v[i].y2;
	v.erase(v.begin()+i);
	createSegment(newSeg);
	return;
      }else if( (v[i].y1 <= seg.y1 &&seg.y1<=v[i].y2) && seg.y2>v[i].y2){
	newSeg.y1 = v[i].y1;
	newSeg.y2 = seg.y2;
	v.erase(v.begin()+i);
	createSegment(newSeg);
	return;
      }else if( seg.y1>=v[i].y1 && seg.y2<=v[i].y2 ){
	newSeg.y1 = v[i].y1;
	newSeg.y2 = v[i].y2;
	v.erase(v.begin()+i);
	createSegment(newSeg);
	return;
      }else if( seg.y1<=v[i].y1 && seg.y2>=v[i].y2 ){
	newSeg.y1 = seg.y1;
	newSeg.y2 = seg.y2;
	v.erase(v.begin()+i);
	createSegment(newSeg);
	return;
      }
    }
    v.push_back(seg);
  }

  void removeSegment(int id){
    for(int i=0; i<list.size(); i++){
      if( list[i].id == id ){
	list.erase(list.begin() + i);
	return;
      }
    }
  }
};

vector<Segment> v;
int n;

int read();
void work();
void insert(Segment);
void createLine();

int read(){
  cin >> n;
  if( n == 0 ) return 0;
  return 1;
}

void insert(Segment seg){
  if( v.size() == 0 ){
    v.push_back(seg);
    return;
  }else if( v.size() == 1 ){
    if( seg.x <= v[0].x ){
      v.insert(v.begin(), seg);
    }else{
      v.push_back(seg);
    }
    return;
  }else if( v.size() == 2){
    if( seg.x <= v[0].x ){
      v.insert(v.begin(), seg);
    }else if( v[0].x < seg.x && seg.x <= v[1].x ){
      v.insert(v.begin()+1, seg);
    }else if(v[1].x < seg.x ){
      v.push_back(seg);
    }
    return ;
  }else{
    for(int i=0; i<v.size(); i++){
      if( i==0 ){
	if( seg.x <= v[i].x ){
	  v.insert(v.begin(), seg);
	  return;
	}
      }else if( i== v.size()-1){
	if( v[i].x < seg.x){
	  v.push_back(seg);
	  return;
	}else{
	  v.insert( v.end()-1, seg);
	  return ;
	}
      }else{
	if( v[i-1].x < seg.x && seg.x <= v[i].x ){
	  v.insert(v.begin()+i, seg);
	  return;
	}
      }
    }
  }
}

void createLine(){
  double x, y, r;
  v.clear();
  for(int a=0; a<n; a++){
    cin >> x >> y >> r;
    Segment start , end;
    start.id = a;
    end.id = a;
    start.x = x-r;
    end.x = x+r;
    start.y1 = y-r;
    end.y1 = y-r;
    start.y2 = y+r;
    end.y2 = y+r;
    start.isEnd = false;
    end.isEnd = true;
    insert(start);
    insert(end);
  }
}

void work(){
  double sum = 0;
  double w, h;
  Line line;
  line.addSegment(v[0]);
  line.x = v[0].x;

  for( int i=1; i<v.size(); i++){
    line.setSegment();
    w = v[i].x - line.x;
    h = 0;
    for(int s=0; s<line.v.size(); s++){
      h += line.v[s].y2 - line.v[s].y1;
    }
    sum += w*h;
    if( v[i].isEnd ){
      line.removeSegment( v[i].id );
      line.x = v[i].x;
    }else{
      line.addSegment( v[i] );
      line.x = v[i].x;
    }
  }
  printf("%.2f\n", sum);
}

main(){
  for(int i=1; read(); i++){
    cout << i << " ";
    createLine();
    work();
  }
  return 0;
}
// @end_of_source_code
