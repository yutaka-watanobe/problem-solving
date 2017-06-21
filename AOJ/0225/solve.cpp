#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cassert>

using namespace std;

const int MAX_LENGTH = 32;
const int MIN_LENGTH = 1;
const int MIN_WORD = 2;
const int MAX_WORD = 10000;
set<char> c;
map<char,int> in;
map<char,int> out;

bool eularPathExist(){
  int odd = 0;

  for(set<char>::iterator it = c.begin();it != c.end();it++)
    if((in[*it] + out[*it])%2 == 1)
      return false;
  
  return true;
}

main(){
  int n;
  while(cin >> n && n){
        assert(MIN_WORD <= n && n <= MAX_WORD);

    in.clear();
    out.clear();
    c.clear();

    for(int i = 0;i<n;i++){
      string str;
      cin >> str;
      assert(MIN_LENGTH <= str.size() && str.size() <= MAX_LENGTH);
      c.insert(str[0]);
      c.insert(str[str.size()-1]);
      in[str[str.size()-1]]++;
      out[str[0]]++;
    }
    if(eularPathExist())
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
