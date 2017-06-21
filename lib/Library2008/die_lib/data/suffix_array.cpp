/*
  同じテキストで複数の異なったキーワードを検索するのに有利.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ccpCmp(const char* a, const char* b){
  return strcmp(a, b) < 0;
}

class SuffixArray{
public:

  SuffixArray(const char* str = NULL){
    mk(str);
  }

  // O(n log n)
  void mk(const char* str){
    head = str;
    if(head){
      int len = strlen(str);

      data.resize(len);
      for(int i = 0; i < len; ++i)
        data[i] = &str[i];
      sort(data.begin(), data.end(), ccpCmp);
    }
  }

  // O(km log n)
  vector<int> find(const char* str) const {
    vector<int> res;
    if(head){
      vector<const char*>::const_iterator iter =
        lower_bound(data.begin(), data.end(), str, ccpCmp);
      int len = strlen(str);
      while(iter != data.end() && strncmp(*iter, str, len) == 0){
        res.push_back(*iter - head);
        ++iter;
      }
    }
    return res;
  }

  
private:
  const char* head;
  vector<const char*> data;
  
};

SuffixArray array;

int main(void){
  string text, target;
  cin >> text >> target;
  
  array.mk(text.c_str());
  //*/
  vector<int> indices = array.find(target.c_str());
  for(int i = 0; i < indices.size(); ++i)
    cout << indices[i] << endl;
  //*/

  return 0;
}
