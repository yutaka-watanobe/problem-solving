// @JUDGE_ID:  17051CA  10602  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>

class Word{
 public:
  string word;
  int similarity;
  Word(){}

  Word(string word, int similarity):word(word), similarity(similarity){}

  bool operator < ( const Word &w ) const{
    if ( similarity == w.similarity ){
      return word > w.word;
    }
    else if ( similarity > w.similarity ) return true;
    else return false;
  }
};

class EditorNottobad{
 public:
  string start;
  vector<Word> words;
  int n;

  int getSimilarity(string word){
    int i, j;
    i = 0; j = 0;
    while ( i < word.size() && j < start.size() && word[i] == start[j]){
      i++; j++;
    }
    return i;
  }

  void read(){
    words.clear();
    string word;
    cin >> n;
    cin >> start;
    words.push_back( Word(start, start.size() ) );

    for ( int i = 1; i < n; i++ ) {
      cin >> word;
      words.push_back( Word(word, getSimilarity(word)) );
    }
  }

  int getDist( string source, string target ){

    int i, j;
    i = 0; j = 0;
    while ( i < source.size() && j < target.size() && source[i] == target[j]){
      i++; j++;
    }
    int sim = i;

    return target.size() - i ;

  }

  void work(){
    sort( words.begin(), words.end() );
    int cost = start.size();
    for ( int i = 1; i < words.size(); i++ ){
      cost += getDist( words[i-1].word, words[i].word );
    }

    cout << cost << endl;
    for ( int i = 0; i < words.size(); i++ ){
      cout << words[i].word << endl;
    }

  }
};

main(){
  EditorNottobad EN;
  int tcase;
  cin >> tcase;
  for ( int i = 0; i < tcase; i++ ){
    EN.read();
    EN.work();
  }
}

// @end_of_source_code


