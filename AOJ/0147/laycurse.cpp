#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,t;
  int seat;

  int bit[6]={0,1,3,7,15,31};

  int arrive[100],sit[100],bye[100],place[100];
  int len[100], need[100];
  int st;

  seat=0;
  REP(i,17,30) seat |= (1<<i);

  rep(i,100) arrive[i]=i*5;
  rep(i,100) {len[i]=2; if(i%5==1) len[i]=5;}
  rep(i,100) need[i]=17*(i%2)+3*(i%3)+19;

  rep(i,100) sit[i]=bye[i]=-1;

  st=0;
  rep(t,650){
    rep(i,100) if(bye[i]==t) seat ^= (bit[len[i]] << place[i]);
    while(st<100 && arrive[st]<=t){
      rep(i,17) if(!(seat&(bit[len[st]]<<i))) break;
      if(i==17) break;
      sit[st]=t; bye[st]=t+need[st]; place[st]=i;
      seat ^= (bit[len[st]] << place[st]);
      st++;
    }
  }

  while(scanf("%d",&i)==1) printf("%d\n",sit[i]-arrive[i]);

  return 0;
}
