#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void mkKMPTable(int* table, const char* pat){
  int n = strlen(pat);
  table[0] = -1;  // 先頭で不一致の際は、1 つ進める必要があるため
  table[1] = 0;
  for(int i = 2, j = 0;  i < n; ){
    if(pat[j] == pat[i])
      table[i++] = ++j;
    else if(j > 0)
      j = table[j];
    else
      j = table[i++] = 0;
  }
}

vector<int> kmp(const char* text, const char* pat, const int* table){
  int n = strlen(text), m = strlen(pat);
  vector<int> res;
  for(int i = 0, j = 0; i + j < n; ){
    if(text[i+j] == pat[j]){
      if(++j == m)
        res.push_back(i);
    }
    else{
      i = i + j - table[j];
      if(j > 0) j = table[j];
    }
  }
  return res;
}

int main(void){
  string text, pat;
  int table[1000];

  getline(cin, text);
  getline(cin, pat);

  mkKMPTable(table, pat.c_str());
  vector<int> indices = kmp(text.c_str(), pat.c_str(), table);
  for(int i = 0; i < indices.size(); ++i)
    cout << indices[i] << ' ';
  cout << endl;
  
  return 0;
}
