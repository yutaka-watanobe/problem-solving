#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

class Word{
public:
  string name;
  int cnt, pos;
  Word(string name, int cnt, int pos):name(name), cnt(cnt), pos(pos){ cnt = 0; pos = 0;}
  bool operator < ( const Word &w ) const{
    //    if ( cnt == w.cnt ) return  pos > w.pos;
    //    return cnt > w.cnt;
    if ( cnt == w.cnt ) return  name < w.name;
  return cnt > w.cnt;
  }
};

main(){
  int n;
  string line, word;
  char ch;
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    getline(cin, line);
    vector<string> tmp;
    map<string, int> post, cntt;
    set<string> buffer;
    vector<Word> W;
    for ( int i = 0; i < n; i++ ){
      getline(cin, line);
      stringstream sin(line);
      while( sin >> word ) {
	tmp.push_back(word);
      }
    }
    cin >> ch;
    
    for ( int i = 0; i < tmp.size(); i++ ){
      if ( tmp[i][0] == ch ) {
	buffer.insert(tmp[i]);
	post[tmp[i]] = i;
	cntt[tmp[i]]++;
      }
    }

    for ( set<string>::iterator it = buffer.begin(); it != buffer.end(); it++ ){
      W.push_back(Word(*it, cntt[*it], post[*it]));
    }

    sort(W.begin(), W.end());
    getline(cin, line);

    if ( W.size() == 0 ){
      cout << "NA" << endl;
    } else {
      for ( int i = 0; i < min(5, (int)W.size()); i++ ) {
	if (i ) cout << " ";
	cout << W[i].name;
      }
      cout << endl;
    }

  }
}
