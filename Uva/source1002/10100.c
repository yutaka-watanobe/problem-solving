// @JUDGE_ID: 17051CA  10100 C++
// @begin_of_source_code
#include <stdio.h>
#include <stl.h>
#include <string> 

vector<string> v1, v2;

int read();
void match();

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


main(){
  for(int i=1; read(); i++){
    printf("%2d. ", i);
    match();
  }
  return 0;
}

void match(){
  if(v1.size()==0 || v2.size()==0){
    cout << "Blank!" << endl;
  }
  else {
    cout << "Length of longest match: " << lcs(v1, v2) << endl;
  }
}

int read(){
  char buffer[2000];
  string s, t;
  cin.getline(buffer, 2000);
  if(cin.eof()) return 0;

  s = buffer;
  v1.clear();
  t = "";
  for(int i=0; i<s.size(); i++){
    if(ispunct(s[i]) || s[i]==' '){
      if(t != ""){ 
	v1.push_back(t); 
	t = "" ; 
      }
    }
    else t += s[i];
  }
  if(t.size()) v1.push_back(t);

  cin.getline(buffer, 2000);

  s = buffer;
  v2.clear();
  t = "";
  for(int i=0; i<s.size(); i++){
    if(ispunct(s[i]) || s[i]==' '){
      if(t != ""){ 
	v2.push_back(t); 
	t = "" ; 
      }
    }
    else t += s[i];
  }
  if(t.size()) v2.push_back(t);

  return 1;
}

// @end_of_source_code
