#include<stdio.h>
#define M 1000000007
#define N_MAX 200000
long long fact[N_MAX+1];

void compute(int N, int H){
  int word[N_MAX], invalid[N_MAX];
  int deleted[100], inserted[100];
  int d_p = 0, i_p = 0;
  int i, j, s, t;
  long long ans = 0, unable;
  for ( i = 0; i < N; i++ ) {
    invalid[i] = 0;
    word[i] = i;
  }

  for ( int i = 0; i < H; i++ ){
    scanf("%d %d", &s, &t);
    s--; t--; // to 0 origin
    int tmp = word[s];
    word[s] = word[t];
    word[t] = tmp;
  }

  for ( i = 0; i < N; i++ ) if ( word[i] != i ) invalid[i] = 1;

  for ( i = 0; i < N; i++ ){
    unable = (word[i] < i) ? word[i] : i;
    for ( j = 0; j < d_p; j++ )
      if ( deleted[j] < word[i] ) unable--;
    for ( j = 0; j < i_p; j++ )
      if ( inserted[j] < word[i] ) unable++;

    ans += ((word[i] - unable) * fact[N-i-1])%M;
    ans %= M;

    if ( invalid[i] ){
      deleted[d_p++] = i;
      inserted[i_p++] = word[i];
    }
  }

  printf("%lld\n", ans);
}

int main(){
  int i;
  fact[0] = 1;
  for (i = 1; i <= N_MAX; i++ ) fact[i] = (fact[i-1]*i)%M;
  
  int N, H;
  while(1){
    scanf("%d", &N);
    if ( N == 0 ) break;
    scanf("%d", &H);
    compute(N, H);
  }

  return 0;
}
