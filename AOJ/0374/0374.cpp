#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int val(char ch){ return ch-'0';}

int sub(string maxs, string mins){
  for ( int i = 0; i < maxs.size(); i++ ){
    if ( maxs[i] != mins[i] ) {
      if ( i == maxs.size()-1 )
	return val(maxs[i]) - val(mins[i]);
      if ( i == maxs.size()-2 )
	return (10*val(maxs[i])+val(maxs[i+1])) - (10*val(mins[i])+val(mins[i+1]));
      return 10;
    }
  }
  return 0;
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
  for( int p = 0; p < S.size(); p++){
    int v = val(S[p]);
    if ( S[p] == '1' && p+1 < S.size()) {
	v = 10 + val(S[p+1]);
	p++;
    }
    maxv = max(maxv, v);
    minv = min(minv, v);
  }
  return maxv - minv;
}
    
main(){
  string S;
  cin >> S;
  cout << min(checkEqual(S), check12(S)) << endl;
}
