// @JUDGE_ID:  17051CA  713  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<stl.h>

void reversedSum( string str1, string str2 ){
  int len = max( str1.size(), str2.size() ) + 1;

  while ( str1.size() < len) str1 += '0';
  while ( str2.size() < len) str2 += '0';

  string ans;
  ans.resize( len+1, '0' );

  int carry = 0;
  int sum = 0;
  int a, b;

  for ( int i = 0; i < len ; i++ ){
    a = str1[i] - '0';
    b = str2[i] - '0';
    sum = a + b + carry;
    ans[i] = ( sum % 10 ) + '0';
    carry = sum / 10;
  }

  while ( 1 ){
    if ( ans.size() && ans[ ans.size() - 1 ] == '0' ){
      ans.erase( ans.begin() + ans.size() -1 );
    } else break;
  }

  if ( ans.size() == 1 && ans[0] == '0' ) {
    cout << "0" << endl;
    return;
  }

  while ( 1 ){
    if ( ans.size() > 1 && *(ans.begin()) == '0' ) ans.erase( ans.begin() + 0);
    else break;
  }
  cout << ans << endl;


}

main(){
  int tcase;
  cin >> tcase;
  string str1, str2;
  for ( int i = 0; i < tcase; i++ ){
    cin >> str1 >> str2;
    //    reverse( str1.begin(), str1.end() );
    //    reverse( str2.begin(), str2.end() );
    reversedSum( str1, str2 );
  }
}
// @end_of_source_code
