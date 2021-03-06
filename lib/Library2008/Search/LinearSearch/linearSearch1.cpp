#include<iostream>
using namespace std;

#define MAX 10000
#define NOT_FOUND (-1)

int linearSearch( int size, int data[], int key ){
    for ( int index = 0; index < size; index++ ){
	if ( data[ index ] == key ) return index;    
    }
    return NOT_FOUND;
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
