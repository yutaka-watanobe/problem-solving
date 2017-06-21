// @JUDGE_ID:  17051CA  356  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>


int n;
double r;
double poi[155][155];

int read(){
  cin >> n;
  if(cin.eof()) return 0;
  return 1;
}

int check(int i, int j){
  int x, y;
  int cnt = 0;
  x = i+1; y = j;
  if( poi[x][y] <= r ) cnt++;
  x = i; y = j+1;
  if( poi[x][y] <= r ) cnt++;
  x = i+1; y = j+1;
  if( poi[x][y] <= r ) cnt++;
  x = i; y = j;
  if( poi[x][y] <= r ) cnt++;
  return cnt;
}

void work(){
  r = (2*n-1)/2.0;

  int seg = 0;
  int com = 0;

  int k;

  for(int i=0; i<n+1; i++){
    for(int j=0; j<n+1; j++){
      poi[i][j] = sqrt(i*i+j*j);
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      k = check(i, j);
      if(k==4) com++;
      else if(0 < k && k < 4 ) seg++;
    }
  }
  
  com *= 4;
  seg *= 4;

  cout << "In the case n = " << n << ", " << seg << " cells contain segments of the circle." << endl;
  cout << "There are " << com << " cells completely contained in the circle." << endl;



}

main(){
  for(int i=0; read(); i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
