#include<string>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

const string ERROR = "ERROR";
const int M = 200;
 

char m[M][M];

bool F(int &y,int &x){
  if (m[y][x] == ' ')return false;
  x++;
  return true;
}

bool B(int &y,int &x){
  if (x == 0 || m[y][x-1] == ' ')return false;
  x--;
  return true;
}

bool P(int &y,int &x){//upward
  if (x == 0){
    if (m[y+1][x] == ' ')return false;
  }else if (m[y+1][x-1]==' ' && m[y+1][x]==' '){
    return false;
  }
  y++;
  return true;
}

bool N(int &y,int &x){//downward
  if (y==0){
    return false;
  }else if (m[y-1][x-1]==' ' && m[y-1][x] == ' '){
    return false;
  }
  y--;
  return true;
}

bool C(int &y,int &x){
  if (m[y][x]   == ' ')return false;
  if (m[y+1][x] != ' ')return false;
  m[y+1][x]=m[y][x];
  y++;
  x++;
  return true;
}

bool fall(int &y,int &x){

  REP(i,1,M){
    for(int j=0;j<M;j++){
      if (m[i][j] == ' ')continue;
      bool moveonce=false;
      bool isfall=false;
      int k=j;
      for(k=j;k<M && m[i][k] != ' ';k++);
      if (j<=x && x<=k && i== y)isfall=true;
      while(i>0){
	bool canmove=true;
	for(int l=j;l < k;l++){
	  if (m[i-1][l] != ' '){canmove=false;}//break;}
	}
	if (canmove){
	  for(int l=j;l<k;l++)swap(m[i][l],m[i-1][l]);
	  //	  if (j <=x && x <= k && i == y){
	  if (isfall){
	    y--;
	  }
	  moveonce=true;
	}else break;
	i--;
      }
      if (moveonce)return true;
      j=k-1;
    }
  }
  return false;
}

bool D(int &y,int x){
  if (m[y][x] == ' ')return false;
  int tx = x;
  while(true){
    m[y][tx]=m[y][tx+1];
    if (m[y][tx]==' ')break;
    tx++;
  }
  
  //if empty
  if (m[y][x] == ' '){
    if (x == 0){//begining of segment
      if (y == 0)return false;//bottom
      if (m[y-1][x] == ' ')return false;//ilegal position
      y--;
    }else if (m[y][x-1] == ' '){//empty
      if (y == 0)return false;//bottom
      if (m[y-1][x-1] == ' ' && m[y-1][x] == ' ')return false;//ilegal position
      y--;
    }
  

  }
  return true;
}

void insert(int y,int &x,char c){
  int tx = x;
  while(true){
    swap(m[y][tx],c);
    if (c == ' ')break;
    tx++;
  }
  x++;
  return;
}

void output(){
  rep(i,10){
    rep(j,10)cout<<m[i][j];
    cout << endl;
  }
}

string solve(string &in){
  int p=0;
  while(p < in.size() && in[p] == ' ')p++;
  if (isupper(in[p]))return ERROR;
  m[0][0]=in[p];
  int y = 0,x=1;
  REP(i,p+1,in.size()){
    switch(in[i]){
    case 'F':
      if (!F(y,x))return ERROR;
      break;
    case 'B':
      if (!B(y,x))return ERROR;
      break;
    case 'P':
      if (!P(y,x))return ERROR;
      break;
    case 'N':
      if (!N(y,x))return ERROR;
      break;
    case 'D':
      if (!D(y,x))return ERROR;
      while(fall(y,x));
      break;
    case 'C':
      if (!C(y,x))return ERROR;
      break;
    case ' ':
      break;
    default:
      insert(y,x,in[i]);
      break;
    }
  }


  string ret ="";
  int beg=x;
  if (m[y][beg]==' ')beg--;
  while(true){
    if (m[y][beg] == ' '){beg++;break;}
    if (beg == 0)break;
    beg--;
  }


  //    cout <<"debug " <<  y << " " << x << endl;
  //  output();
  

  while(true){
    if (m[y][beg] == ' ')break;
    ret+=m[y][beg++];
  }
  return ret;
}

void test(){

  rep(i,M)rep(j,M)m[i][j]=' ';
  m[0][0]=' ';m[0][1]=' ';m[0][2]='a';m[0][3]='a';
  m[1][0]=' ';m[1][1]=' ';m[1][2]='a';
  m[2][0]='c';m[2][1]='c';m[2][2]='c';
  m[3][0]='d';m[3][1]='d';
  int y = 2,x = 0;
  cout << D(y,x) << endl;
  while(fall(y,x));
  cout << y << " " << x << endl;
  output();
  
}

main(){
  int te;
  cin>>te;
  string tmp;getline(cin,tmp);
  while(te--){
    string in;
    //    cin>>in;
    getline(cin,in);
    rep(i,M)rep(j,M)m[i][j]=' ';
    cout << solve(in) << endl;
    //output();
  }
    

  //test();  

  return false;
}
