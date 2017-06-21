// @JUDGE_ID:  17051CA  119  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<vector>

class GreedyGiftGivers{
 public:
  map<string, int> value;
  vector<string> member;
  int n;

  void work(){
    int fopen;
    int m;
    int give, div;
    string name;
    string target;

    for ( int i = 0; i < n; i++ ){
      cin >> name >> give >> m;
      if ( m == 0 ) continue;
      value[name] -= give;
      value[name] += give%m;
      div = give/m;
      for ( int j = 0; j < m; j++ ){
	cin >> target;
	value[target] += div;
      }
    }

    for ( int i = 0; i < member.size(); i++ ){
      cout << member[i] << " " << value[ member[i] ] << endl;
    }
  }

  bool read(){
    cin >> n;
    if ( cin.eof() ) return false;
    string name;
    member.clear();
    value = map<string,int>();
    for ( int i = 0; i < n; i++ ){
      cin >> name;
      value[name] = 0;
      member.push_back( name );
    }
    return true;
  }
};

main(){
  GreedyGiftGivers GGG;
  for ( int i = 0; GGG.read(); i++ ){
    if ( i ) printf("\n");
    GGG.work();
  }
}

// @end_of_source_code


