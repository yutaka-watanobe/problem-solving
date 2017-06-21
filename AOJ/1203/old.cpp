// @JUDGE_ID:  17051CA  689  C++
// @begin_of_source_code
#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define MAX 100000

int read();
void work();
void cut(vector<string> &str);

char buf[MAX];
string str;
vector<string> odd, even;
set<string> result;

int read(){
  cin.getline(buf, MAX);
  if(cin.eof()) return 0;
  str = "";
  for(int i=0; buf[i]!='\0'; i++){
    if(isalpha(buf[i])){
      str += toupper(buf[i]);
    }
  }
  return 1;
}

void cut( vector<string> &str ){
  string s1, s2;
  for(int i=0; i<str.size(); i++){
    s1 = str[i];
    for(int j=0; j<str.size(); j++){
      if( i != j ){
	s2 = str[j];
	if( s2.size() >= s1.size() ){
	  if( s1 == s2.substr(0, s1.size())){
	    str.erase(str.begin() + i);
	    cut(str);
	    return;
	  }
	}
      }
    }
  }

}

void work(){
  odd.clear();
  even.clear();
  result.clear();
  if( str.size() == 0 ) {
    cout << endl;
    return;
  }

  string s1, s2, s;
  
  /* odd */
  int l,r, m ; /*left and right*/
  for(int s=0; s<str.size(); s++){
    l = s-1;
    r = s+1;
    while( l >=0 && r < str.size() && str[l] == str[r]){
      l--; r++;
    }
    m = r - s -1;
    if( m >= 1) odd.push_back( str.substr(s, m+1));
  }

  /* cut */
  cut(odd);

  for(int i=0; i<odd.size(); i++){
    s1 = odd[i];
    s2 = odd[i];
    reverse(s2.begin(), s2.end());
    s = s2.substr(0, s2.size()-1) + s1;
    result.insert( s );
  }

  /* enen */
  for(int s=1; s<str.size()-1; s++){
    if(str[s] == str[s-1]){
      l = s-2;
      r = s+1;
      while( l >=0 && r < str.size() && str[l] == str[r]){
	l--; r++;
      }
      m = r - s -1;
      if( m >= 1){
	even.push_back( str.substr(s, m+1));
      }
    }
  }
  
  /* cut */
  cut(even);
  
  for(int i=0; i<even.size(); i++){
    s1 = even[i];
    s2 = even[i];
    reverse(s2.begin(), s2.end());
    s = s2.substr(0, s2.size()) + s1;
    result.insert( s );
  }

  set<string>::iterator it;

  for(it = result.begin(); it!=result.end(); it++){
    if( it != result.begin() ) cout << " ";
    cout << *it;
  }
  cout << endl;
}

main(){
   while(read()){
    work();
  }
}
// @end_of_source_code
