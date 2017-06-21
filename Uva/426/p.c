// @JUDGE_ID:  17051CA  426  C++
// @begin_of_source_code
/* Simulation */
/* PE !! */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

void split(vector<string> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(t);
}

string line;
vector<pair<int, pair<double, string> > > V;

int read(){
  int value;
  double check;
  string date;

  vector<string> sp;
  V.clear();
  while ( 1 ){
    getline( cin, line );
    if ( cin.eof() || line == "" ) break;
    sp.clear();
    split( sp, line );

    value = atoi( sp[1].c_str() );
    date = sp[0];
    sscanf( sp[2].c_str(), "%lf", &check );

    V.push_back( make_pair( value, make_pair(check, date) ) );
  }

  sort( V.begin(), V.end() );
}

void work(){
  int index;
  int space = (V.size()-1)/3+1;
  for ( int i = 0; i <= (V.size()-1)/3; i++ ){
    for ( int j = 0; j < 3; j++ ){
      index = i + space*j;
      if ( index < V.size() ){
	if ( j ) cout << "   ";
	printf("%4d", V[index].first);
	if( index > 0 && V[index-1].first != V[index].first - 1) cout << "*";
	else cout << " ";
	cout << " ";
	printf("%9.2lf", V[index].second.first);
	cout << " ";
	cout << V[index].second.second;
      }
    }
    cout << endl;
  }
}

main(){
  int t;
  getline( cin, line );
  t = atoi( line.c_str() );
  getline( cin, line );
  for ( int i = 0; i < t; i++ ){
    read();
    work();
    cout << endl;
  }
}
// @end_of_source_code
