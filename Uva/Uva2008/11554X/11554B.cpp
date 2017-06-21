#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cassert>

using namespace std;

/** 多倍長整数の基礎を変更する場合には以下の
 *  ５つの項目を適切に調整すること
 */
typedef int digit;

#define BASE 1000000
#define NDIGIT 4
#define FRONT "%d"
#define FORMAT "%04d"

class BigInteger{
 public:
  /* 初期化は BASE 未満の数で行うこと */
  /* この制約を守る限りは高速な初期化を保証 */
  BigInteger( digit n = 0 ){
    assert( n < BASE);
    digits.assign(1, n);
  }

  BigInteger( vector<digit> &dts){
    digits = dts;
  }

  /* 空文字列を入れないこと。数字は正しいことを保証する */
  /* 符合は処理しない!! */
  BigInteger( string n ){
    assert( !n.empty() );

    /* 桁数を揃える */
    while( n.size() % NDIGIT ){
      n.insert(n.begin(), 1, '0');
      for ( int i = n.size()-NDIGIT; i >= 0; i -= NDIGIT ){
	digits.push_back(atoi(n.substr(i, NDIGIT).c_str()));
      }
    }
  }

  string toString() const {
    string result;
    char buffer[NDIGIT+1];

    /* 先頭に余分な０を付けない */
    sprintf(buffer, FRONT, digits.back()), result = buffer;

    /* NDIGI によって変化刺せたいが、sprintf でフォーマットを */
    /* 作る手間をかけるよりは修正した方が良い */
    for ( int i = digits.size()-2; i >= 0; i--){
      sprintf(buffer, FORMAT, digits[i]), result += buffer;
    }
    return result;
  }

  int size() const{
    return digits.size();
  }
  
  const digit &operator [] (int n) const {
    return digits[n];
  }

  bool operator == ( const BigInteger &O ) const {
    if( size() != O.size() ) return false;
    
    for( int i = 0; i < size(); i++ ){
      if ( digits[i] != O[i] ) return false;
    }
    return true;
  }

  bool operator < ( const BigInteger &O ) const {
    if ( size() < O.size() ) return true;
    if ( size() > O.size() ) return false;

    for( int i = size()-1; i >= 0; i-- ){
      if( digits[i] < O[i] ) return true;
      if( digits[i] > O[i] ) return false;
    }
    return false;
  }

  bool operator > ( const BigInteger &O ) const {
    if( size() > O.size() ) return true;
    if( size() < O.size() ) return false;

    for( int i = size()-1; i >= 0; i--){
      if ( digits[i] > O[i] ) return true;
      if ( digits[i] < O[i] ) return false;
    }
    return false;
  }

  void operator += ( const BigInteger &O ){
    digits.resize(max(size(), O.size()) +1, 0);
    
    for( int i = 0; i < O.size(); i++ ) add(O[i], i, digits);
    regularize();
  }

  void operator -= ( const BigInteger &O){
    assert( size() >= O.size() );

    for(int i = 0;  i < O.size(); i++ ) sub(O[i], i, digits);
    regularize();
  }

  void operator *= ( const BigInteger &O){
    vector<digit> dts;

    dts.resize(size() + O.size() +1, 0);
    for(int i=0; i<size(); i++){
      for(int j=0;  j<O.size(); j++) mul(digits[i] * O[j], i+j, dts);
    }
    digits = dts;
    regularize();
  }

  void operator /= ( const BigInteger &O ){
    BigInteger rem = BigInteger(digits);

    *this = BigInteger(0);
    div(*this, rem, O); /* 余りは rem に格納されている */
  }

  void operator ^= ( int exponent ){
    BigInteger p = *this;
    bitset<32> bits = exponent;
    
    assert(exponent >= 0);
    *this = BigInteger(1);
    for(int i=0; bits.any(); i++){
      if(bits[i]) *this *= p;
      bits[i] = false, p *= p;
    }
  }

 private:

  vector<digit> digits;
  
  void add( digit num, int order, vector<digit> &dts ){
    dts[order] += num;

    for( int i = order; i < dts.size(); i++ ){
      if ( dts[i] < BASE ) break;
      dts[i+1]++;
      dts[i] -= BASE;
    }
  }

  void sub( digit num, int order, vector<digit> &dts ){
    dts[order] -= num;

    for ( int i = order; i < dts.size()-1; i++ ){
      if ( dts[i] >= 0) break;
      dts[i+1]--;
      dts[i] += BASE;
    }
  }

  void mul( digit num, int order, vector<digit> &dts ){
    dts[order] += num;

    for ( int i = order; i < dts.size(); i++ ){
      if ( dts[i] < BASE ) break;
      dts[i+1] += dts[i] / BASE;
      dts[i] %= BASE;
    }
  }
  
  void div( BigInteger &quot, BigInteger &rem, const BigInteger &pow ){
    if ( rem < pow ) return ;

    BigInteger pow2 = pow; pow2.twice();
    div(quot, rem, pow2);

    quot.twice();
    if ( !(pow > rem) ) rem -= pow, quot.increment();
  }

  void twice() {
    digits.push_back(0);
    for ( int i = digits.size()-1; i >= 0; i--) add(digits[i], i, digits);
    regularize();
  }

  void increment(){
    digits.push_back(0);
    add(1, 0, digits);
    regularize();
  }

  void regularize(){
    while ( digits.back() == 0 && digits.size() > 1){
      digits.pop_back();
    }
  }
};

/*
main(){
  BigInteger a, b, c, d;

  a = BigInteger(100);
  b = BigInteger("12345678900000000000000");

  a *= b;

  cout << a.toString() << endl;
  }*/


void compute(int e){
    BigInteger t, tf, s, sf;

    tf = BigInteger(0);

    for ( int i = 4; i <= e; i++ ){
	t = tf;
	t += BigInteger( (i-2)/2 );
	s = sf;
	s += t;
	tf = t;
	sf = s;
    }
    cout << s.toString() << endl;
}

main(){
    /*
    BigInteger t, tf, S[1000001];

    tf = S[3] = BigInteger(0);

    for ( int i = 4; i <= 1000000; i++ ){
	t = tf;
	t += BigInteger( (i-2)/2 );
	S[i] = S[i-1];
	S[i] += t;
	tf = t;
	//	cout << S[i].toString() << endl;
    //	printf("%d %d\n", i, T[i]);
    }*/
    int tcase; scanf("%d", &tcase);
    int n;
    for ( int i = 0; i < tcase; i++ ) {
	scanf("%d", &n);
	compute(n);
	//	cout << S[n].toString() << endl;
    }
}
