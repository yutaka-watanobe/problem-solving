#include<iostream>
using namespace std;

#define MAX 10000
#define NOT_FOUND (-1)

int linearSearch( int data[], int size, int key ){
    int index = -1; // data[0]から検索を開始するため
    data[ size ] = key; // 番兵をセットする 

    while ( data[ ++index ] != key ); // 探索する

    if ( index == size ) return NOT_FOUND; // 番兵が機能した場合 
    else return index; // 目的の値を発見した場合 
}

int main(void){
  int size, data[MAX], key;
  
  cin >> size;
  for ( int i = 0; i < size; i++ ) cin >> data[i];
  cin >> key;

  int result = linearSearch(data, size, key);
  if ( result == NOT_FOUND ) cout << "not found. " << endl;
  else cout << result << endl;

  return 0;
}
