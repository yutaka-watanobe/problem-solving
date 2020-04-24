#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static const int M = 1000000007;
static const int N_MAX = 200000;
long long fact[N_MAX+1];

void compute(int N, int H){
  vector<int> word, invalid(N, 0);
  for ( int i = 0; i < N; i++ ) word.push_back(i);
  int s, t;
  for ( int i = 0; i < H; i++ ){
    cin >> s >> t; s--; t--; // to 0 origin
    swap(word[s], word[t]); 
  }

  for ( int i = 0; i < N; i++ ) if ( word[i] != i ) invalid[i] = 1;

  long long ans = 0;
  vector<int> deleted, inserted;
  for ( int i = 0; i < N; i++ ){
    long long unable = min(word[i], i);
    for ( int j = 0; j < deleted.size(); j++ )
      if ( deleted[j] < word[i] ) unable--;
    for ( int j = 0; j < inserted.size(); j++ )
      if ( inserted[j] < word[i] ) unable++;

    ans += ((word[i] - unable) * fact[N-i-1])%M;
    ans %= M;

    if ( invalid[i] ){
      deleted.push_back(i);
      inserted.push_back(word[i]);
    }
  }
  
  cout << ans << endl;
}

main(){
  fact[0] = 1;
  for ( int i = 1; i <= N_MAX; i++ ) fact[i] = (fact[i-1]*i)%M;
  
  int N, H;
  while(1){
    cin >> N;
    if ( N == 0 ) break;
    cin >> H;
    compute(N, H);
  }
}
