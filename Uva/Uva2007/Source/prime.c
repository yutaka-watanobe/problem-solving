/*　２からNまでの素数を求めるための、Cプログラム */
#include <stdio.h>
#include <math.h>

void main(){
  
  int i,j,limit,n,find;
  
  printf("整数を入力＝");
  scanf("%d",&n); /* キーボードから上限（N)を入力 */
  
  for(i=2;i<=n;i++) {
    /*limit=sqrt(i);*/
    limit=i-1; /* limit=sqrt(i); */ /* 割る数のlimitはi-1 */
    find=1;
    for (j=2;j<=limit;j++){ /* 割る数Jは２からlimitまで */
      if (i%j==0) { /* 割り切れたら素数ではないのでＢｒｅａｋする */
	find=0;
	break;
      }
    }
    if (find==1) { /* findが１のままなら素数 */
      printf("%d ",i);
    }
  }
  printf("\n"); 
}



