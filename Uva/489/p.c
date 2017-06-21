// @JUDGE_ID:  17051CA  489  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
#include<vector>

int read();
void work();
bool judge(vector<char> &v, char c);

int n;

int read(){
  cin >> n;
  if(n==-1) return 0;
  return 1;
}

void work(){
  string line, guess;
  cin >> line;
  cin >> guess;
  set<char> puz;
  vector<char> v;
  puz.clear();
  
  for(int s=0; s<line.size(); s++){
    puz.insert(line[s]);
  }
  v.resize(puz.size());
  copy(puz.begin(), puz.end(), v.begin());

  int cnt = 0;
  for(int s=0; s<guess.size(); s++){

    if(!judge(v, guess[s])){
      cnt++;
    }
    
    if( cnt >= 7 ){
      if( v.size() > 0 ){
	cout << "You lose." << endl;
	return;
      }
    }
    if( v.size() == 0 ){
      if( cnt < 7 ) {
	cout << "You win." << endl;
	return;
      }
    }
  }

  cout << "You chickened out." << endl;
  
}

bool judge(vector<char> &v, char c){
  for(int i=0; i<v.size(); i++){
    if( v[i] == c ){
      v.erase(v.begin()+i);
      return true;
    }
  }
  return false;
}

main(){
  while( read() ){
    cout << "Round " << n << endl;
    work();
  }
}
// @end_of_source_code
