#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

const int N = 100001;
const int M = 20;

double dp[N][M]={0};
double table[M+1];
//double ans[N]={0};

void make_table(){
  table[0]= 1;
  table[1] = 1;
  REP(i,2,M+1){
    table[i]=table[i-1]/2;
  }
  
  dp[1][1]=1;
  REP(i,2,N){
    rep(j,M){
      dp[i][0]+=dp[i-1][j]*(1-table[j+1]);
      if (j)dp[i][j]+=dp[i-1][j-1]*table[j]*j;
    }
  } 

  //  rep(i,100)cout << dp[2][i] << endl;
  
  //  cout << dp[1][1] << " " << dp[2][1] << " " << dp[2][2] << endl;

}

main(){
  int n;
  make_table();
  while(cin>>n && n){
    double ans = 0;
    rep(i,M)ans+=dp[n][i];
    printf("%.5lf\n",ans);
  }
}


