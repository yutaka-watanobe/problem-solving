#include<iostream>
using namespace std;

#define MAX 10000
#define NOT_FOUND (-1)

int linearSearch( int size, int data[], int key ){
    int index = -1;
    data[ size ] = key;

    while ( data[ ++index ] != key );

    if ( index == size ) return NOT_FOUND;
    else return index;
}

int main(void){
  int size, data[MAX], key;
  
  cin >> size;
  for ( int i = 0; i < size; i++ ) cin >> data[i];
  cin >> key;

  int result = linearSearch(size, data, key);
  if ( result == NOT_FOUND ) cout << "not found. " << endl;
  else cout << result << endl;

  return 0;
}
