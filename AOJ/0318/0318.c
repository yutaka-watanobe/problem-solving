#include <stdio.h>
int tgt[100];

int main(){
  int n,i,num=0;
  scanf("%d",&n);
  while(n--) tgt[n]=1;
  scanf("%d",&n);
  while(n--) {scanf("%d",&i); tgt[i-1]=0;}
  scanf("%d",&n);
  while(n--) {scanf("%d",&i); tgt[i-1]=1;}
  scanf("%d",&n);
  while(n--) {scanf("%d",&i); if(tgt[i-1]) num++;}
  printf("%d\n",num);
  return 0;
}
