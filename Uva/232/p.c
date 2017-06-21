// @JUDGE_ID:  17051CA  232  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int r, c;
char grid[10][10];
int number[10][10];

int read(){
  cin >> r >> c;
  if(r==0) return 0;


  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> grid[i][j];
    }
  }
  return 1;
}

void work(){
  /* init */
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      number[i][j] = 0;
    }
  }

  int count = 1;
  int left, above;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(grid[i][j]!='*'){
	left = j-1; above = i-1;
	bool checked = false;
	if(left<0){
	  number[i][j] = count; count++; checked = true;
	}else{
	  if(grid[i][left]=='*'){
	    number[i][j] = count;
	    count++; checked = true;
	  }
	}
	if(!checked){
	  if(above<0){
	    number[i][j] = count; count++;
	  }else{
	    if(grid[above][j]=='*') {
	      number[i][j] = count;
	      count++;
	    }
	  }
	}

      }
    }
  }

  /* parse row */
  vector<pair<int, string> > across;
  vector<pair<int, string> > down;
  pair<int, string> p;
  for(int i=0; i<r; i++){
    string str = "";
    int start = number[i][0];
    for(int j=0; j<c; j++){
      if(grid[i][j]=='*' || j==c-1){
	if(j==c-1) {
	  if(grid[i][j]!='*')str += grid[i][j];
	}
	p.first = start;
	p.second = str;
	across.push_back(p);
	str = "";
	if(j!=c-1)start = number[i][j+1];
      }else{
	if(grid[i][j]!='*')str += grid[i][j];
      }
    }
  }

  /* parse col */
  for(int j=0; j<c; j++){
    string str = "";
    int start = number[0][j];
    for(int i=0; i<r; i++){
      if(grid[i][j]=='*' || i==r-1){
	if(i==r-1) {
	  if(grid[i][j]!='*')str += grid[i][j];
	}
	p.first = start;
	p.second = str;
	down.push_back(p);
	str = "";
	if(i!=r-1)start = number[i+1][j];
      }else{
	if(grid[i][j]!='*')str += grid[i][j];
      }
    }
  }

  sort(across.begin(), across.end());
  sort(down.begin(), down.end());
  cout << "Across" << endl;
  for(int i=0; i<across.size(); i++){
    if(across[i].first != 0){
      printf("%3d", across[i].first);
      cout << "." << across[i].second << endl;
    }
  }
  cout << "Down" << endl;
  for(int i=0; i<down.size(); i++){
    if(down[i].first!=0){
      printf("%3d", down[i].first);
      cout << "." << down[i].second << endl;
    }
  }
}

main(){
  for(int i=1; read(); i++){
    if(i!=1) cout << endl;
    cout << "puzzle #" << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
