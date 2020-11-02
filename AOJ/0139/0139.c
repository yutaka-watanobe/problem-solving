#include<stdio.h>
#include<string.h>

int isA(char *s){
  int i, c = -1, len = strlen(s);
  if ( s[0] != '>' || s[1] != '\'' ||
       s[len - 1] != '~' ) return 0;
  for ( i = 2; i < len; i++ )
    if ( s[i] == '#' ) { c = i; break; }
  if ( c == -1 ) return 0;
  if ( c - 2 != len - 1 - (c + 1) ) return 0;
  for ( i = 2; i < c; i++ )
    if ( s[i] != '=' || s[c + i - 1] != '=' ) return 0;
  return len > 4;
}

int isB(char *s){
  int i, len = strlen(s);
  if ( s[0] != '>' || s[1] != '^' ||
       s[len - 2] != '~' || s[len - 1] != '~' ) return 0;
  for ( i = 2; i <= len - 4; i += 2 )
    if ( s[i] != 'Q' || s[i + 1] != '=' ) return 0;
  return len > 4;
}

int main(){
  int n; scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) {
    char snake[1000]; scanf("%s", snake);
    if ( isA(snake) ) printf("A\n");
    else if ( isB(snake) ) printf("B\n");
    else printf("NA\n");
  }
  return 0;
}
