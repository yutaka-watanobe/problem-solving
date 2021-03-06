#include<stdio.h>
#include<stdlib.h>

int col[1000], row[1000];

int descend(const void *a, const void *b) {
  return *(int*)b - *(int*)a;
}

int main() {
  int i, j, s, t, w, h, sumC = 0, sumR = 0;
  scanf("%d %d", &w, &h);
    
  for ( i = 0; i < w; ++i ) {
    scanf("%d", &col[i]);
    sumC += col[i];
  }
  for ( i = 0; i < h; ++i ) {
    scanf("%d", &row[i]);
    sumR += row[i];
  }

  if ( sumR != sumC ) {
    printf("0\n");
    return 0;
  }
    
  for ( i = 0; i < w; ++i ) {

    qsort(row, h, sizeof(int), descend);//降順ソート

    for ( j = 0; j < h; ++j ) {
      if ( !col[i] || !row[j] ) break;
      --row[j];
      --col[i];
    }

    if ( col[i] > 0 ) {
      printf("0\n");
      return 0;
    }
  }
  printf("1\n");
  return 0;
}
