#include<stdio.h>

int n,a,t[102];

int main(){
  int i;
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a);
    t[a]++;
  }
  for(i = 100; i > 0; i--){
    t[i] += t[i+1];
    if(t[i] >= i){
      printf("%d\n", i);
      return 0;
    }
  }
}
