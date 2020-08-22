#include<iostream>
#include<string>
using namespace std;

int main(){
    int tcase; cin >> tcase;
    for ( int t = 0; t < tcase; t++ ) {
      string line; cin >> line;
      bool vis[26] ={};
      string buffer;
      buffer += line[0];
      vis[line[0]-'a'] = true;
      for (int i = 3; i < line.size(); i += 3){
	if (vis[line[i]-'a']) continue;
	if ( line[i-1] =='>' ) buffer += line[i];
	else buffer = line[i] + buffer;
	vis[line[i]-'a'] = true;
      }
      cout << buffer << endl;
    }
    return 0;
}
