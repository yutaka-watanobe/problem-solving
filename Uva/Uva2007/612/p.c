// @JUDGE_ID:  17051CA  612  C++
// @begin_of_source_code
/* Sort */
/* Use function object */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

class DNA{
 public:
  int id;
  int measure;
  string seq;
  
  DNA(){}
  DNA(int i, string s){
    id = i;
    seq = s;
    countM();
  }

  void countM(){
    measure = 0;

    char ch;
    for ( int i = 0; i < seq.size(); i++ ){
      ch = seq[i];
      for ( int j = i+1; j < seq.size(); j++ ){
	if ( ch > seq[j] ){
	  measure++;
	}
      }
    }

  }

};

class DNASortCriterion{
 public:
  bool operator() ( const DNA &d1, const DNA &d2 ) const{
    if ( d1.measure < d2.measure ) return true;
    else if ( d1.measure == d2.measure ) {
      if ( d1.id < d2.id ) return true;
      else return false;
    }else{
      return false;
    }
  }
};

int N, M;
vector<DNA> V;

int read(){
  cin >> N >> M;
  string line;
  V.clear();

  for ( int i = 0; i < M; i++ ){
    cin >> line;
    V.push_back( DNA(i, line) );
  }
}

void work(){
  sort( V.begin(), V.end(), DNASortCriterion() );

  for ( int i = 0; i < M; i++ ){
    cout << V[i].seq << endl;
  }

}

main(){
  int t;
  cin >> t;

  for ( int i = 0; i < t; i++ ){
    if( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
