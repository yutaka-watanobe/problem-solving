#include <stdio.h>
#include <stl.h>
#include <string>

string s;
set<string> even, odd;

int read();
void work();

main(){
  while(read()){
    work();
  }
}

void work(){
  even.clear();
  odd.clear();

  for(int i=0; i<s.size(); i++){
    int j;
    for(j=1; i-j>=0 && i+j<s.size() && s[i+j]==s[i-j]; j++);
    j--;
    if(j>=1) odd.insert(s.substr(i, j+1));

    for(j=0; i-j>=0 && i+j+1<s.size() && s[i+j+1]==s[i-j]; j++);
    j--;
    if(j>=1) even.insert(s.substr(i+1, j+1));
  }
  
  set<string>::iterator cur, prev = odd.end();

  for(cur=odd.begin(); cur!=odd.end(); cur++){
    if(prev!=odd.end()){
      int i;
      for(i=0; i<prev->size() && i<cur->size(); i++){
	if((*prev)[i]!=(*cur)[i]) break;
      }
      if(i>=prev->size()) odd.erase(prev);
    }
    prev = cur;
  }
  
  prev = even.end();
  for(cur=even.begin(); cur!=even.end(); cur++){
    if(prev!=even.end()){
      int i;
      for(i=0; i<prev->size() && i<cur->size(); i++){
	if((*prev)[i]!=(*cur)[i]) break;
      }
      if(i>=prev->size()) even.erase(prev);
    }
    prev = cur;
  }

  vector<string> v;
  string tmp;

  
  for(cur=odd.begin(); cur!=odd.end(); cur++){
    tmp = *cur;
    reverse(tmp.begin(), tmp.end());
    tmp += cur->substr(1);

    v.push_back(tmp);
  }

  for(cur=even.begin(); cur!=even.end(); cur++){
    tmp = *cur;
    reverse(tmp.begin(), tmp.end());
    tmp += *cur;
    
    v.push_back(tmp);
  }

  sort(v.begin(), v.end());

  for(int i=0; i<v.size(); i++){
    if(i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

char buf[100000];
int read(){
  cin.getline(buf, 100000);
  if(cin.eof()) return 0;

  s = "";
  for(int i=0; buf[i]!='\0'; i++){
    if(isalpha(buf[i])) s += toupper(buf[i]);
  }

  return 1;
}
