
#include <stdio.h>
#include <stl.h>

class poly {
 public:
  vector<long long> v;
  
  poly(){}
  poly(long long r){ v.resize(2); v[0] = -r; v[1] = 1; }
  void operator*=(const poly &p) {
    vector<long long> tmp;
    
    tmp = v;
    v.resize(v.size()+p.v.size()-1);
    fill(v.begin(), v.end(), 0);

    for(int i=0; i<p.v.size(); i++){
      for(int j=0; j<tmp.size(); j++){
	v[i+j] += p.v[i]*tmp[j];
      }
    }
  }
};

poly P;

int read();
void work();

main(){
  while(read()){

    work();
  }
}

void work(){
  if(P.v.size()==1){
    cout << "+ 0 = 0" << endl;
    return;
  }
  for(int i=P.v.size()-1; i>=0; i--){
    if(i==P.v.size()-1){
      if(i==1) cout << "x";
      else cout << "x^" << i;
    }
    else {
      if(P.v[i]==0){
	if(i==0) cout << " + 0";
      }
      else {
	if(P.v[i]>0){
	  cout << " + ";
	  if(i==0 || P.v[i]!=1) cout << P.v[i];

	}
	else {
	  cout << " - ";
	  if(i==0 || P.v[i]!=-1) cout << -P.v[i];
	}

	if(i==0);
	else if(i==1) cout << "x";
	else cout << "x^" << i;
      }
    }
  }
  cout << " = 0" << endl;
}

int read(){
  int n;
  poly p;

  cin >> n;
  if(cin.eof()) return 0;

  P.v.resize(1);
  P.v[0] = 1;

  for(int i=0; i<n; i++){
    int r;
    
    cin >> r;

    p = poly(r);
    P *= p;
  }
  return 1;
}
