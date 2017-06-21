#include<iostream>
using namespace std;

#define MAX 10000
#define NOT_FOUND (-1)

int binarySearch( int data[], int size, int key ){
    int mid, left, right;
    left = 0; // 左端
    right = size; // 右端 + 1

    while ( left < right ){
	mid = ( left + right ) / 2; // 真ん中のインデックスを求める
	if ( data[mid] == key ) return mid; // 目的の値を発見
	else if ( key < data[mid] ) right = mid; // 前半部分へ
	else left = mid + 1; // 後半部分へ
    }

    return NOT_FOUND; // 目的の値がなかった
}

int main(void){
  int size, data[MAX], key;
  
  cin >> size;
  for ( int i = 0; i < size; i++ ) cin >> data[i];
  cin >> key;

  int result = binarySearch(data, size, key);
  if ( result == NOT_FOUND ) cout << "not found. " << endl;
  else cout << result << endl;

  return 0;
}
