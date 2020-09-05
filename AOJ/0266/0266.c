#include<stdio.h>

int G[][2] = {{1, 2}, {-1, 3}, {1, -1}, {4, 5}, {5, 2}, {2, 1}};

int main(){
  char S[101];
  int cur, i;
  while(1){
    scanf("%s", S);
    if ( S[0] == '#' ) break;
    cur = 0; /* A市を出発 */
    for ( i = 0; S[i] != '\0'; i++ ){
      if ( cur == -1 ) break;
      cur = G[cur][S[i] - '0'];
    }
    printf(cur == 5 ? "Yes\n" : "No\n" ); /* B市か判定 */
  }
  return 0;
}
