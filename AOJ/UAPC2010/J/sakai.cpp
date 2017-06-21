#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end();

typedef long long ll;

ll gcd(ll a,ll b){
  return b==0?a:gcd(b,a%b);
};


ll lcm(ll w,ll m){
  ll g = gcd(w,m);
  return (w/g)*m;
}

ll ans;

ll table[10000][10000];

void solve(int n,int now,bool flag,ll *num,ll me,ll op,ll L){
  if (n == now){
    if (!flag){
      solve(n,0,true,num,me,op,L);
      return;
    }
    //    cout << me << " "<< op << " " <<  L << endl;
    if (me <= op && lcm(me,op) == L)ans++;
    return;
  }


  rep(i,num[now]+1){
    if (!flag){
      solve(n,now+1,flag,num,me*table[now][i],op,L);
    }
    else solve(n,now+1,flag,num,me,op*table[now][i],L);
  }
}


int f(ll in,ll *val,ll *num){
  int p = 0;
  ll tmp = in;
  for(ll i=2;i*i <= tmp;i++){
    if (tmp % i == 0){
      ll cnt = 0;
      while(true){
	if (tmp/i == 0 || tmp%i != 0)break;
	tmp/=i;
	cnt++;
      }
      num[p]=cnt;
      val[p]=i;
      p++;
    }
  }

  if (tmp != 1){
    num[p]=1;
    val[p]=tmp;
    p++;
  }

  rep(i,p){
    tmp = 1;
    rep(j,num[i]+1){
      table[i][j]=tmp;
      tmp*=val[i];
    }
  }

  return p;
}


main(){
  ll n;
  ll val[10000],num[10000];
  while(cin>>n && n){
    int index = f(n,val,num);
    ans = 0;
    solve(index,0,false,num,1,1,n);
    cout << ans << endl;
  }
  return false;
}
