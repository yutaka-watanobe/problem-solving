#include<stdio.h>
#include<vector>

main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.insert(v.begin(), 10);

  for(int i=0; i<v.size(); i++){
    cout << v[i] << endl;
  }
}
