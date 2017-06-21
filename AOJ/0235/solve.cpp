#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

const int MAX_SIZE = 20;
bool visited[MAX_SIZE];
int sadj[MAX_SIZE][MAX_SIZE];
int adj[MAX_SIZE][MAX_SIZE];
int table[MAX_SIZE][1 << MAX_SIZE];
int n;

void makeEdge(int s,int nn,int cost){
  visited[nn] = true;
  adj[s][nn] = min(cost,adj[s][nn]);
  
  for(int i = 0;i<n;i++)
    if(visited[i] == false && sadj[nn][i] != 1 << 30)
      makeEdge(s,i,cost+sadj[nn][i]);
} 

main(){
    while(cin >> n && n){
    bool canIgnore[n];
    
    for(int i = 0;i<n;i++)
      for(int j = 0;j<n;j++)
	adj[i][j] = sadj[i][j] = 1 << 30;
    
    for(int i = 0;i<n-1;i++){
      int a,b,w;
      cin >> a >> b >> w;
      a--;b--;
      
      sadj[a][b] = sadj[b][a] = w;
    }
    
    canIgnore[0] = false;
    for(int i = 1;i<n;i++){
      canIgnore[i] = false;
      int sum = 0;
      for(int j = 0;j<n;j++)
	sum += (int)(sadj[i][j] != (int)(1 << 30));
      
      if(sum == 1){
	canIgnore[i] = true;
      }
    }
    
    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++)
	visited[j] = false;
      makeEdge(i,i,0);
    }

    /*
    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++)
	cout << adj[i][j] << " ";
      cout << endl;
    }
    */

    for(int i = 0;i<n;i++)
      for(int j = 0;j<(int)(1 << n);j++)
	table[i][j] = 1 << 30;
    
    table[0][1] = 0;
    for(int k = 1;k<(int)(1 << n);k++)
      for(int i = 0;i<n;i++)
	if((int)(k & (int)(1 << i)) != 0 && canIgnore[i] == false)
	  for(int j = 0;j<n;j++){
	    if(i != j && adj[i][j] != -1 && (int)(k & (1 << j)) == 0 && canIgnore[j] == false){
	      //cout << "k = " << k << ", i = " << i << ",j = " << j << endl;
	      //cout << "table[j][k + (1 << j)] = " << table[j][k + (1 << j)] << ", adj[i][j] + table[i][k] = " << adj[i][j] + table[i][k] << endl;
	      table[j][k + (1 << j)] = min(table[j][k + (1 << j)],adj[i][j] + table[i][k]);
	    }
	  }
    
    int ans = 1 << 30,pos = 0;
    
    for(int i = 0;i<n;i++)
      if(canIgnore[i] == false)
	pos += 1 << i;

    //cout << "pos = " << pos << endl;

    for(int i = 0;i<n;i++)
      if(canIgnore[i] == false){
	ans = min(ans,table[i][pos]);
      }
    cout << ans << endl;
  }
  return 0;
}
    
