// divsion

#include<stdio.h>
#include<string>

#include<vector>

int N;
bool used[10];
vector<int> ans;

bool check( int value ){
  bool visited[10];
  for ( int i = 0; i < 10; i++ ) visited[i] = false;

  for ( int i = 0; i < 10; i++ ){
    if ( used[i] ) visited[i] = true;
  }

  char a[20];
  
  sprintf(a, "%d", value);

  string str =  string(a);
  if ( str.size() <= 3 ) return false;
  if ( str.size() == 4 ) str = '0' + str;
  for ( int i = 0; i < str.size(); i++ ){
    int index = str[i] - '0';
    if ( visited[index] ) return false;
    visited[index] = true;
  }

  //  cout << "div " << value << endl;
  return true;
}

void recursive( int p, int value ){
  if ( p == 0 ) {
    if ( value % N == 0 && check( value / N ) ) ans.push_back(value);
    return;
  }

  for ( int i = 0; i < 10; i++ ){
    if ( used[i] ) continue;

    value += i * p;
    used[i] = true;
    recursive( p / 10, value ) ;
    used[i] = false;
    value -= i * p;

  }

}

void work(){
  ans.clear();
  for (int i = 0; i < 10; i++ ) used[i] = false;

  recursive( 10000, 0 );

  if ( ans.size() == 0 ){
    printf("There are no solutions for %d.\n", N);
    return;
  } 

  for ( int i = 0; i < ans.size(); i++ ){
    int denominator, numerator;
    denominator = ans[i];
    numerator = denominator / N;

    if ( denominator < 10000 ) printf("0");
    printf("%d / ", ans[i]);
    if ( numerator < 10000 ) printf("0");
    printf("%d = %d\n", numerator, N) ;
  }





}

bool read(){
  scanf("%d", &N);
  if ( N == 0 ) return false;
  return true;
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) printf("\n");
    work();
  }
}
