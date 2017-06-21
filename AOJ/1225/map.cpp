#include<iostream>
#include<map>
using namespace std;

main(){
  map<string, pair<int, int> > M;

  cout << M["ABC"].first << endl;


  M["AAC"].second = 10;

  M["ABC"].first = 10;



  M["XX"].first = 10;

  for ( map<string, pair<int, int> >::iterator it = M.begin(); it != M.end(); it++ ){
    string name = (*it).first;
    pair<int, int> p = (*it).second;
 
    cout << name << " " <<  p.first << " " << p.second << endl;
    
  }


}
