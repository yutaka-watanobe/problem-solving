
#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>

#define N 8
#define S 20
#define X 4
#define POW6X (6 * 6 * 6 * 6)

typedef struct{ int x, y; } point;
typedef struct{ point a[N]; } serpent;
typedef struct{ serpent *s; int n; } serpents;
typedef struct{
  char d;
  serpents s[POW6X];
} cell;

cell swamp[2 * S][2 * S];
serpents serp;
int length, curr;

pow6(int i){
  int r = 1;

  for(; i; i--) r *= 6;
  return r;
}

void bfs(int x, int y){
  char *xq, *yq;
  int dq = 0, eq = 1, c, tmp, i;

  xq = alloca(4 * S * S * sizeof(char)); xq[0] = x;
  yq = alloca(4 * S * S * sizeof(char)); yq[0] = y;
  swamp[y][x].d = 0;
  for(c = 1; dq != eq && c <= S; c++)
    for(tmp = eq; dq != tmp; dq = (dq + 1) % (4 * S * S))
      for(i = 0; i < 6; i++){
	switch(i){
	case 0: x = 1; y = 0; break;
	case 1: x = 0; y = 1; break;
	case 2: x = -1; y = 1; break;
	case 3: x = -1; y = 0; break;
	case 4: x = 0; y = -1; break;
	case 5: x = 1; y = -1;
	}
	x += xq[dq]; y += yq[dq];
	if(x != -1 && x != 2 * S && y != -1 && y != 2 * S &&
	   swamp[y][x].d == -1){
	  xq[eq] = x; yq[eq] = y;
	  eq = (eq + 1) % (4 * S * S);
	  swamp[y][x].d = c;
	}
      }
}

void turnL(int *x, int *y){
  if(*x == 1)
    if(*y == 0){ *x = 0; *y = 1; }
    else *y = 0;
  else if(*x == 0)
    if(*y == 1) *x = -1;
    else *x = 1;
  else
    if(*y == 1) *y = 0;
    else{ *x = 0; *y = -1; }
}

void turnR(int *x, int *y){
  if(*x == 1)
    if(*y == 0) *y = -1;
    else *x = 0;
  else if(*x == 0)
    if(*y == 1){ *x = 1; *y = 0; }
    else{ *x = -1; *y = 0; }
  else
    if(*y == 1) *x = 0;
    else *y = 1;
}

judge(serpent *s, int n){
  int i, x, y, a, b;

  x = s->a[n].x;
  y = s->a[n].y;
  for(i = 0; i < n - 1; i++){
    a = s->a[i].x;
    b = s->a[i].y;
    if((x + 0 == a && y + 0 == b) ||
       (x + 1 == a && y + 0 == b) ||
       (x + 0 == a && y + 1 == b) ||
       (x - 1 == a && y + 1 == b) ||
       (x - 1 == a && y + 0 == b) ||
       (x + 0 == a && y - 1 == b) ||
       (x + 1 == a && y - 1 == b))
      return 0;
  }
  return 1;
}

void add(serpent *s){
  cell *c;
  serpent *t;
  int n, x, y, d, i, j;

  d = 0;
  for(i = 0; i < X && i < length - 1; i++){
    x = s->a[i + 1].x - s->a[i].x;
    y = s->a[i + 1].y - s->a[i].y;
    d *= 6;
    if(x == 1 && y == 0) d += 0;
    else if(x == 0 && y == 1) d += 1;
    else if(x == -1 && y == 1) d += 2;
    else if(x == -1 && y == 0) d += 3;
    else if(x == 0 && y == -1) d += 4;
    else if(x == 1 && y == -1) d += 5;
  }
  x = s->a[0].x;
  y = s->a[0].y;
  c = &swamp[y][x];
  n = c->s[d].n;
  for(i = 0; i < n; i++){
    t = c->s[d].s + i;
    for(j = 0; j < length; j++)
      if(t->a[j].x != s->a[j].x ||
	 t->a[j].y != s->a[j].y) break;
    if(j == length) return;
  }
  c->s[d].s = realloc(c->s[d].s, (n + 1) * sizeof(serpent));
  for(i = 0; i < length; i++){
    t = c->s[d].s + n;
    t->a[i].x = s->a[i].x;
    t->a[i].y = s->a[i].y;
  }
  c->s[d].n++;
  serp.s = realloc(serp.s, (serp.n + 1) * sizeof(serpent));
  for(i = 0; i < length; i++){
    t = serp.s + serp.n;
    t->a[i].x = s->a[i].x;
    t->a[i].y = s->a[i].y;
  }
  serp.n++;
}

move(serpent *s, int n){
  int x, y, a, b, c, d, e, f, i, j;

  if(n == 0){
    a = s->a[1].x; b = s->a[1].y;
    x = s->a[0].x - a; y = s->a[0].y - b;
    if(curr + swamp[b + y][a + x].d * 2 - 3 > S)
      return 0;
    if(move(s, n + 1)) return 1;
    for(i = 0; i < 2; i++){
      c = x; d = y;
      if(i) turnL(&c, &d);
      else turnR(&c, &d);
      if(swamp[b + d][a + c].d != -2){
	s->a[0].x = a + c;
	s->a[0].y = b + d;
	if(judge(s, n + 1)){
	  if(n + 2 < length){
	    if(move(s, n + 2)) return 1;
	  }else if(swamp[b + d][a + c].d == 0) return 1;
	  else add(s);
	}
      }
    }
    s->a[0].x = a + x;
    s->a[0].y = b + y;
  }else if(n == length - 1){
    a = s->a[n - 1].x; b = s->a[n - 1].y;
    x = s->a[n].x - a; y = s->a[n].y - b;
    if(judge(s, n)){
      if(swamp[s->a[0].y][s->a[0].x].d == 0) return 1;
      add(s);
    }
    for(i = 0; i < 2; i++){
      c = x; d = y;
      if(i) turnL(&c, &d);
      else turnR(&c, &d);
      if(swamp[b + d][a + c].d != -2){
	s->a[n].x = a + c;
	s->a[n].y = b + d;
	if(judge(s, n)){
	  if(swamp[s->a[0].y][s->a[0].x].d == 0) return 1;
	  add(s);
	}
      }
    }
    s->a[n].x = a + x;
    s->a[n].y = b + y;
  }else{
    x = s->a[n].x;
    y = s->a[n].y;
    if(judge(s, n))
      if(move(s, n + 1)) return 1;
    a = s->a[n - 1].x - x;
    b = s->a[n - 1].y - y;
    c = s->a[n + 1].x - x;
    d = s->a[n + 1].y - y;
    e = a + c; f = b + d;
    if((e * e + f * f == 1 ||
       (e == -1 && f == 1) || (e == 1 && f == -1)) &&
       swamp[y + f][x + e].d != -2){
      s->a[n].x = x + e;
      s->a[n].y = y + f;
      if(judge(s, n + 1))
	if(n + 2 < length){
	  if(move(s, n + 2)) return 1;
	}else{
	  if(swamp[s->a[0].y][s->a[0].x].d == 0) return 1;
	  add(s);
	}
      s->a[n].x = x;
      s->a[n].y = y;
    }
  }
  return 0;
}

main(){
  serpent *s;
  int n, ox, oy, x, y, i, j, k, tmp;

  while(1){
    scanf("%d", &length);
    if(length == 0) return 0;
    tmp = pow6(length);
    for(i = 0; i < 2 * S; i++)
      for(j = 0; j < 2 * S; j++){
	swamp[i][j].d = -1;
	for(k = 0; k < POW6X && k < tmp; k++){
	  swamp[i][j].s[k].s = NULL;
	  swamp[i][j].s[k].n = 0;
	}
      }
    s = malloc(sizeof(serpent));
    n = 1;
    scanf("%d %d", &ox, &oy);
    s[0].a[0].x = S;
    s[0].a[0].y = S;
    for(i = 1; i < length; i++){
      scanf("%d %d", &x, &y);
      x -= ox - S;
      y -= oy - S;
      s[0].a[i].x = x;
      s[0].a[i].y = y;
    }
    scanf("%d", &k);
    for(i = 0; i < k; i++){
      scanf("%d %d", &x, &y);
      x -= ox - S;
      y -= oy - S;
      if(x >= 0 && x < 2 * S &&
	 y >= 0 && y < 2 * S)
	swamp[y][x].d = -2;
    }
    scanf("%d %d", &x, &y);
    bfs(x - ox + S, y - oy + S);
    for(curr = 1; curr <= S + 1; curr++){
      /* printf(" %d %d\n", curr - 1, n); */
      serp.s = NULL; serp.n = 0;
      for(i = 0; i < n; i++)
	if(move(s + i, 0)){
	  /*
	  for(j = 0; j < length; j++)
	    printf(" %d,%d", s[i].a[j].x, s[i].a[j].y);
	  printf("\n");
	  */
	  break;
	}
      if(i != n) break;
      free(s);
      s = serp.s;
      n = serp.n;
    }
    if(curr > S) return -1;
    /* tmp = 0; */
    tmp = pow6(length);
    for(i = 0; i < 2 * S; i++)
      for(j = 0; j < 2 * S; j++)
	for(k = 0; k < POW6X && k < tmp; k++){
	  /* if(swamp[i][j].n[k] > tmp)
	     tmp = swamp[i][j].n[k]; */
	  free(swamp[i][j].s[k].s);
	}
    /* printf("max:%d\n", tmp); */
    free(serp.s);
    free(s);
    printf("%d\n", curr);
  }
}

