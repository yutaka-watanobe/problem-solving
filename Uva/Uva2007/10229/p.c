// @JUDGE_ID:  17051CA  10229  C++
// @begin_of_source_code
/* 数論 Fibonacci */
/* ( a + b )%c = ( a%c + b%c )%c であることを利用 */
/* unsigned の型を利用してもよいが、危険である */

#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>

int p;

class Matrix{
 public:
  /* |a, b| */
  /* |c, d| */
  long long a, b, c, d;
  Matrix(){}
  Matrix(long long a, long long b, long long c, long long d): a(a), b(b), c(c), d(d){}
  Matrix operator+(const Matrix &m)const{
    return Matrix(a+m.a, b+m.b, c+m.c, d+m.d);
  }
  Matrix operator*(const Matrix &m)const{
    return Matrix(a*m.a%p+b*m.c%p, a*m.b%p+b*m.d%p, c*m.a%p+d*m.c%p, c*m.b%p+d*m.d%p);
  }
};

Matrix power(Matrix x, long long n){
  Matrix tmp = Matrix(1, 0, 0, 1);
  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}

int power(int x, int n){
  int tmp = 1;

  if(n>0){
    tmp = power(x, n/2);
    if(n%2==0) tmp = tmp*tmp;
    else tmp = tmp*tmp*x;
  }
  return tmp;
}


int n, m;

int read(){
  cin >> n >> m;
  if(cin.eof()) return false;
  return true;
}

void work(){
  p = power(2, m);
  
  Matrix base = Matrix(1, 1, 1, 0);
  Matrix M = power(base, n);

  int f0 = 0;
  int f1 = 1;

  long long F = f1*M.c%p; /* + f0*M.d%p; */

  cout << F%p << endl;

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
