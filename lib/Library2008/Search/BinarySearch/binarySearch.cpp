#include<iostream>
using namespace std;

#define MAX 10000
#define NOT_FOUND (-1)

int binarySearch( int size, int data[], int key ){
    int mid, left, right;
    left = 0;
    right = size;

    while ( left < right ){
	mid = ( left + right ) / 2;
	if ( data[mid] == key ) return mid;
	else if ( key < data[mid] ) right = mid;
	else left = mid + 1;
    }

    return NOT_FOUND;
}

int main(void){
  int size, data[MAX], key;
  
  cin >> size;
  for ( int i = 0; i < size; i++ ) cin >> data[i];
  cin >> key;

  int result = binarySearch(size, data, key);
  if ( result == NOT_FOUND ) cout << "not found. " << endl;
  else cout << result << endl;

  return 0;
}
