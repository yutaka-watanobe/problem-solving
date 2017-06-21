// @JUDGE_ID:  17051CA  422  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

char matrix[201][201];
int n;

int read(){
  cin >> n;
  string line;
  for(int i=0; i<n; i++){
    cin >> line;
    for(int j=0; j<n; j++){
      matrix[i][j] = line[j];
    }
  }
}

void parse(string line){
  int size = line.size();
  int id;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      /* E */
      if(j+size-1<n){
	bool b = true; id=0;
	for(int pj=j; pj<j+size; pj++){
	  if(line[id]!=matrix[i][pj]){ b = false; break;}
	  id++;
	}
	if(b){
	  cout << i+1 << "," << j+1 << " " << i+1 << "," << j+size << endl;
	  return;
	}
      }
      /* W */
      if(j-size+1>=0){
	bool b = true; id=0;
	for(int pj=j; pj>=j-size+1; pj--){
	  if(line[id]!=matrix[i][pj]){ b = false; break;}
	  id++;
	}
	if(b){
	  cout << i+1 << "," << j+1 << " " << i+1 << "," << j-size+2 << endl;
	  return;
	}
      }
      /* S */
      if(i+size-1<n){
	bool b = true; id=0;
	for(int pi=i; pi<i+size; pi++){
	  if(line[id]!=matrix[pi][j]){ b = false; break;}
	  id++;
	}
	if(b){
	  cout << i+1 << "," << j+1 << " " << i+size << "," << j+1 << endl;
	  return;
	}
      }
      /* N */
      if(i-size+1>=0){
	bool b = true; id=0;
	for(int pi=i; pi>=i-size+1; pi--){
	  if(line[id]!=matrix[pi][j]){ b = false; break;}
	  id++;
	}
	if(b){
	  cout << i+1 << "," << j+1 << " " << i-size+2 << "," << j+1 << endl;
	  return;
	}
      }
      /* NE */
      if(j+size-1<n && i-size+1>=0){
	bool b = true; id=0;
	int pi=i, pj=j;
	for(int c=0; c<size; c++){
	  if(line[id]!=matrix[pi][pj]){b= false; break;}
	  pi--; pj++; id++;
	}
	if(b){
	  cout << i+1 <<"," << j+1 << " " << i-size+2 << "," << j+size << endl;
	  return;
	}
      }
      /* NW */
      if(j-size+1>=0 && i-size+1>=0){
	bool b = true; id=0;
	int pi=i, pj=j;
	for(int c=0; c<size; c++){
	  if(line[id]!=matrix[pi][pj]){b=false; break;}
	  pi--; pj--; id++;
	}
	if(b){
	  cout << i+1 <<"," << j+1 << " " << i-size+2 << "," << j-size+2 << endl;
	  return;
	}
      }
      /* SE */
      if(j+size-1<n && i+size-1<n){
	bool b = true; id=0;
	int pi=i, pj=j;
	for(int c=0; c<size; c++){
	  if(line[id]!=matrix[pi][pj]){b=false; break;}
	  pi++; pj++; id++;
	}
	if(b){
	  cout << i+1 << "," << j+1 << " " << i+size << "," << j+size << endl;
	  return;
	}
      }
      /* SW */
      if(i+size-1<n && j-size+1>=0){
	bool b = true; id=0;
	int pi=i, pj=j;
	for(int c=0; c<size; c++){
	  if(line[id]!=matrix[pi][pj]){b=false; break;}
	  pi++; pj--; id++;
	}
	if(b){
	  cout << i+1 << "," << j+1 << " " << i+size << "," << j-size+2 << endl;
	  return;
	}
      }
	
    }
  }
  cout << "Not found" << endl;
  return ;
}

void work(){
  string line;
  while(1){
    cin >> line;
    if(line=="0") break;
    
    parse(line);
    
  }
}



main(){
  read();
  work();
}
// @end_of_source_code
