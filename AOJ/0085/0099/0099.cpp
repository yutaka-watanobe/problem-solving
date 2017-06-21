#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 1000000
using namespace std;

class P{
public:
  int id, value;
  P(){}
  P(int id, int value):id(id), value(value){}

  bool operator > ( const P &p ) const{
    if ( value == p.value ){
      return id < p.id;
    } else {
      return value > p.value;
    }
  }

};

P A[MAX+1];
int size;
int I[MAX+1]; // index of heap

void downHeap(int i){

  int l, r, largest;
  l = 2*i;
  r = 2*i+1;
  if ( l <= size && A[l] > A[i] ) largest = l;
  else largest = i;

  if ( r <= size && A[r] > A[largest] ) largest = r;

  if ( largest != i ){
    I[A[i].id] = largest;
    I[A[largest].id] = i;
    swap(A[i], A[largest]);
    downHeap(largest);
  }
}

void upHeap(int i){
  while ( i > 1 && A[i] > A[i/2]){
    I[A[i].id] = i/2;
    I[A[i/2].id] = i;
    swap(A[i], A[i/2]);

    i = i/2;
  }
}

main(){
  int id, value;
  int n, q;

  size = MAX;
  for ( int i = 1; i <= MAX; i++ ){
    A[i].value = 0;
    A[i].id = i;
    I[i] = i;
  }

  cin >> n >> q;

  int total = 0;
  for ( int i = 0; i < q; i++ ){
    scanf("%d %d", &id, &value);
    total += value;
    A[I[id]].value += value;
    if ( value > 0 ){
      upHeap(I[id]);
    } else if ( value < 0 ){
      downHeap(I[id]);
    }
    cout << A[1].id << " " << A[1].value << endl;
  }
  
  return 0;
}

