#include<stdio.h>
#include<string>
#include<stl.h>
#include<iostream>
#include<algorithm>
/* BigInteger Data Type */
/*
Solved 10494 --> D, R (only positive)


 */

#define MAXDIGITS       1000     /* maximum length bignum */ 
#define PLUS            1       /* positive sign bit */
#define MINUS           -1      /* negative sign bit */

// long型からstringオブジェクトへの変換
string ltoa(long x){
  char a[20];
  sprintf(a, "%ld", x);
  return string(a);
}

class BigInteger {
 public:
  char digits[MAXDIGITS]; /* represent the number */
  int signbit;            /* PLUS or MINUS */ 
  int lastdigit;          /* index of high-order digit */

  BigInteger(){}

  BigInteger(string s){

    fill(digits, digits + MAXDIGITS, '0');
    if(s[0]=='-') {
      signbit = MINUS;
      s.erase(s.begin()+0);
    }
    else signbit = PLUS;
    lastdigit = s.size()-1;
    for(int i=0; i<s.size(); i++){
      digits[i] = s[s.size()-1-i];
    }
  }

  void init(){
    fill(digits, digits + MAXDIGITS, '0');
    signbit = PLUS;
    lastdigit = 0;
  }

  string toString(){
    string s = string(digits, lastdigit+1);
    reverse(s.begin(), s.end());
    if(signbit==MINUS) s = '-' + s;
    return s;
  }
};

int compare(BigInteger &a, BigInteger &b);
void zero_justify(BigInteger &n);
void add(BigInteger &a, BigInteger &b, BigInteger &c);
void subtract(BigInteger &a, BigInteger &b, BigInteger &c);
void multiply(BigInteger &a, BigInteger &b, BigInteger &c);
void divide(BigInteger &a, BigInteger &b, BigInteger &c);
void digit_shift(BigInteger &n, int d);
void factorial(int a, BigInteger &c);
  
/**
 * Addition 
 * Allowing negative numbers turns addition into subtraction. 
 */
void add(BigInteger &a, BigInteger &b, BigInteger &c){
  int carry;                      /* carry digit */
  
  c.init();
  
  if (a.signbit == b.signbit) c.signbit = a.signbit;
  else {
    if (a.signbit == MINUS) {
      a.signbit = PLUS;
      subtract(b,a,c);
      a.signbit = MINUS;
    } else {
      b.signbit = PLUS;
      subtract(a,b,c);
      b.signbit = MINUS;
    }
    return;
  }
  
  c.lastdigit = max(a.lastdigit,b.lastdigit)+1;
  carry = 0;
  
  for (int i=0; i<=(c.lastdigit); i++) {
    c.digits[i] = ((carry + (a.digits[i]-'0') + (b.digits[i]-'0'))%10) + '0';
    carry = (carry + (a.digits[i]-'0') + (b.digits[i]-'0') )/10;
  }
  
  zero_justify(c);
}

/**
 * The zero_justify operation adjusts lastdigit to avoid leading zeros. 
 * It is harmless to call after every operation, 
 */
void zero_justify(BigInteger &n){
  while ((n.lastdigit > 0) && (n.digits[ n.lastdigit ]=='0'))
    n.lastdigit--;
  
  if ((n.lastdigit == 0) && (n.digits[0] == '0'))
    n.signbit = PLUS;      /* hack to avoid -0 */
}

/**
 * Subtraction 
 * Subtraction is trickier than addition because it requires borrowing. 
 * To ensure that borrowing terminates, it is best to make sure that the
 * larger-magnitude number is on top. 
 */
void subtract(BigInteger &a, BigInteger &b, BigInteger &c) {
  int borrow;                     /* anything borrowed? */
  int v;                          /* placeholder digit */

  if ((a.signbit == MINUS) || (b.signbit == MINUS)) {
    b.signbit = -1 * b.signbit;
    add(a,b,c);
    b.signbit = -1 * b.signbit;
    return;
  }
  if (compare(a,b) == PLUS) {
    subtract(b,a,c);
    c.signbit = MINUS;
    return;
  }
  c.lastdigit = max(a.lastdigit,b.lastdigit);
  borrow = 0;
  for (int i=0; i<=(c.lastdigit); i++) {
    v = ((a.digits[i]-'0') - borrow - (b.digits[i]-'0'));
    if (a.digits[i]-'0' > 0)
      borrow = 0;
    if (v < 0) {
      v = v + 10;
      borrow = 1;
    }
    c.digits[i] =  v % 10 + '0';
  }
  zero_justify(c);
}

/**
 * Comparison 
 * Deciding which of two numbers is larger requires a comparison operation. 
 * Comparison proceeds from highest-order digit to the right, starting
 * with the sign bit: 
 */
int compare(BigInteger &a, BigInteger &b){
  if ((a.signbit==MINUS) && (b.signbit==PLUS)) return(PLUS);
  if ((a.signbit==PLUS) && (b.signbit==MINUS)) return(MINUS);
  
  if (b.lastdigit > a.lastdigit) return (PLUS * a.signbit);
  if (a.lastdigit > b.lastdigit) return (MINUS * a.signbit);
  
  for (int i = a.lastdigit; i>=0; i--) {
    if (a.digits[i] > b.digits[i])
      return(MINUS * a.signbit);
    if (b.digits[i] > a.digits[i])
      return(PLUS * a.signbit);
  }
  
  return(0);
}

/**
 * Multiplication 
 */
void multiply(BigInteger &a, BigInteger &b, BigInteger &c){
  BigInteger row;                     /* represent shifted row */
  BigInteger tmp;                     /* placeholder bignum */
  
  c.init();
  
  row = a;
  
  for (int i=0; i<=b.lastdigit; i++) {
    for (int j=1; j<=b.digits[i]-'0'; j++) {
      add(c, row, tmp);
      c = tmp;
    }
    digit_shift(row,1);
  }
  
  c.signbit = a.signbit * b.signbit;
  zero_justify(c);
}


void digit_shift(BigInteger &n, int d){ /* multiply n by 10^d */
  
  if ((n.lastdigit == 0) && (n.digits[0] == '0')) return;
  
  for (int i=n.lastdigit; i>=0; i--)
    n.digits[i+d] = n.digits[i];
  
  for (int i=0; i<d; i++) n.digits[i] = '0';
  
  n.lastdigit = n.lastdigit + d;
}

/**
 * Division 
 */
void divide(BigInteger &a, BigInteger &b, BigInteger &c){
  BigInteger row;                     /* represent shifted row */
  BigInteger tmp;                     /* placeholder bignum */
  int asign, bsign;               /* temporary signs */
  
  c.init();
  
  c.signbit = a.signbit * b.signbit;
  
  asign = a.signbit;
  bsign = b.signbit;
  
  a.signbit = PLUS;
  b.signbit = PLUS;
  
  row.init();
  tmp.init();
  
  c.lastdigit = a.lastdigit;
  
  for (int i=a.lastdigit; i>=0; i--) {
    digit_shift(row,1);
    row.digits[0] = a.digits[i];
    c.digits[i] = '0';
    while (compare(row,b) != PLUS) {
      c.digits[i]++;
      //c.digits[i] = (c.digits[i]-'0')+ 1 +'0';
      subtract(row, b, tmp);
      row = tmp;
    }
  }
  
  zero_justify(c);
  
  a.signbit = asign;
  b.signbit = bsign;
}

/**
 * Remainder
 * a - b*(a/b)
 */
void remainder(BigInteger &a, BigInteger &b, BigInteger &c){
  BigInteger d, m;
  divide(a, b, d);
  multiply(b, d, m);
  subtract(a, m, c);
}

/*
 * Crazy!!! 
 */
void factorial(int x, BigInteger &t){
  BigInteger b = BigInteger("1");
  BigInteger c, k;
  BigInteger a = BigInteger("2");
  BigInteger f = BigInteger("1");
  for(int i=2; i<=x; i++){
    multiply(a, b, c);
    add(a, f, k);
    b = c;
    a = k;
  }
  t = c;
}

main(){
  string s1, s2, s3;
  string com;

  while(1){
    cin >> com >> s1 >> s2;



    BigInteger a = BigInteger(s1);
    BigInteger b = BigInteger(s2);
    BigInteger c = BigInteger(s3);
    
    if(com=="A")  add(a, b, c);
    else if(com=="M") multiply(a, b, c);
    else if(com=="D") divide(a, b, c);
    else if(com=="S") subtract(a, b, c);
    else if(com=="R") remainder(a, b, c);
    else if(com=="F") factorial(atoi(s1.c_str()), c);

    cout << a.toString() << endl;
    cout << com << endl;
    cout << b.toString() << endl;
    cout << c.toString() << endl;
  }
}
