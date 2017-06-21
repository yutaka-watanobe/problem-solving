// @JUDGE_ID:  17051CA  399  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<stl.h>

class Peace{
 public:
  int id, h, w;
  vector<vector<char> > p;
  Peace(){}
  Peace(int a, int b){
    h = a; w = b;
    p.resize(h);
    for(int i=0; i<h; i++){
      p[i].resize(w);
    }
  }
};

class Pix{
 public:
  int id;
  int top, left, right, bot;
  Pix(){}
  Pix(int a, int b, int c, int d, int i){
    top = a;
    left = b;
    bot = c;
    right = d;
    id = i;
  }
};

void split(vector<string> &d, string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){
    if(s[i]==c){
      if(t!=""){ d.push_back(t); t = ""; }
    }
    else t+= s[i];
  }
  if(t.size()) d.push_back(t);
};

void work();
void rec(int i, int j, vector<Pix> plist, vector<vector<Pix> > puzzle);

vector<Pix> plist;
vector<vector<Pix> > goal;
map<int, Peace> pm;
char grid[300][300];

int dim, h, w;

void work(){
  char buff[1000];
  string line;

  cin.getline(buff, 1000);
  line = buff;
  vector<string> com; 
  
  com.clear();
  split(com, line);

  dim = atoi( com[0].c_str() );
  h = atoi( com[1].c_str() );
  w = atoi( com[2].c_str() );

  /* init */
  plist.clear();
  pm.clear();

  for(int i=0; i<dim*dim; i++){
    Peace p = Peace(h, w);
    vector<vector<char> > hv;
    for(int a=0; a<h; a++){
      cin.getline(buff, 1000);
      vector<char> wv;
      for(int b=0; b<w; b++){
	wv.push_back(buff[b]);
      }
      hv.push_back(wv);
    }
    p.p = hv;

    cin.getline(buff, 1000);
    line = buff;
    vector<string> f;
    split(f, line);
    int to, le, rh, bt;
    to = atoi( f[0].c_str());
    le = atoi( f[1].c_str());
    bt = atoi( f[2].c_str());
    rh = atoi( f[3].c_str());
    Pix pix = Pix(to, le, bt, rh, i);
    plist.push_back(pix);
    pm[i] = p;
    cin.getline(buff, 1000);
  }

  vector<vector<Pix> > puz;
  puz.resize(dim);
  for(int i=0; i<dim; i++) puz[i].resize(dim);
  for(int i=0; i<dim; i++){
    for(int j=0; j<dim; j++){
      Pix pi = Pix(-100, -100, -100, -100, 0);
      puz[i][j] = pi;
    }
  }

  rec(0, 0, plist, puz);

  for(int i=0; i<dim; i++){
    for(int j=0; j<dim; j++){
      Pix pp = goal[i][j];
      Peace pe = pm[pp.id];

      int ii = i*h;
      int jj = j*w;
      int x, y;
      x = 0;
      for(int a=ii; a<=ii+h-1; a++){
	y = 0;
	for(int b=jj; b<=jj+w-1; b++){
	  grid[a][b] = pe.p[x][y];
	  y++;
	}
	x++;
      }
    }
  }

  for(int i=0; i< dim*h; i++){
    for(int j=0; j< dim*w; j++){
      cout << grid[i][j];
    }
    cout << endl;
  }

}

void rec(int i, int j, vector<Pix> pl, vector<vector<Pix> > puzz){

  if( pl.size() == 0 ){
    goal = puzz; 
    return ;
  }

  Pix pix, puz, puz1, puz2;
  for(int a=0; a<pl.size(); a++){
    pix = pl[a];

    bool m = false;
    if(i==0){
      if(j==0){
	if(pix.top == 0 && pix.left == 0 ) { m = true; goto next; }
      }else if(j==dim-1){
	if(pix.top == 0 && pix.right == 0 ){ m = true; goto next; }
      }else{
	puz = puzz[i][j-1];
	if(pix.top ==0 && (pix.left+puz.right==0) ) { m = true; goto next; }
      }
    }else if(i==dim-1){
      if(j==0){
	if(pix.bot == 0 && pix.left == 0 )  { m = true; goto next; }
      }else if(j==dim-1){
	if(pix.bot == 0 && pix.right == 0 ) { m = true; goto next; }
      }else{
	puz = puzz[i][j-1];
	if(pix.bot == 0 && (pix.left+puz.right==0) )  { m = true; goto next; }
      }
    }else{
      if(j==0){
	puz = puzz[i-1][j];
	if( pix.left==0 && (pix.top + puz.bot==0) ) { m = true; goto next; }
      }else if(j==dim-1){
	puz = puzz[i-1][j];
	if( pix.right==0 && (pix.top+puz.bot==0) ) { m = true; goto next; }
      }else{
	puz1 = puzz[i-1][j]; puz2 = puzz[i][j-1];
	if((puz1.bot+pix.top==0) && (puz2.right+pix.left==0) ) { m = true; goto next; }
      }
    }
    
  next:;

    if(m){
      vector<Pix> plistT = pl;
      plistT.erase(plistT.begin()+a);
      vector<vector<Pix> > puzzleT = puzz;
      puzzleT[i][j] = pix;
      int pos = i*dim+j;
      pos++;
      rec(pos/dim, pos%dim, plistT, puzzleT);
    }  
  }

}

main(){
  char buff[100];
  int n;
  cin.getline(buff, 100);
  n = atoi( buff );

  for(int i=0; i<n; i++){
    work();
    cout << endl;
  }
}
// @end_of_source_code
