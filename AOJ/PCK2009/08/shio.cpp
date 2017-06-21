#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INFTY (1<<21)

int rosen[101][101];
bool visit[101][11];
int cost[101][11];
int ken,mati,edge,start,goal,a,b,mim,f;
void di(void){
  int now1,now2;
  cost[start][ken]=0;
  while(1){
    mim=INFTY;
    now1=-1;
    now2=-1;
    for(int i=0;i<=100;i++){
      for(int j=0;j<11;j++){
	if(!visit[i][j] && mim>cost[i][j]){
	  mim=cost[i][j];
	  now1=i;
	  now2=j;
	}
      }
    }
    //cout<<now1<<' '<<now2<<' '<<mim<<endl;
    if(now1==-1 && now2==-1)break;
    for(int i=0;i<=100;i++){
      if(!visit[i][now2] && rosen[now1][i]>0){
	cost[i][now2]=min(cost[i][now2],cost[now1][now2]+rosen[now1][i]);
	if(now2>0)cost[i][now2-1]=min(cost[i][now2-1],cost[now1][now2]+rosen[now1][i]/2);
      }
    }
    visit[now1][now2]=true;
  }
  return;
}

main(){
  while(cin>>ken>>mati>>edge>>start>>goal){
    mim=INFTY; 
    if(mati==0)break;
    for(int i=0;i<=100;i++){
      for(int j=0;j<=100;j++){
	rosen[i][j]=0;
      }
      for(int j=0;j<=10;j++){
	cost[i][j]=mim;
	visit[i][j]=false;
      }
    }
    for(int i=0;i<edge;i++){
      cin>>a>>b>>f;
      rosen[a][b]=f;
      rosen[b][a]=f;
    }
    di();
    mim=INFTY;
    for(int i=0;i<11;i++)mim=min(mim,cost[goal][i]);
    cout<<mim<<endl;
  }
}
