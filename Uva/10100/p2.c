// @JUDGE_ID:  17051CA  10100  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream.h>
#include<stl.h>

vector<string> v1;
vector<string> v2;
vector<string> matchList;

void createV(string);
int isletter(char);
void match();
int check(string);

template<class T> int lcs(const T&x, const T&y){
  vector<vector<int> > b, c;
  int m, n;

  m = x.size(), n = y.size();
  
  b.resize(m+1, vector<int>(n+1));
  c.resize(m+1, vector<int>(n+1));

  for(int i=0; i<=m; i++) c[i][0] = 0;
  for(int j=0; j<=n; j++) c[0][j] = 0;

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(x[i-1]==y[j-1]){
	c[i][j] = c[i-1][j-1]+1;
	b[i][j] = 2;
      }
      else if(c[i-1][j]>=c[i][j-1]){
	c[i][j] = c[i-1][j];
	b[i][j] = 1;
      }
      else {
	c[i][j] = c[i][j-1];
	b[i][j] = 0;
      }
    }
  }
  
  return c[m][n];
}

int isletter(char c){
  string letter = "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int isletter = 0;
  for(int i=0; i<letter.size(); i++){
    if( letter[i] == c ) return 1;
  }
  return 0; 
}

int testCase;

main(){
  string a = "";
  char c, tmp;
  int num = 1;

  testCase = 1;

  while(1){
    if( scanf("%c", &c) == EOF ){
      if( tmp != '\n') match();
      break;
    }

    if( c == '\n'){
      if( num == 1 ){
	if( a.size() > 0 ) v1.push_back(a);
	num = 2;
	a = "";
      } else if( num == 2){
	if( a.size() > 0 ) v2.push_back(a);
	match();
	num = 1;
	a = "";
      } else{ 
	cout << "error" << endl;
      }
    }else if( isletter(c) == 0 ){
      if( num ==1 ) {
	if( a.size() > 0 ) v1.push_back(a);
      } else if (num == 2){
	if( a.size() > 0 ) v2.push_back(a);
      } else cout << "error" << endl;
      a = "";
    }else{
      a = a + c;
    }
    tmp = c;
  }
  

  return 0;
}

void match(){

  printf("%2d. ", testCase);

  if( v1.size() == 0 || v2.size() == 0 ){
    cout << "Blank!" << endl;
    v1.clear();
    v2.clear();
    matchList.clear();
    testCase++;
    return;
  }
  
  /*
  for(int i=0; i<v1.size(); i++){
    cout << v1[i] << " ";
  }
  cout << endl;

  for(int i=0; i<v2.size(); i++){
    cout << v2[i] << " ";
  }
  cout << endl;
  */
  /*
  int match = 0;
  for(int i=0; i<v1.size(); i++){
    for(int j=0; j<v2.size(); j++){
      string s1 = v1[i];
      string s2 = v2[j];
      if( s1 != "" && s1 != " " && s2 != "" && s2 != " "){
	if( s1 == s2 && !check(s1)) {
	  matchList.push_back(s1);
	  match++;
	}
      }
    }
  }
  */

  /*
  vector<string>::iterator  it;
  it = v1.begin();
  for(int i=0; i<v1.size(); i++){
    if( v1[i] == "" || v1[i] == " ") v1.erase(it);
    it++;
  }
  it = v2.begin();
  for(int i=0; i<v2.size(); i++){
    if( v2[i] == "" || v2[i] == " ") v2.erase(it);
    it++;
  }
  */

  cout << "Length of longest match: " << lcs(v1, v2) << endl;
  
  v1.clear();
  v2.clear();
  matchList.clear();
  testCase++;
}

int check(string s){
  for(int i=0; i<matchList.size(); i++){
    if( s == matchList[i] )return 1;
  }
  return 0;
}
// @end_of_source_code
