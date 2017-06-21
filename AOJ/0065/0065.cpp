/**
 * multiset, set
 */
#include<iostream>
#include<sstream>
#include<string>
#include<set>

using namespace std;

multiset<int> read(){
  multiset<int> s;
  string line;
  int x;

  while(1){
    getline(cin , line );
    if ( cin.eof() || line.find(',') == string::npos) break;
    stringstream sin(line);
    sin >> x;
    s.insert(x);
  }

  return s;
}

main(){
  multiset<int> v1, v2;
  set<int> u;
  v1 = read();
  v2 = read();
  for ( multiset<int>::iterator it = v1.begin(); it != v1.end(); it++ ){
    int t = (*it);
    if ( v2.count(t) && u.find(t) == u.end() ) {
      cout << t << " " << v1.count(t) + v2.count(t) << endl;
      u.insert(t);
    }
  }
}
