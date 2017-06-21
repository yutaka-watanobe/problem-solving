class Res{
public:
  int a, b, c;

  Res(int a, int b, int c) : a(a), b(b), c(c){
  }
  
};

// x > 0, y > 0 に対し、ax + by = c = gcd(x, y) となるような、a, b, c を求める
//
// 任意の整数 k に対し、an = a0 + y*k, bn = b0 + x*k とすることで、
// 一般の an , bn を求められる。
Res egcd(int x, int y){
  if(y == 0) return Res(1, 0, x);
  Res r = egcd(y, x%y);
  return Res(r.b, r.a - r.b*(x/y), r.c);
}
