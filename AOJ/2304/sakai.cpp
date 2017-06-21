/*

Accepted Program Reused by Judge (admin)
Thanks for Sakai-san.

2012/08/03

Test for checker.

*/

#include<iostream>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
const int N = 300;
const int inf = (1<<20);
int cap[N][N];
int flow[N][N];
bool vis[N];
 
int fordFulkerson(int n,int s,int t,int now,int fl){
  if (now == t)return fl;
  if (vis[now])return 0;
  vis[now]=true;
  int tmp=0;
  rep(i,n){
    int &next=i;
    if (cap[now][i] - flow[now][i] > 0){
      tmp=fordFulkerson(n,s,t,next,min(fl,cap[now][i]-flow[now][i]));
      if (tmp != 0){
    flow[now][next]+=tmp;
    flow[next][now]=-flow[now][next];
    return tmp;
      }
    }
  }
  return 0;
}
 
int maxFlow(int n,int s,int t){
  int tmp=0,ret=0;
  rep(i,n)vis[i]=false;
  while((tmp = fordFulkerson(n,s,t,s,inf)) != 0){
    ret+=tmp;
    rep(i,n)vis[i]=false;
  }
  return ret;
}
 
bool edge[N][N];
int num[N][N];
main(){
  int n,m;
  while(cin>>n>>m){
    rep(i,n)rep(j,n)flow[i][j]=0,cap[i][j]=0,edge[i][j]=false,num[i][j]=-1;
    rep(i,m){
      int a,b;
      cin>>a>>b;
      a--;b--;
      edge[a][b]=true;
      num[a][b]=num[b][a]=i+1;
      cap[a][b]=cap[b][a]=1;
    }
    int s,t;
    cin>>s>>t;
    s--;t--;
    int ans=maxFlow(n,s,t);
    cout << ans << endl;
    int cnt=0;
    rep(i,n)rep(j,n)if (flow[i][j] > 0 && !edge[i][j])cnt++;
    cout << cnt << endl;
    rep(i,n)rep(j,n)if (flow[i][j] > 0 && !edge[i][j])cout << num[i][j] << endl;
  }
}

/*

add comment
add comment
add comment
add commentadd comment

*/
