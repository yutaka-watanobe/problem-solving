// @JUDGE_ID:  17051CA  442  C++
// @begin_of_source_code
/* Parser */
/* Matrix maltiplication parens */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stl.h>

class Matrix{
 public:
  int row, col;
  Matrix(){}
  Matrix(int r, int c): row(r), col(c){}
};

int n;
map<char, Matrix> M;
string line;

int read(){
  cin >> n;
  char ch;
  int r, c;
  for(int i=0; i<n ; i++){
    cin >> ch >> r >> c;
    M[ch] = Matrix(r, c);
  }
}

void parse(){

  if(line.size()==1){
    cout << 0 << endl;
    return;
  }

  vector<Matrix> m;
  Matrix m1, m2;

  int sum = 0;
  for(int i=0; i<line.size(); i++){
    char ch = line[i];

    if(isalpha(ch)){
      m.push_back(M[ch]);
    }else if(ch==')'){
      m1 = m[m.size()-2];
      m2 = m[m.size()-1];
      if(m1.col != m2.row){
	cout << "error" << endl;
	return;
      }
      sum += m1.row * m1.col * m2.col;
      m.erase(m.begin() + m.size()-1);
      m[m.size()-1] = Matrix(m1.row, m2.col);
    }
  }
  cout << sum << endl;
}

void work(){

  while(1){
    cin >> line;
    if(cin.eof()) return;
    parse();
  }
}

main(){
  read();
  work();
}
// @end_of_source_code
