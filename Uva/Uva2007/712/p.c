// @JUDGE_ID:  17051CA  712  C++
// @begin_of_source_code
/* Tree operation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<math.h>

int depth(int x){
  int e = 0;
  while(1){
    if(x==0) return e-1;
    x = x/2;
    e++;
  }
}


int n, m, size, fsize;
vector<int> tree;
vector<int> func;
vector<int> f;
map<int, int> index;

int read(){
  cin >> n;
  if(n==0) return 0;
  
  tree.clear();
  func.clear();

  char c;
  int f;
  for(int i=0; i<n; i++){
    cin >> c >> f;
    func.push_back(f-1);
  }


  size = (int)pow(2, n+1);
  fsize = (int)pow(2, n);

  tree.resize(size);

  tree[0] = -1;
  for(int i=1; i<fsize; i++){
    tree[i] = func[depth(i)];
  }

  string str;
  cin >> str;
  int j = 0;
  for(int i=fsize; i<size; i++){
    if(str[j]=='1') tree[i] = 1;
    else tree[i] = 0;
    j++;
  }

  /* for(int i=0; i<tree.size(); i++) cout << tree[i] << " ";
  cout << endl;*/
  return 1;
}

void parse(){
  int index = 1;
  for(int i=0; i<n; i++){
    if(f[tree[index]]) index = index*2+1;
    else index = index*2;
  }

  cout << tree[index];
}

void work(){

  int m;
  string str;
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> str;
    f.clear();
    for(int j=0; j<n; j++){
      if(str[j]=='1') f.push_back(1);
      else f.push_back(0);
    }
    parse();
  }
  cout << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "S-Tree #" << i << ":" << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
