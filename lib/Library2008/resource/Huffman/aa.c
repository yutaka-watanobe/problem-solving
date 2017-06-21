#include<stdio.h>
#define size 999999
#define uchar unsigned char

void downheap(int k, int n);

static int heap[256], w[512], index[256], left[512], right[512];

void downheap( int k, int n ){
  int j, u, v;
  u = heap[k];
  v = index[k];
  while ( k <= n/2 ){
    j = k + k;
    if ( j < n && heap[j] > heap[j + 1] ) j++;
    if ( u <= heap[j] ) break;
    heap[k] = heap[j];  
    index[k] = index[j];
    k = j;
  }
  heap[k] = u;
  index[k] = v;
}

int main(){
  int i, j, k, h, m, n, new;
  char S[size];
  
  /* Input the string to be encoded */
  scanf("%s", S);

  /* Compute the wight of each character */
  for ( i = 0; i < 256; i++ ) { w[i] = 0; index[i] = 0;}
  i = 0;

  while ( S[i] != '\0' ) w[S[i++]]++;

  /* Construct the indirect heap */
  h = 0;
  for ( i = 0; i < 256; i++ )
    if ( w[i] > 0 ) { h++; heap[h] = w[i]; index[h] = i;}

  for ( i = h/2; i >= 1; i-- ) downheap( i, h );

  /* Construct the binary tree */
  new = 256;
  while( h > 1 ){
    i = index[1];
    heap[1] = heap[h]; index[1] = index[h--];
    downheap( 1, h );
    j = index[1];
    k = new++;
    w[k] = w[i] + w[j];
    heap[1] = w[k]; index[1] = k;
    left[k] = i; right[k] = j;
    downheap(1, h );
  }

  /* Output the binary tree constructed */
  for ( i = new-1; i >= 256; i-- ){
    if ( left[i] >= 256 ) printf("left  son of %4d is %4d\n", i, left[i] );
    else printf("left  son of %4d is %4c\n", i, left[i] );

    if ( right[i] >= 256 ) printf("right son of %4d is %4d\n", i, right[i] );
    else printf("right son of %4d is %4c \n", i, right[i] );
  }

  return 0;
}

