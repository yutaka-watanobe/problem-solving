// @JUDGE_ID:  17051CA  216  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<math.h>

int n;

int read(){
  cin >> n;
  if(n==0) return 0;
  return 1;
}

double dis(int x1, int y1, int x2, int y2){
  return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

void work(){
  pair<int, int> p;
  vector<pair<int, int> > points;
  vector<int> v;
  vector<int> tmp;

  for(int i=0; i<n; i++){
    cin >> p.first >> p.second;
    points.push_back(p);
  }

  v.resize(n);
  for(int i=0; i<n; i++) v[i] = i;

  double min = 100000;

  do{
    double d = 0;
    for(int i=0; i<v.size()-1; i++){
      d += dis(points[v[i]].first, points[v[i]].second, points[v[i+1]].first, points[v[i+1]].second) + 16;
    }
    if(min>d){
      min = d;
      tmp = v;
    }
  }while(next_permutation(v.begin(), v.end()));

  int x1, x2, y1, y2;
  double sum = 0;
  for(int i=0; i<tmp.size()-1; i++){
    x1 = points[tmp[i]].first;
    y1 = points[tmp[i]].second;
    x2 = points[tmp[i+1]].first;
    y2 = points[tmp[i+1]].second;
      
    cout << "Cable requirement to connect ";
    cout << "(" << x1 << "," << y1 << ")";
    cout << " to ";
    cout << "(" << x2 << "," << y2 << ")";
    cout << " is ";
    double d = dis(x1, y1, x2, y2)+16;
    sum += d;
    printf("%.2f", d);
    cout << " feet." << endl;
  }
  cout << "Number of feet of cable required is ";
  printf("%.2f.", sum);
  cout << endl;

}

main(){
  for(int i=1; read(); i++){
    cout << "**********************************************************" << endl;
    cout << "Network #" << i << endl;
    work();
  }
}
// @end_of_source_code
