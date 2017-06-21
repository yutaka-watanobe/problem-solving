#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#define MAX 5001

using namespace std;

typedef long long digit;

#define BASE 10000000000000000LL
#define NDIGIT 16
#define HEAD "%lld"
#define BODY "%016lld"

// NDIGIT * BUF_SIZE 桁の整数を格納できることになる.
// ただし, 計算途中でこの桁数以上の数を想定する可能性が
// ある場合にはもうすこし余裕を持たせて取ること.
#define BUF_SIZE 10


class BigInteger {
public:

	// 0 で初期化.
	BigInteger() {
		reset();
	}

	// BASE 未満の数で整数値を初期化するコンストラクタ.
	// 制限は厳しいが, 文字列による初期化よりははるかに高速に行える.
	BigInteger( digit n ) {
		assert( n < BASE );

		reset();
		digits[0] = n;
	}

	void clear() {
		reset();
	}

	// 加算を行う.  処理時間は結果の桁数に線形比例する.
	void add( const BigInteger &r ) {
		resize(max(size(), r.size()) + 1);

		for ( int i = 0, sz = r.size(); i < sz; i++ ) digits[i] += r[i];
		for ( int i = 0, sz = size(); i < sz; i++ )
			if ( digits[i] >= BASE ) digits[i] -= BASE, ++digits[i+1];
		normalize();
	}

	// 整数値を文字列として返す.  先頭に leading 0 は付けない.
	// 処理時間は桁数に関して線形比例する.  sprintf による数値の文字列化を行うので,
	// 同じ値に対する toString の多用は, 大きな無駄となる.  不変であるならば,
	// 文字列によるキャッシュも考えられる.
	string toString() const {
		char buf[NDIGIT + 1];
		string result;

		sprintf(buf, HEAD, most()), result = buf;
		for ( int i = size() - 2; i >= 0; i-- )
			sprintf(buf, BODY, digits[i]), result += buf;
		return result;
	}

private:

	// resize のみを調整すれば vector でも C 配列でもすぐに
	// 切り替えが可能である.  BigInteger の基盤機能はすべて
	// これ以降に private として揃えること.  ndigit は vector に
	// よる実装の際にも用いる.  vector の size メソッドが遅い
	// ため.

	int ndigit;
	digit digits[BUF_SIZE];

	inline void reset() {
		ndigit = 0, resize(1);
		digits[0] = 0;
	}

	inline void resize( int size ) {
		assert( size < BUF_SIZE );
		if ( size <= ndigit )
			ndigit = size;
		else
			while ( ndigit < size ) digits[ndigit++] = 0;
	}

	inline int size() const {
		return ndigit;
	}

	inline const digit &operator [] ( int n ) const {
		return digits[n];
	}

	inline digit most() const {
		return digits[ndigit - 1];
	}

	inline digit least() const {
		return digits[0];
	}

	inline void normalize() {
		while ( !normalized() ) ndigit--;
	}

	inline bool normalized() {
		return (most() != 0 || ndigit == 1);
	}

};

BigInteger T[MAX + 1];

void init(){
  for ( int i = 0; i < MAX; i++ ){
    T[i].clear();
  }

  T[0] = BigInteger(1);

  for ( int j = 1; j < MAX; j++ ){
    for ( int i = 0; i < MAX; i++ ){
      if ( i + j > MAX ) break;
      T[i + j].add(T[i]);
    }
  }


}

main(){
  int n;

  init();

  while ( scanf("%d", &n) != EOF ){
    cout << T[n].toString() << endl;
  }
}

