// @JUDGE_ID:  17051CA  104  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>
#include<vector>

int read();
void work();
void initM();
void arbit(int, int, double, vector<int> );
int contain(vector<int>, int);
void setR(vector<int>, double);

int N;
double mat[30][30];
vector<int> path;
vector<int> result;
double _ratio;

int read(){
  if( scanf("%d", &N ) == EOF ) return 0;
  else return 1;
}

void initM(){
  double x;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( i == j ){
	mat[i][j] = 1;
      }else{
	cin >> x;
	mat[i][j] = x;
      }
    }
  }
}

void work(){
  initM();
  /*
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << mat[i][j] << "   ";
    }
    cout << endl;
  }*/

  for(int i=0; i<N; i++){
    vector<int> v;
    v.push_back(i+1);
    arbit(i, i, 1, v) ;
  }
  
}

void arbit(int start, int current, double r, vector<int> v ){
  
  for(int j=0; j<N; j++){
    if( j != current ){
      if( j == start ){
	double r1 = r;
	r1 = r1*mat[current][j];
	vector<int> v1 = v;
	v1.push_back(j+1);
	setR(v1, r1);

	for(int a = 0; a<v1.size();a++){
	  cout << v1[a] << " ";
	} 
	cout << "  ratio " << r1 << endl;

      }else{
	if( contain(v, j) == 0){
	  vector<int> v1 = v;
	  double r1 = r;
	  r1 = r1*mat[current][j];
	  v1.push_back(j+1);
	  arbit(start, j, r1, v1);
	}
      }
    }
  }

}

void setR(vector<int> v, double r){
  if( r/100 < 0.01 ) return;
  
  if( result.size() == 0 ){
    result = v; 
  }else if( result.size() > v.size()){
    result = v;
  }

}

int contain(vector<int> v, int j){
  for(int i=0; i<v.size(); i++){
    if( v[i] == j+1 ) return 1;
  }
  return 0;
}

main(){

  while(read()){
    result.clear();
    work();
    /*result*/
    if( result.size() == 0 ){
      cout << "no arbitrage sequence exists" << endl;
    }else{
      for(int i=0; i<result.size(); i++){
	if( i!=0 ) cout << " ";
	cout << result[i];
      }
      cout << endl;
    }
  }
}
// @end_of_source_code
