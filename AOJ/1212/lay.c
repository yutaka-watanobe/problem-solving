#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x=32,y=32;
int mpx[35][35],mpy[35][35];

int main(){
  int i,j,k,l,m,n;
  int sx=3,sy=1,dx,dy,nx,ny;
  char din[10];

  for(;;){
    scanf("%d",&n); if(n<0)break;
    rep(i,x+1) rep(j,y+1) mpx[i][j]=mpy[i][j]=0;
    while(n--){
      scanf("%s%d%d",din,&i,&j); i*=4; j*=4;
      if(din[0]=='x') mpx[i][j]=mpx[i+1][j]=mpx[i+2][j]=mpx[i+3][j]=1;
      if(din[0]=='y') mpy[i][j]=mpy[i][j+1]=mpy[i][j+2]=mpy[i][j+3]=1;
    }
    nx=sx; ny=sy; dx=dy=1;
    for(;;){
      if(mpx[nx][ny]) dy*=-1;
      if(mpy[nx][ny]) dx*=-1;
      if(nx+dx<0||ny+dy<0||nx+dx>x||ny+dy>y) break;
      nx+=dx; ny+=dy;
      if(nx==sx&&ny==sy) break;
    }
    printf("%d %d\n",nx*25,ny*25);
  }

  return 0;
}
