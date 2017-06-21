#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string T = "abcdefghijklmnopqrstuvwxyz";

main(){
  int n, a, b, diff;
  string str;
  vector<pair<int, int> > in;
  
  while(1){
    cin >> n;
    if ( n == 0 ) break;
    cin >> str;
    in.clear();

    for ( int i = 0; i < n; i++ ){
      cin >> a >> b;
      a--; b--;
      in.push_back(make_pair(a, b));
    }

    for ( int i = 0; i < n; i++ ){
      a = in[n-i-1].first;
      b = in[n-i-1].second;

      diff = (b - a);

      str[a] = T[(str[a]-'a'+diff)%26];
      str[b] = T[(str[b]-'a'+diff)%26];

      swap(str[a], str[b]);            
    }

    cout << str << endl;
    
  }
}
