// @JUDGE_ID:  17051CA  706  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

class Digit{
 public:
  vector<vector<char> > v;
  Digit(){}
  Digit(int s, char c){
    v.resize(2*s+3);
    for(int i=0; i<v.size(); i++) v[i].resize(s+2);

    for(int i=0; i<v.size(); i++){
      for(int j=0; j<v[i].size(); j++){
	v[i][j] = ' ';  
	if(j!=0 && j!=s+1){
	  if(i==0) {
	    if( c!='1' && c!='4'){
	      v[i][j] = '-';
	    }
	  }else if(i==s+1){
	    if( c!='1' && c!='7' && c!='0' ){
	      v[i][j] = '-';
	    }
	  }else if(i==2*s+2){
	    if( c!='1' && c!='4' && c!='7' ){
	      v[i][j] = '-';
	    }
	  }
	}
	if(0 < i && i < s+1){
	  if(j==0){
	    if(c=='6' || c=='4' || c=='5' || c=='8' || c=='9' || c=='0'){
	      v[i][j] = '|';
	    }
	  }else if(j==s+1){
	    if(c!='5' && c!='6'){
	      v[i][j] = '|';
	    }
	  }
	}else if( s+1 < i && i < 2*s+2){
	  if(j==0){
	    if(c=='2' || c=='6' || c=='8' || c=='0'){
	      v[i][j] = '|';
	    }
	  }else if(j==s+1){
	    if(c!='2'){
	      v[i][j] = '|';
	    }
	  }
	}
      }
    }
  }
};

int read();
void work();

int s;
string n;

int read(){
  cin >> s >> n;
  if( s==0 && n=="0" ) return 0;
  return 1;
}

void work(){
  vector<vector<char> > g;
  vector<Digit> d;

  int size = n.size();
  for(int i=0; i<size; i++){
    Digit dig = Digit(s, n[i]);
    d.push_back(dig);
  }

  g.resize(2*s+3);
  for(int i=0; i<g.size(); i++) g[i].resize( (s+2)*size  );

  int id;
  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g[i].size(); j++){
      id = j/(s+2);
      g[i][j] = d[id].v[i][j%(s+2)];
    }
  }

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g[i].size(); j++){
      if( j%(s+2)==0 && j!=0) cout << " ";
      cout << g[i][j];
    }
    cout << endl;
  }
}

main(){
  for(int i=0; read(); i++){
    work();
    cout << endl;
  }
}
// @end_of_source_code
