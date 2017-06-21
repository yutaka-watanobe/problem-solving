#include<iostream>
#include<set>
#include<string>
using namespace std;

main(){
  int N, M; 
  string name;
  set<string> U;
  cin >> N;
  for ( int i = 0; i < N; i++ ){
    cin >> name;
    U.insert(name);
  }
  int state = 0;
  cin >> M;
  for ( int i = 0; i < M; i++ ){
    cin >> name;
    if ( U.find(name) == U.end() ){
      cout << "Unknown " << name << endl;
    } else {
      cout << ((state%2==0)?"Opened":"Closed") << " by " << name << endl;
      state++;
    }
  }
}
