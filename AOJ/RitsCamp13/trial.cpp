#include<iostream>
using namespace std;
  
int main(){
  int a, b;
  cin >> a >> b;
  double a2 = a;
  double b2 = b;


  double c = a2/b2;
  cout.setf(ios::fixed);
  cout.precision(8);
  cout << a/b << " " << a%b << " " << c << endl;
}



#include<iostream>
#include<deque>
#include<algorithm>
 
using namespace std;
 
bool Check(deque<int>& deq)
{
  int cnt = deq.size();
  for(int i=deq.size()-1;i>=0;i--)
    {
      if(deq[i] != cnt)
    return false;
      cnt--;
    }
  return true;
}
 
bool Do(deque<int>& deq)
{
 
 for(int i=1;i<=10000;i++)
   {
 
     for(int iu=0;iu<deq.size();iu++)
         deq[iu]--;
       
     int next = deq.size();
     deq.erase(remove(deq.begin(),deq.end(),0),deq.end());     
     deq.push_back(next);
 
 
     if(Check(deq))
       {
     cout << i << endl;
     return true;
       }
   }
 return false;
}
 
int main()
{
  int N;
  while(cin >> N,N)
    {
      deque<int> deq;
      for(int i=0;i<N;i++)
    {
      int in;
      cin >> in;
      deq.push_back(in);
    }
 
      if(Check(deq))
    {
      cout << 0 << endl;
      continue;
    }
 
      if(!Do(deq))
    cout << -1 << endl;  
 
    }
  return 0;
}



#include<iostream>
#include<vector>
 
using namespace std;
 
int main()
{
  int n,m;
  cin >> m >> n;
   
  vector<int> per;
  vector<vector<int> > G;
  G.resize(m);
  bool used[m]; 
  per.resize(m);
  for(int i=0;i<m;i++)
    per[i] = 0,used[i] = false;
  for(int i=0;i<n;i++)
    {
      int x,y;
      cin >> x >> y;
     
      x--,y--;
      per[y]++;
      G[x].push_back(y);
    }
  used[1] = true;
   
   
  for(int i=0;i<m;i++)
    {
      for(int j=0;j<m;j++)
    {
      if(used[j])
        continue;
      if(!per[j])
        {
          used[j] = true;
          cout << j+1 << endl;
          for(int k=0;k<G[j].size();k++)
        per[G[j][k]]--;
        }
    }
    }
 
  cout << 2 << endl;
  return 0;
}

