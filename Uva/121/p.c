// @JUDGE_ID:  17051CA  121  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<stl.h>

#define GRID 0
#define SKEW 1

double A, B;

int read(){
  cin >> A >> B;
  if(cin.eof()) return 0;
  return 1;
}

double R3;

int getCol(double a){
  double h = 0;
  int c = 1;
  if(a<1) return 0;

//  cout << R3 << endl;
  h = 0.5;
  while(1){
    if(h+R3+0.5> a) return c;
    h += R3;
    c++;
  }

}


void pipe(double a, double b, pair<int, int> &p){
  int grid, skew;
  grid = (int)a * (int)b;

  int col = getCol(a);
  
  //cout <<  "col = " << col << endl;

  int odd_row = (int)b;
  int even_row = (int)b-1;
  if( b-(int)b >= 0.5 ) even_row++;

//  cout << "odd= " << odd_row << "   even=" << even_row << endl;
  if(odd_row==even_row) skew = col*odd_row;
  else{
    if(col%2==0){
      skew = (col/2)*odd_row + (col/2)*even_row;
    }else{
      skew = ((col/2)+1)*odd_row + (col/2)*even_row;
    }
  }

  if(skew>grid){
    p.first = skew; p.second = SKEW;
  }else{
    p.first = grid; p.second = GRID;
  }
}


void work(){
  pair<int, int> p1, p2;
  pipe(A, B, p1);
  pipe(B, A, p2);
  
  if(p1.first > p2.first){
    cout << p1.first;
    if(p1.first==GRID) cout << " grid" << endl;
    else cout << " skew" << endl;
  }else if(p1.first == p2.first){
    cout << p1.first;
    if(p2.second==GRID || p1.second==GRID) cout << " grid" << endl;
    else cout << " skew" << endl;
  }else{
    cout << p2.first;
    if(p2.first==GRID) cout << " grid" << endl;
    else cout << " skew" << endl;
  }

}

main(){
  R3 = sqrt(3)/2;
  while(read()){
    work();
  }
}
// @end_of_source_code
