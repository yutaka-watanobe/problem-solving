// @JUDGE_ID:  17051CA  468  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
#include<map>

void work(){
  string line1, line2;
  string word;

  cin >> line1 >> line2;

  word = line2;
  
  set<char> letter1, letter2;
  vector<char> temp;
  vector<pair<int, char> > v1, v2;
  map<char, int> m1, m2;

  for(int i=0; i<line1.size(); i++){
    char c = line1[i];
    letter1.insert(c);
    m1[c]++;
  }
  
  for(int i=0; i<line2.size(); i++){
    char c = line2[i];
    letter2.insert(c);
    m2[c]++;
  }
  
  temp.clear();
  temp.resize(letter1.size());
  copy(letter1.begin(), letter1.end(), temp.begin());
  for(int i=0; i<temp.size(); i++){
    char c = temp[i];
    pair<int, char> p;
    p.first = m1[c]; p.second = c;
    v1.push_back(p);
  }

  temp.clear();
  temp.resize(letter2.size());
  copy(letter2.begin(), letter2.end(), temp.begin());
  for(int i=0; i<temp.size(); i++){
    char c = temp[i];
    pair<int, char> p;
    p.first = m2[c]; p.second = c;
    v2.push_back(p);
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  int n = min(v1.size(), v2.size());

  map<char, char> mp;

  for(int i=0; i<n; i++){
    char c1, c2;
    c1 = v1[i].second;
    c2 = v2[i].second;
    mp[c2] = c1;
  }

  for(int i=0; i<word.size(); i++){
    char c = word[i];
    cout << mp[c];
  }
  cout << endl;
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    work();
    cout << endl; 
  }
}
// @end_of_source_code
