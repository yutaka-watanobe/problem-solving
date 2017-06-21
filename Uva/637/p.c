// @JUDGE_ID:  17051CA  637  C++
// @begin_of_source_code
/* Calculation */
#include<stdio.h>
#include<iostream>
#include<string>

int n;
int S;

int read(){
  cin >> n;
  if ( n == 0 ) return 0;
  if ( n % 4 == 0 ) S = n / 4;
  else  S = n / 4 + 1;

  return 1;
}

void work(){
  cout << "Printing order for " << n << " pages:" << endl;

  int front1, front2, back1, back2;

  for ( int s = 1; s <= S; s++ ){
    back2 = (S*2) + (S-s)*2 + 1; 
    front2 = s*2 - 1; 
    back1 = front2 + 1;
    front1 = back2 + 1;

    if ( !(front1 >n && front2 > n )){
      cout << "Sheet " << s << ", front: ";
      if(front1 > n ) cout << "Blank";
      else cout << front1 ;
      cout << ", ";
      if (front2 > n ) cout <<  "Blank";
      else cout << front2 ;
      cout << endl;
    }

    if ( !(back1 > n && back2 > n )) {
      cout << "Sheet " << s << ", back : ";
      if(back1 > n ) cout << "Blank";
      else cout << back1 ;
      cout << ", ";
      if(back2 > n ) cout <<  "Blank";
      else cout << back2 ;
      cout << endl;
    }

  }

}

main(){
  while ( read() ) work();
}
// @end_of_source_code
