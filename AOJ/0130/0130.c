#include<stdio.h>
#include<string.h>

int main(){
  int n, t, i; scanf("%d", &n);
  char s[1025];            /* 巡回記録 最大1024文字*/
  char form[27], tmp[27];  /* 列車の編成 最大26両*/
  for ( t = 0; t < n; t++ ) {
    scanf("%s", s);
    form[0] = s[0]; form[1] = '\0'; /* 始点の車両 */
    for ( i = 3; i < strlen(s); i += 3 ){
      if ( strchr(form, (int)s[i]) != NULL ) continue;
      if ( s[i - 1] == '>' ) snprintf(tmp, 27, "%s%c", form, s[i]);
      else snprintf(tmp, 27, "%c%s", s[i], form);
      strcpy(form, tmp);
    }
    printf("%s\n", form);
  }
  return 0;
}
