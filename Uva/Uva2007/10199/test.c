#include<stdio.h>
#include<stl.h>
#include<vector>
#include<string>

main(){
  vector<string> v, v2;
  string line;
  while(1){
    cin >> line;
    if(cin.eof()) break;
    v.push_back(line);
  }

  sort(v.begin(), v.end());
  
  while(1){
    if(v.size()==0 ) break;
    int min = 100000;
    for(int i=0; i<v.size(); i++){
      if(min>v[i].size()) min = v[i].size();
    }
    for(int i=0; i<v.size(); i++){
      if(v[i].size()==min){
	v2.push_back(v[i]); 
	v.erase(v.begin()+i);
      }
    }
  }


  for(int i=0; i<v2.size(); i++){
    cout << v2[i] << endl;
  }
}
