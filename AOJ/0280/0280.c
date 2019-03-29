#include<stdio.h>
#include<string.h>
#define MAX 10

void play(char *line, int N){
  int i, j, minj, tmp;
  int C[N];
  int B = 0;
  for (i = 0; i < N; i++ ) C[i] = 0;

  for ( i = 0; i < strlen(line); i++ ){
    int p = i%N;
    if ( line[i] == 'M' ){
      C[p]++;
    } else if ( line[i] == 'S' ){
      C[p]++;
      B += C[p];
      C[p] = 0;
    } else if ( line[i] == 'L' ){
      C[p] += B + 1;
      B = 0;
    }
  }

  // selection sort;
  for ( i = 0; i < N; i++ ){
    minj = i;
    for ( j = i; j < N; j++ )
      if ( C[j] < C[minj] ) minj = j;
    tmp = C[i];
    C[i] = C[minj];
    C[minj] = tmp;
  }

  for ( i = 0; i < N; i++ ) printf("%d ", C[i]);
  printf("%d\n", B);
}

int main(){
  int N;
  char line[101];
  while(1){
    scanf("%d", &N);
    if ( N == 0 ) break;
    scanf("%s", line);
    play(line, N);
  }
  return 0;
}
