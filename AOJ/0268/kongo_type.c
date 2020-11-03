#include<stdio.h>
#include<string.h>

int main() {
  unsigned int b;
  double res, frac;
  char s[20];
  int i, q;
  scanf("%d", &q);

  while ( q-- ) {
    scanf("%x", &b);

    res = (b&0x7fffffff) >> 7;//整数部の値で初期化
	
    //小数部を加算
    frac = 0.5;
    for ( i=6; i>=0; --i ) {
      if ( (b>>i)&1 ) res += frac;
      frac *= 0.5;
    }

    //出力フォーマット
    snprintf( s, 20, "%16.15lf", res );
    for ( i=strlen(s)-1; i>0; --i ) {
      if ( s[i] == '0' ) s[i] = '\0';
      else break;
    }
    printf("%s%s%s\n", (b>>31)?"-":"", s, (b&0x0000007f)?"":"0");

  }

  return 0;
}
