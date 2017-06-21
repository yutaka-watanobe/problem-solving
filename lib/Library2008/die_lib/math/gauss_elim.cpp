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

void gaussElimination(double **m, int row, int col, double x[]){
  if(row == col-1){
    for(int j = 0; j < col-1; ++j){
      int r = pivoting(m, row, j);
      swap(m[j], m[j]+col, m[r], m[r]+col);
      divRow(m[j], m[j]+col, m[j][j]);
      
      for(int i = 0; i < row; ++i)
        if(j != i)
          relax(m[i]+j, m[i]+col, m[j]+j, m[j]+col);
    }
    
    for(int j = col-2; j >= 0; --j){
      x[j] = m[j][col-1];
      for(int jj = col-2; jj > j; --jj)
        x[j] -= m[j][jj] * x[jj+1];
    }
  }
  else{
    cerr << "not supported" << endl;
  }
}

int main(void){
  double **m = new double*[3];
  m[0] = new double[4];
  m[0][0] = 2, m[0][1] = 1, m[0][2] = 1, m[0][3] = 5;
  m[1] = new double[4];
  m[1][0] = 4, m[1][1] = -6, m[1][2] = 0, m[1][3] = -2;
  m[2] = new double[4];
  m[2][0] = -2, m[2][1] = 7, m[2][2] = 2, m[2][3] = 9;

  double x[10];
  gaussElimination(m, 3, 4, x);
  for(int i = 0; i < 3; ++i)
    cout << "x" << i+1 << " : " << x[i] << endl;
  
  return 0;
}
