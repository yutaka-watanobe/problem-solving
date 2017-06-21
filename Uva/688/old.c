// @JUDGE_ID:  17051CA  688 C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX 60400

int read();
void work();
void init();

class Seg{
 public:
  float a1, a2;
};

class Line{
 public:
  vector<Seg> v;
  Seg newSeg;
  Line(){
    v.clear();
  }

  void addSegment(Seg seg){
    
    for(int i=0; i<v.size(); i++){
      /*重なりがる場合*/
      if( (v[i].a2 >= seg.a2 && seg.a2 >= v[i].a1) && seg.a1<v[i].a1){
	newSeg.a1 = seg.a1;
	newSeg.a2 = v[i].a2;
	v.erase(v.begin()+i);
	addSegment(newSeg);
	return;
      }else if( (v[i].a1 <= seg.a1 &&seg.a1<=v[i].a2) && seg.a2>v[i].a2){
	newSeg.a1 = v[i].a1;
	newSeg.a2 = seg.a2;
	v.erase(v.begin()+i);
	addSegment(newSeg);
	return;
      }else if( seg.a1>=v[i].a1 && seg.a2<=v[i].a2 ){
	newSeg.a1 = v[i].a1;
	newSeg.a2 = v[i].a2;
	v.erase(v.begin()+i);
	addSegment(newSeg);
	return;
      }else if( seg.a1<=v[i].a1 && seg.a2>=v[i].a2 ){
	newSeg.a1 = seg.a1;
	newSeg.a2 = seg.a2;
	v.erase(v.begin()+i);
	addSegment(newSeg);
	return;
      }

    }
    v.push_back(seg);

  }


  float getValue(){
    if( v.size() == 0 ) return 0;
    float sum = 0;
    for(int i=0; i<v.size(); i++){
      sum += v[i].a2 -v[i].a1;
    }
    return sum;
  }
};

Line line[MAX];
unsigned int n;

void init(){
  for(int i=0; i<MAX; i++){
    line[i].v.clear();
  }
}

int read(){
  cin >> n;
  if( n == 0 ) return 0;
  float x, y, r;
  int start, end;
  for(int a=0; a<n; a++){
    cin >> x >> y >> r;
    x = x+201;
    x = x*100;
    start = (int)(x - r*100);
    end = (int)(x + r*100);
    /*if( start < 0 ) start = 0;*/
    /*if( end >= MAX ) end = MAX;*/
    
    
    for(int i=start; i<end; i++){
      Seg seg;
      seg.a1 = (y-r)/100; seg.a2 = (y+r)/100; /* check!! */
      /*if( y-r <0 ) seg.a1 = 0;*/
      /*if( y+r >200 ) seg.a2 = 200;*/
      line[i].addSegment(seg);
    }
    
  }

  return 1;
}

void work(){

  float sum = 0;
  
  for(int i=0; i<MAX; i++){
    sum += line[i].getValue();
  }



  

  printf("%.2f\n", sum);
}

main(){
  for(int i=1; read(); i++){
    cout << i << " ";
    work();
    init();
  }
}
// @end_of_source_code
