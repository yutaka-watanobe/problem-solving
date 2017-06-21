#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

const int SMAX = 100000;
const int DIVISOR = 1234577;

int table[SMAX];

bool match(const char *str, const char *query){
  while(*query != '\0'){
    if(*str != *query)
      return false;
    ++str;
    ++query;
  }
  return true;
}

// imcomplete
void rabinKarp(const char *str, const char *query){
  int m = strlen(query);
  int key = 0;
  for(int i = 0; i < m; ++i)
    key += (unsigned int)query[i] << ((m - i - 1) * 4);
  
  int curr = 0;
  for(int i = 0; i < m; ++i)
    curr += (unsigned int)str[i] << ((m - i - 1) * 4);
  
  int len = strlen(str) - m + 1;
  for(int i = 0; i < len; ++i){
    if(curr == key){
      if(match(str+i, query))
        cout << "match" << endl;
      else
        cout << "not match" << endl;
    }
    
    curr -= (unsigned int)str[i] << ((m - 1) * 4);
    curr <<= 4;
    curr += str[i+m];
  }
}

int main(void){
  ifstream fin("target");
  string str;
  while(!fin.eof())
    str += fin.get();

  string query;
  cout << "input search string : ";
  cin >> query;

  rabinKarp(str.c_str(), query.c_str());
  
  fin.close();
  
  return 0;
}
