#include<stdio.h>

int main(){
  int n; scanf("%d", &n);
  for ( int t = 0; t < n; t++ ) {
    char s[1025]; scanf("%s", s); // 巡回記録
    char form[51];        // 列車の編成
    int p = 25, l = p, r = p;
    form[p] = s[0];
    for ( int i = 3; s[i - 2]; i += 3 ){
      if ( s[i - 1] == '>' ) p++; else p--;
      form[p] = s[i];
      if ( p < l ) l = p;
      if ( p > r ) r = p;
    }
    for ( int i = l; i <= r; i++ ) printf("%c", form[i]);
    printf("\n");
  }
  return 0;
}
