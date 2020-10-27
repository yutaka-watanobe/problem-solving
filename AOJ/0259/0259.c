#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ascend(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
}

int descend(const void *a, const void *b) {
  return *(char *)b - *(char *)a;
}

void solve(char *N){
  int num, cnt = 0;
  char L[5],  S[5];
  if ( N[0] == N[1] && N[1] == N[2] && N[2] == N[3] ) {
    printf("NA\n"); return;
  }
  for( cnt = 0; strncmp(N, "6174", 4) != 0; cnt++ ){
    strncpy(L, N, 4);
    strncpy(S, N, 4);
    qsort(L, 4, 1, descend); /* 降順にソート*/
    qsort(S, 4, 1, ascend);  /* 昇順にソート*/
    num = strtol(L, NULL, 10) - strtol(S, NULL, 10);
    sprintf(N, "%04d", num);
  }
  printf("%d\n", cnt);
}

int main(){
  char N[5];
  while ( scanf("%s", N) == 1 && strncmp( N, "0000", 4 ) != 0 ) {
    solve(N);
  }
  return 0;
}
