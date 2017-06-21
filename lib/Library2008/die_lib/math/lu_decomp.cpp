#include <iostream>
#include <cmath>

using namespace std;

int pivoting(double **m, int row, int j){
  int ret = j;
  for(int i = j+1; i < row; ++i)
    if(fabs(m[ret][j]) < fabs(m[i][j]))
      ret = i;
  return ret;
}

void divRow(double *a, double *ae, double d){
  while(a < ae)
    *(a++) /= d;
}

void swap(double *a, double *ae, double *b, double *be){
  if(ae-a == be-b)
    while(a < ae)
      swap(*(a++), *(b++));
  else
    cerr << "error" << endl;
}

void relax(double *f, double *fe, double *t, double *te){
  if(fe-f == te-t){
    double mul = *f / *t;
    while(f < fe)
      *(f++) -= *(t++) * mul;
  }
  else
    cerr << "error" << endl;
}

void doLittle(double **u, int row, int col, double **l){
  if(row == col){
    for(int i = 0; i < row; ++i){
      fill(l[i], l[i]+col, 0);
      l[i][i] = 1;
    }
    
    for(int j = 0; j < row; ++j){
      int r = pivoting(u, row, j);
      swap(u[j], u[j]+col, u[r], u[r]+col);

      for(int i = j+1; i < row; ++i){
l[i][j] = u[i][j] / u[j][j];
          relax(u[i]+j, u[i]+col, u[j]+j, u[j]+col);
      }
    }
  }
  else
    cerr << "not supported" << endl;
}

int main(void){
  double **m = new double*[3];
  m[0] = new double[3];
  m[0][0] = 2, m[0][1] = 5, m[0][2] = 4;
  m[1] = new double[3];
  m[1][0] = 1, m[1][1] = 4, m[1][2] = 3;
  m[2] = new double[3];
  m[2][0] = 1, m[2][1] = -3, m[2][2] = -2;

  double **l = new double*[3];
  l[0] = new double[3];
  l[1] = new double[3];
  l[2] = new double[3];
  
  doLittle(m, 3, 3, l);

  cout  << "L -- " << endl;
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j)
      cout<< l[i][j] << ' ';
    cout << endl;
  }
  
  cout  << "U -- " << endl;
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j)
      cout<< m[i][j] << ' ';
    cout << endl;
  }
  
  return 0;
}
