#include<stdio.h>
#include<string>
#include<stl.h>
/* Bignum Data Type */

#define MAXDIGITS       100     /* maximum length bignum */ 
#define PLUS            1       /* positive sign bit */
#define MINUS           -1      /* negative sign bit */


class bignum {
 public:
  char digits[MAXDIGITS]; /* represent the number */
  int signbit;            /* PLUS or MINUS */ 
  int lastdigit;          /* index of high-order digit */

  bignum(){}
  bignum(string s){
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

void initialize_bignum(bignum &a);
int compare_bignum(bignum &a, bignum &b);
void divide_bignum(bignum &a, bignum &b, bignum &c);
void add_bignum(bignum &a, bignum &b, bignum &c);
void subtract_bignum(bignum &a, bignum &b, bignum &c);
void zero_justify(bignum &n);
void multiply_bignum(bignum &a, bignum &b, bignum &c);
void digit_shift(bignum &n, int d);

void initialize_bignum(bignum &a){
  a.init();
}
  
/**
 * Addition 
 * Adding two integers is done from right to left, 
 * with any overflow rippling to the next field as a carry. 
 * Allowing negative numbers turns addition into subtraction. 
 */
void add_bignum(bignum &a, bignum &b, bignum &c){
  int carry;                      /* carry digit */
  int i;                          /* counter */
  
  initialize_bignum(c);
  
  if (a.signbit == b.signbit) c.signbit = a.signbit;
  else {
    if (a.signbit == MINUS) {
      a.signbit = PLUS;
      subtract_bignum(b,a,c);
      a.signbit = MINUS;
    } else {
      b.signbit = PLUS;
      subtract_bignum(a,b,c);
      b.signbit = MINUS;
    }
    return;
  }
  
  c.lastdigit = max(a.lastdigit,b.lastdigit)+1;
  carry = 0;
  
  for (i=0; i<=(c.lastdigit); i++) {
    c.digits[i] = ((carry + (a.digits[i]-'0') + (b.digits[i]-'0'))%10) + '0';
    /* c.digits[i] = (char)((carry + (a.digits[i]) + (b.digits[i]))%10);*/
    carry = (carry + (a.digits[i]-'0') + (b.digits[i]-'0') )/10;
  }
  
  zero_justify(c);
}

/**
 * Manipulating the signbit is a non-trivial headache. 
 * We reduced certain cases to subtraction by negating the numbers 
 * and/or permuting the order of the operators, but 
 * took care to replace the signs first. 
 *
 * The actual addition is quite simple, and made simpler by initializing 
 * all the high-order digits to 0 and treating the final carry over 
 * as a special case of digit addition. 
 * The zero_justify operation adjusts lastdigit to avoid leading zeros. 
 * It is harmless to call after every operation, 
 * particularly as it corrects for : 
 */
void zero_justify(bignum &n){
  while ((n.lastdigit > 0) && (n.digits[ n.lastdigit ]=='0'))
    n.lastdigit--;
  
  if ((n.lastdigit == 0) && (n.digits[0] == '0'))
    n.signbit = PLUS;      /* hack to avoid -0 */
}

/**
 * Subtraction 
 * Subtraction is trickier than addition because it requires borrowing. 
 * To ensure that borrowing terminates, it is best to make sure that the
 *larger-magnitude number is on top. 
 */
void subtract_bignum(bignum &a, bignum &b, bignum &c) {
  int borrow;                     /* anything borrowed? */
  int v;                          /* placeholder digit */
  int i;                          /* counter */
  
  if ((a.signbit == MINUS) || (b.signbit == MINUS)) {
    b.signbit = -1 * b.signbit;
    add_bignum(a,b,c);
    b.signbit = -1 * b.signbit;
    return;
  }
  if (compare_bignum(a,b) == PLUS) {
    subtract_bignum(b,a,c);
    c.signbit = MINUS;
    return;
  }
  c.lastdigit = max(a.lastdigit,b.lastdigit);
  borrow = 0;
  for (i=0; i<=(c.lastdigit); i++) {
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
int compare_bignum(bignum &a, bignum &b){
  int i;                          /* counter */
  
  if ((a.signbit==MINUS) && (b.signbit==PLUS)) return(PLUS);
  if ((a.signbit==PLUS) && (b.signbit==MINUS)) return(MINUS);
  
  if (b.lastdigit > a.lastdigit) return (PLUS * a.signbit);
  if (a.lastdigit > b.lastdigit) return (MINUS * a.signbit);
  
  for (i = a.lastdigit; i>=0; i--) {
    if (a.digits[i] > b.digits[i])
      return(MINUS * a.signbit);
    if (b.digits[i] > a.digits[i])
      return(PLUS * a.signbit);
  }
  
  return(0);
}

/**
 * Multiplication 
 * Multiplication seems like a more advanced operation than 
 * addition or subtraction. A people as sophisticated as the Romans had 
 * a difficult time multiplying, even though their numbers look impressive
 *  on building cornerstones and Super Bowls. 
 * 
 * The Roman's problem was that they did not use a radix (or base) 
 * number system. Certainly multiplication can be viewed as repeated addition
 * and thus solved in that manner, but it will be hopelessly slow. 
 * Squaring 999,999 by repeated addition requires on the order of a million
 * operations, but is easily doable by hand using the row-by-row method we 
 * learned in school: 
 */
void multiply_bignum(bignum &a, bignum &b, bignum &c){
  bignum row;                     /* represent shifted row */
  bignum tmp;                     /* placeholder bignum */
  int i,j;                        /* counters */
  
  initialize_bignum(c);
  
  row = a;
  
  for (i=0; i<=b.lastdigit; i++) {
    for (j=1; j<=b.digits[i]-'0'; j++) {
      add_bignum(c, row, tmp);
      c = tmp;
    }
    digit_shift(row,1);
  }
  
  c.signbit = a.signbit * b.signbit;
  zero_justify(c);
}

/*
Each operation involves shifting the first number one more place to the right and then adding the shifted first number  times to the total,
where  is the appropriate digit of the second number. We might have gotten fancier than using repeated addition, but since the loop cannot
spin more than nine times per digit, any possible time savings will be relatively small. Shifting a radix-number one place to the right is
equivalent to multiplying it by the base of the radix, or 10 for decimal numbers: 

*/
void digit_shift(bignum &n, int d){           /* multiply n by 10^d */
  int i;                          /* counter */
  
  if ((n.lastdigit == 0) && (n.digits[0] == '0')) return;
  
  for (i=n.lastdigit; i>=0; i--)
    n.digits[i+d] = n.digits[i];
  
  for (i=0; i<d; i++) n.digits[i] = '0';
  
  n.lastdigit = n.lastdigit + d;
}

/*
Exponentiation is repeated multiplication, and hence subject to the same performance problems as repeated addition on large numbers. The trick
is to observe that 
so it can be done using only a logarithmic number of multiplications. 

                                                       Division 
Although long division is an operation feared by schoolchildren and computer architects, it too can be handled with a simpler core loop than
might be imagined. 

Division by repeated subtraction is again far too slow to work with large numbers, but the basic repeated loop of shifting the remainder to the
left, including the next digit, and subtracting off instances of the divisor is far easier to program than ``guessing'' each quotient digit as we were
taught in school: 
*/

void divide_bignum(bignum &a, bignum &b, bignum &c){
  bignum row;                     /* represent shifted row */
  bignum tmp;                     /* placeholder bignum */
  int asign, bsign;               /* temporary signs */
  int i,j;                        /* counters */
  
  initialize_bignum(c);
  
  c.signbit = a.signbit * b.signbit;
  
  asign = a.signbit;
  bsign = b.signbit;
  
  a.signbit = PLUS;
  b.signbit = PLUS;
  
  initialize_bignum(row);
  initialize_bignum(tmp);
  
  c.lastdigit = a.lastdigit;
  
  for (i=a.lastdigit; i>=0; i--) {
    digit_shift(row,1);
    row.digits[0] = a.digits[i];
    c.digits[i] = '0';
    while (compare_bignum(row,b) != PLUS) {
      //c.digits[i]++;
      c.digits[i] = (c.digits[i]-'0')+ 1 +'0';
      subtract_bignum(row, b, tmp);
      row = tmp;
    }
  }
  
  zero_justify(c);
  
  a.signbit = asign;
  b.signbit = bsign;
}


main(){
  string s1, s2, s3;
  string com;
  while(1){
    cin >> com >> s1 >> s2;

    bignum a = bignum(s1);
    bignum b = bignum(s2);
    bignum c = bignum(s3);
    
    if(com=="A")  add_bignum(a, b, c);
    else if(com=="M") multiply_bignum(a, b, c);
    else if(com=="D") divide_bignum(a, b, c);
    else if(com=="S") subtract_bignum(a, b, c);
    cout << a.toString() << endl;
    cout << com << endl;
    cout << b.toString() << endl;
    cout << c.toString() << endl;
  }
}
