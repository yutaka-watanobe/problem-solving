#include <stdio.h>

#define N 10000

typedef struct {
  int first[N], next[N];
  int color[N], sum1[N], sum2[N];
  int is_root[N];
  int n;
} tree;

void tr_init(tree *tr, int n){
  tr->n = n;
  while(n--){
    tr->first[n] = -1;
    tr->next[n] = -1;
    tr->is_root[n] = 1;
  }
}

void tr_add(tree *tr, int p, int c){
  tr->is_root[c] = 0;
  tr->next[c] = tr->first[p];
  tr->first[p] = c;
}

int tr_sum(tree *tr, int x){
  int b, c, i, j;
  for(i = tr->first[x]; i != -1; i = tr->next[i])
    tr_sum(tr, i);
  tr->sum1[x] = -1u / 2;
  c = 1;
  while(1){
    b = 0;
    j = c;
    for(i = tr->first[x]; i != -1; i = tr->next[i])
      if(tr->color[i] != c)
	j += tr->sum1[i];
      else{
	b = 1;
	j += tr->sum2[i];
      }
    if(j < tr->sum1[x]){
      tr->sum1[x] = j;
      tr->color[x] = c;
    }
    if(!b) break;
    c++;
  }
  tr->sum2[x] = -1u / 2;
  c = 1;
  while(1){
    if(c != tr->color[x]){
      b = 0;
      j = c;
      for(i = tr->first[x]; i != -1; i = tr->next[i])
	if(tr->color[i] != c)
	  j += tr->sum1[i];
	else{
	  b = 1;
	  j += tr->sum2[i];
	}
      if(j < tr->sum2[x])
	tr->sum2[x] = j;
      if(!b) break;

    }
    c++;
  }
  return tr->sum1[x];
}

int main(){
  static tree tr;
  int n, p;
  int c;
  int i, j, k;
  while(scanf("%d", &n) != EOF && 0 < n){
    tr_init(&tr, n);
    for(i = 0; i < n; i++){
      scanf("%d:", &p);
      if(getchar() == '\n') continue;
      c = ' ';
      while(c == ' '){
	k = 0;
	while('0' <= (c = getchar()) && c <= '9')
	  k = 10 * k + c - '0';
	tr_add(&tr, p, k);
      }
    }
    for(i = 0; i < n; i++)
      if(tr.is_root[i])
	break;
    printf("%d\n", tr_sum(&tr, i));
  }
  return 0;
}
