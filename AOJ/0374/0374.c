#include<stdio.h>
#include<string.h>
#define MAX 100000

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a < b ? b : a; }

int val(char ch){ return ch-'0';}

int sub(char *maxs,char *mins){
  int i;
  for ( i = 0; i < strlen(maxs); i++ ){
    if ( maxs[i] != mins[i] ) {
      if ( i == strlen(maxs)-1 )
	return val(maxs[i]) - val(mins[i]);
      if ( i == strlen(maxs)-2 )
	return (10*val(maxs[i])+val(maxs[i+1])) - (10*val(mins[i])+val(mins[i+1]));
      return 10;
    }
  }
  return 0;
}

int checkEqual(char *S){
  char mins[MAX], maxs[MAX], tmp[MAX];
  int k, s, ans = 8;
  for ( k = 1; k < strlen(S); k++ ){
    if ( strlen(S)%k != 0 ) continue;
    strncpy(mins, S, k);
    strncpy(maxs, S, k);
    for (s = 0; s < strlen(S); s += k ){
      strncpy(tmp, S + s, k);
      if ( strcmp(tmp, maxs) > 0 ) strncpy(maxs, tmp, k);
      if ( strcmp(tmp, mins) < 0 ) strncpy(mins, tmp, k);
    }
    ans = min(ans, sub(maxs, mins));
  }
  return ans;
}

int check12(char *S){
  int maxv = 0;
  int minv = 10;
  int p, v;
  for( p = 0; p < strlen(S); p++){
    v = val(S[p]);
    if ( S[p] == '1' && p+1 < strlen(S) ) {
	v = 10 + val(S[p+1]);
	p++;
    }
    maxv = max(v, maxv);
    minv = min(v, minv);
  }
  return maxv - minv;
}
    
int main(){
  char S[MAX];
  scanf("%s", S);
  printf("%d\n", min(checkEqual(S), check12(S)));
  return 0;
}
