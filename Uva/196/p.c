// @JUDGE_ID:  17051CA  196  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>
#include<math.h>
#include<map>
#include<vector>

//bool isValue[1100][20000];
//int value[1100][20000];
vector<vector<bool> > isValue;
vector<vector<int> > value;
map<pair<int,int>, string > formula;

int getId(string str){
  char c;
  reverse(str.begin(), str.end());
  int sum = 0;
  for(int i=0; i<str.size(); i++){
    c = str[i];
    sum += (int)pow(26, i) * ( c - 64 );
  }
  return sum;
}

bool setValue(int r, int c){
  pair<int, int> p;
  p.first = r; p.second = c;
  string f = formula[p];

  int i, j;

  string s1, s2;
  char ch;
  
  int sum = 0;

  s1 = s2 = "";
  for(int s=0; s<f.size(); s++){
    ch = f[s];
    if(ch=='+'){
      i = atoi(s2.c_str()) - 1;
      j = getId(s1) - 1;
      s1 = s2 = "";
      if(!isValue[i][j]) return false;
      sum += value[i][j];
      continue;
    }

    if(s==f.size()-1){
      s2 += ch;
      i = atoi(s2.c_str()) - 1;
      j = getId(s1) - 1;
      if(!isValue[i][j]) return false;
      sum += value[i][j];
      continue;
    }

    if(isalpha(ch)){
      s1 += ch;
    }else{
      s2 += ch;
    }
  }

  value[r][c] = sum;
  isValue[r][c] = true;
  return true;
  
}

void work(){
  int row, col;
  cin >> col >> row;
  
  for(int i=0; i<value.size(); i++){
    value[i].clear();
  }
  value.clear();
  for(int i=0; i<isValue.size(); i++){
    isValue[i].clear();
  }
  isValue.clear();
  
  value.resize(row);
  isValue.resize(row);
  for(int i=0; i<row; i++){
    value[i].resize(col);
    isValue[i].resize(col);
  }

  string str;
  char c;

  formula = map<pair<int, int>, string >();
  pair<int, int> p;

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cin >> str;
      c = str[0];
      if(c=='='){/* formula */
	isValue[i][j] = false;
	value[i][j] = 0;
	p.first = i; p.second = j;
	str.erase(str.begin()+0);
	formula[p] = str;
      }else{/* value */
	isValue[i][j] = true;
	value[i][j] = atoi(str.c_str());
      }
    }
  }
    
  bool changed = true;;
  while(1){
    if(!changed) break;
    changed = false;
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
	if(!isValue[i][j]){
	  changed = true;
	  setValue(i, j);
	}
      }
    }
  }

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(j!=0) cout << " ";
      cout << value[i][j];
    }
    cout << endl;
  }
}

main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
