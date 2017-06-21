// @JUDGE_ID:  17051CA  630  C++
// @begin_of_source_code
/* String search */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stl.h>

int n;
vector<pair<string, string> > W;

int read(){
  cin >> n;
  string line, str;

  W.clear();

  for ( int i = 0; i < n; i++ ){
    cin >> line;
    str = line;
    sort( line.begin(), line.end() );
    W.push_back( make_pair(line, str) );
  }

}

void work(){
  string line, str;

  int cnt = 0;

  while( 1 ){
    cin >> line;
    if ( line == "END" ) break;
    str = line;
    sort( line.begin(), line.end() );
    cout << "Anagrams for: " << str << endl;
    cnt = 0;
    for ( int i = 0; i < W.size(); i++ ){
      if ( W[i].first == line ){
	cnt++;
	printf("%3d) ", cnt);
	cout << W[i].second << endl;
      }
    }
    
    if ( cnt == 0 ) cout << "No anagrams for: " << str << endl;
  }

}

main(){
  int t;
  cin >> t;
  for ( int i = 0; i < t; i++ ){
    read();
    work();
    cout << endl;
  }
}
// @end_of_source_code
