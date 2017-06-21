#include<stdio.h>
#include<stl.h>

main(){
  vector<pair<int, int> > v;
  pair<int, int> p;

  p.first = 3; p.second = 2;
  v.push_back(p);
  p.first = 100; p.second = 2;
  v.push_back(p);
  p.first = 0; p.second = 3;
  v.push_back(p);

  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++){
    p = v[i];
    cout << p.first << ", " << p.second << endl;
  }
}
