#include<stdio.h>
#include<iostream>

/**
 * Solved 10229
 */
class Matrix{
 public:
  /* |a, b| */
  /* |c, d| */
  int a, b, c, d;
  Matrix(){}
  Matrix(int a, int b, int c, int d): a(a), b(b), c(c), d(d){}
  Matrix operator+(const Matrix &m)const{
    return Matrix(a+m.a, b+m.b, c+m.c, d+m.d);
  }
  Matrix operator*(const Matrix &m)const{
    return Matrix(a*m.a+b*m.c, a*m.b+b*m.d, c*m.a+d*m.c, c*m.b+d*m.d);
  }
};

/**
 * Solved 10229
 */
Matrix power(Matrix x, int n){
  Matrix tmp = Matrix(1, 0, 0, 1);
  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

main(){
  Matrix M;
  Matrix m = Matrix(1, 1, 1, 0);


  int n;
  cin >> n;
  M = power(m, n);

  cout << M.a << " " << M.b << " " << M.c << " " << M.d << endl;
  
}
