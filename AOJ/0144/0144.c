#include<stdio.h>
#define MAX 100
#define INF (1<<21)
int n, M[MAX][MAX], Q[MAX*2], head, tail;

int dequeue(){
    int x = Q[head++];
    return x;
}

void enqueue(int x){
    Q[tail++] = x;
}

int isEmpty(){ return head == tail; }

int bfs( int s, int t ){
    int i, u, v, d[MAX];
    head = tail = 0;
    enqueue(s);
    for ( i = 0; i < n; i++ ) d[i] = INF;
    d[s] = 1;

    while( !isEmpty() ){
	u = dequeue();
	for ( v = 0; v < n; v++ ){
	    if ( !M[u][v] ) continue;
	    if ( d[v] == INF ){
		d[v] = d[u] + 1;
		enqueue(v);
	    }
	}
    }
    return d[t];
}

main(){
    int i, j, s, t, k, tl, q, c;
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
	for ( j = 0; j < n; j++ ) M[i][j] = 0;
    for ( i = 0; i < n; i++ ){
	scanf("%d %d", &s, &k);
	for ( j = 0; j < k; j++ ){
	    scanf("%d", &t);
	    M[s-1][t-1] = 1;
	}
    }
    scanf("%d", &q);
    for ( i = 0; i < q; i++ ){
	scanf("%d %d %d", &s, &t, &tl);
	c = bfs(s-1, t-1);
	if ( c <= tl ) printf("%d\n", c);
	else printf("NA\n");
    }
    return 0;
}
