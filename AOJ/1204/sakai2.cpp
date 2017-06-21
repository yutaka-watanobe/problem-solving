#include<iostream>
using namespace std;
#define N 300
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

int table[5][N];
char res[5][20];
int cnt=0;

bool can_do(int x,int n){
  rep(i,5){
    rep(j,n){
      if ( res[i][j] == '.')continue;
      else if ( table[i][x+j]!= -1)return false;
    }
  }
  return true;
}

void fill_table(int x,int n,int now,bool flag){
  rep(i,5){
    rep(j,n){
      if ( flag == false && res[i][j] =='X')table[i][x+j]=now;
      if (flag == true &&table[i][x+j]==now)table[i][x+j]=-1;
    }
  }
}

int node=0;

void solve(int n,int last,int now){
  node++;
  if ( last+n>=cnt)return;
  if (last+10-now+n>=cnt)return;
  if (now == 10){
    if ( last+n<cnt)cnt=last+n;
    /*
    rep(i,5){
      rep(j,last+1+n){
	if ( table[i][j] == -1)cout << "* ";
	else cout << table[i][j] << " ";
      }
      cout << endl;
    }
    */
    //cnt=last+n;
    return;
  }
  
  int lim=n+1;
  REP(i,1,lim){
    if  (can_do(last+i,n)){
      fill_table(last+i,n,now,false);
      solve(n,last+i,now+1);
      fill_table(last+i,n,now,true);
    }
  }  
}

main(){
  int n;
  while(cin>>n && n){
    fill(&table[0][0],&table[4][N],-1);
    rep(i,5)rep(j,n)cin>>res[i][j];
    // cnt=n*11+1;
    node=0;
    cnt=N;
    solve(n,-1,0);
    cout << cnt<<endl;
  }
  return false;
}
