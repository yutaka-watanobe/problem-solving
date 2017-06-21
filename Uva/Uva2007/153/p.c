// @JUDGE_ID:  17051CA  153  C++
// @begin_of_source_code
/* Permutaion Number */
/* 0.021 sec  may be not so good */
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<stl.h>

/*
 * 最大公約数 (Greatest Common Divisor)
 * a > b > 0 を保証すること。
 * 要件: なし
 */
int gcd(int a, int b){
  int tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    
    tmp = a;
    a = b;
    b = tmp;
  }

  return a;
}

string line;

int read(){
  cin >> line;
  if ( line == "#" ) return false;
  return true;
}

int permutaion( int n, vector<int> v ){
  if ( n == 0 ) return 1;

  int sum = 1;

  vector<int> denominator, numerator;
  
  for ( int i = 2; i <= n; i++ ) denominator.push_back( i );
  for ( int i = 0; i < v.size(); i++ ){
    for ( int j = 2; j <= v[i]; j++ ){
      numerator.push_back( j );
    }
  }

  for ( int i = 0; i < denominator.size(); i++ ){
    for ( int j = 0; j < numerator.size(); j++ ){
      int g = gcd( denominator[i], numerator[j] );
      denominator[i] /= g;
      numerator[j] /= g;
    }
  }

  int den, num;
  den = num = 1;
  for ( int i = 0; i < denominator.size(); i++ ) den *= denominator[i];
  for ( int i = 0; i < numerator.size(); i++ ) num *= numerator[i];

  return den/num;
}

void work(){
  int sum = 0;
  vector<char> V;
  set<char> C;
  vector<int> number;
  vector<int> counter;

  number.resize( 26, -1 );
  counter.resize( 26 , 0 );

  for ( int i = 0; i < line.size(); i++ ) C.insert( line[i] );

  V.resize( C.size() );
  copy ( C.begin(), C.end(), V.begin() );

  for ( int i = 0; i < V.size(); i++ ){
    number[ V[i] - 'a' ] = i;
  }

  for ( int s = 0; s < line.size(); s++ ){
    string str = line.substr( s );
    string str2 = str;

    fill ( counter.begin(), counter.end(), 0 );
    
    for ( int i = 0; i < str.size(); i++ ){
      counter[ str[i] - 'a' ]++;
    }

    sort ( str2.begin(), str2.end() );

    int i;
    for ( i = 0; str2[i] != str[0]; ){
      counter[ str2[i] - 'a' ]--;
      sum += permutaion( str.size() -1, counter );
      counter[ str2[i] - 'a' ]++;
      for ( char ch2 = str2[i]; ch2 == str2[i]; i++ );
    }
  }

  printf("%10d\n", sum + 1 );
}

main(){
  while ( read() ) work();
}

// @end_of_source_code
