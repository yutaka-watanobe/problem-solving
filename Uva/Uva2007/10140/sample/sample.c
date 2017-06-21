#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class PrimeFactor {

  vector<int> prime_table;
  
  vector<int> primes;

public:

  // エラトステネスの篩によって素数を求める
  // 素数の上限が与えられる
  void Sieve( int upper ) {

    prime_table.assign(upper+1, false);

    for ( int i = 3; i <= upper; i += 2 )
      prime_table[i] = true;
    prime_table[2] = true;

    const int lim = (int)sqrt(upper);
    for ( int i = 3; i <= lim; i += 2 ) {
      if ( !prime_table[i] )
        continue;
      for ( int j = i*i, k = i*2; j <= upper; j += k )
        prime_table[j] = false;
    }

  }

  // 上の篩の拡張版
  // 素数の上限と下限が与えられる
  void Sieve( int lower, int upper, vector<int> &primes ) {

    int begin;
    int geta = lower;

    prime_table.assign(upper-lower+1, true);

    // 注意: ここでは lower は 2 以上でなければならない。
    // そのために lower が 2 より小さい場合 lower を 2 にする。
    if ( lower == 0 ) {
      prime_table[0] = false;
      prime_table[1] = false;
      lower = 2;
    }
    if ( lower == 1 ) {
      prime_table[0] = false;
      lower = 2;
    }

    // 素数で篩をかける
    const int lim = (int)sqrt(upper);
    for ( int i = 0; i < primes.size() && primes[i] <= lim; i++ ) {
      // 素数が lower より小さければ
      // begin を lower 以上の primes[i] の最小の倍数にする
      /*if ( primes[i] < lower )
	begin = primes[i] * ((lower+primes[i]-1) / primes[i]) - geta;*/
      if ( primes[i] < lower ) {
	begin = (lower%primes[i] == 0) ? lower - geta : primes[i] * (lower / primes[i]) + primes[i] - geta;
      }
      // 素数が lower 以上なら 素数の 2乗から篩えばよい。
      else
	begin = primes[i] * primes[i] - geta;
      for ( int j = begin; j < prime_table.size(); j += primes[i] )
	prime_table[j] = false;
    }
  
  }


  // n が 素数かどうか判定する
  bool isPrime( int n ) {

    if ( n < prime_table.size() )
      return prime_table[n];
      
    for ( int i = 2; i < prime_table.size(); i++ ) {
      if ( !prime_table[i] )
        continue;
      if ( !(n % i) )
        return false;
    }

    return true;

  }

  void make_primes( int upper, vector<int> &primes ) {

    Sieve(upper);

    primes.push_back(2);

    for ( int i = 3; i < prime_table.size(); i += 2 ) {
      if ( prime_table[i] == false )
	continue;
      primes.push_back(i);
    }

  }
  
  void prime_distance( int geta ) {
    
    int begin = -1;
    int min = INT_MAX, max = -1;
    int min_dist_begin = -1, min_dist_end = -1;
    int max_dist_begin = -1, max_dist_end = -1;

    for ( int i = 0; i < prime_table.size(); i++ ) {
      if ( prime_table[i] ) {
	begin = i;
	break;
      }
    }
    
    if ( begin < 0 ) {
      cout << "There are no adjacent primes." << endl;
      return;
    }

    for ( int i = begin+1; i < prime_table.size(); i++ ) {
      if ( !prime_table[i] )
	continue;
      if ( min > (i-begin) ) {
	min = i - begin;
	min_dist_begin = begin + geta;
	min_dist_end = i + geta;
      }
      if ( max < (i-begin) ) {
	max = i - begin;
	max_dist_begin = begin + geta;
	max_dist_end = i + geta;
      }
      begin = i;
    }

    if ( max < 0 ) {
      cout << "There are no adjacent primes." << endl;
      return;
    }

    cout << min_dist_begin << ',' << min_dist_end << " are closest, "
	 << max_dist_begin << ',' << max_dist_end << " are most distant.\n";

  }

  void unit_test( int geta ) {

    for ( int i = 0; i < prime_table.size(); i++ ) {
      if ( prime_table[i] )
	cout << i + geta << endl;
    }

  }

};

class TPrimeDistance {

  int lower, upper;

  vector<int> primes;

  PrimeFactor pf;

public:

  TPrimeDistance() {

    pf.make_primes((int)sqrt(INT_MAX), primes);

    /*for ( int i = 0; i < primes.size(); i++ )
      cout << primes[i] << endl;*/

  }

  bool input() {

    if ( !(cin >> lower >> upper) )
      return false;

    return true;

  }

  void work() {

    if ( lower != upper )
      pf.Sieve(lower, upper, primes);

  }

  void output() {

    if ( lower == upper )
      cout << "There are no adjacent primes." << endl;
    else {
      pf.prime_distance(lower);
      //pf.unit_test(lower);
    }
    
  }

};


int main()
{

  TPrimeDistance Tpd;

  while ( Tpd.input() ) {
    Tpd.work();
    Tpd.output();
  }

  return 0;

}
