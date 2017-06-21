#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

main(){
  /*
  set<int> s1, s2, s;
  s1.insert(3);
  s1.insert(5);
  s1.insert(7);

  s2.insert(1);
  s2.insert(5);
  s2.insert(8);
  s2.insert(9);
  set<int>::iterator it, p, e;
  */

  vector<int> s1, s2, s;
  vector<int>::iterator it, p, e;
  s1.push_back(3);
  s1.push_back(5);
  s1.push_back(7);

  s2.push_back(1);
  s2.push_back(5);
  s2.push_back(8);
  s2.push_back(9);

  set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),  inserter(s, s.begin()));

  //  for ( int i = 0; i < 10; i++ ) cout << N[i] << endl;
  //  set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));

  for ( it = s.begin(); it != s.end(); it++ ) cout << (*it) << " ";
  cout << endl;

}
