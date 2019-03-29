#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string S;

int val(char ch){ return ch-'0';}

int sub(string maxs, string mins){
  int k = mins.size();
  int carry = 0;
  int ans;
  if ( val(maxs[k-1]) < val(mins[k-1]) ){
    ans = 10 + val(maxs[k-1]) - val(mins[k-1]);
    carry = -1;
  } else {
    ans = val(maxs[k-1]) - val(mins[k-1]);
    carry = 0;
  }
  
  for ( int i = k-2; i >= 0; i-- ){
    int u = carry + val(maxs[i]);
    int d = val(mins[i]);
    int a;
    if ( u < d ){
      carry = -1;
      a = 10 + u - d;
    } else {
      carry = 0;
      a = u - d;
    }
    if ( a > 0 ) return 10;
  }
  return ans;
}

int checkEqual(string S){
  string mins, maxs;
  int ans = 8;
  for ( int k = 1; k < S.size(); k++ ){
    if ( S.size()%k != 0 ) continue;
    mins = maxs = S.substr(0, k);
    for ( int s = 0; s < S.size(); s += k ){
      maxs = max(maxs, S.substr(s, k));
      mins = min(mins, S.substr(s, k));
    }
    ans = min(ans, sub(maxs, mins));
  }
  return ans;
}

int check12(string S){
  int maxv = 0;
  int minv = 10;
  int p = 0, v;
  while(p<S.size()){
    v = val(S[p]);
    if ( S[p] == '1' ){
      if ( p+1<S.size()) {
	v = 10 + val(S[p+1]);
	p++;
      }
    }
    p++;
    maxv = max(maxv, v);
    minv = min(minv, v);
  }
  return maxv - minv;
}
    
main(){
  cin >> S;
  int ans = 8;
  ans = min(ans, checkEqual(S));
  ans = min(ans, check12(S));
  cout << ans << endl;
}
