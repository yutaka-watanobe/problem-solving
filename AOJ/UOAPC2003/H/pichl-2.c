#include<stdio.h>
#include<math.h>
#include<stdlib.h>
# define N 1001
int A[N+1][N+1], val[N+1], w[N+1], count;

int fib(int n){
	int fo=1, fn=2, fx, i;
	for(i=1;i<=n;i++){
		fx=fn;fn=fo+fn;fo=fx;
	}
	return fo;
}

void init(int V, int d){
  int i, j, fx, fo=1, fn=2;
  count=0;
  for(i=1;i<=V;i++){
    val[i]=0; for(j=1;j<=V;j++) A[i][j]=0;
  }
  for(i=1;i<=V;i++){
	  w[i]=fn%N; fx=w[i]; fn=(fo+fn)%N; fo=fx;
	//w[i]=fib(i)%N; /*This would be an overflow for darge V*/
	//printf("%d\n",w[i]); /* ... as you can check here... */
  }
  for(i=1;i<=V;i++){
	  for(j=1;j<i;j++){
		  if(abs(w[i]-w[j])<d){A[i][j]=1;A[j][i]=1;}
	  }
  }
}

/* Depth-first search */
void DFS (int k, int V)
{
  int t;
  val[k]=count;
  for (t=1;t<=V;t++){
    if(A[k][t] !=0 && val[t] == 0){
      DFS(t,V);
    }
  }
}

main(){
  FILE *fp;
  int i, V, d;
  if ((fp=fopen("fib.txt", "r"))== NULL){
	  printf("could not open file fib.txt\n"); exit(1);}
  while(fscanf(fp,"%d %d",&V,&d)==2){
     init(V,d);
     for(i=1;i<=V;i++) if(val[i]==0) {count++; DFS(i,V);}
     printf("%d\n",count);
  }
}

/*it is also OK just to sort an array of fibonacci labels without 
doing any graph search*/
