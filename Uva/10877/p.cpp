// 無理やりすぎるので、回天のとこ書き換えすること

#include<stdio.h>
#include<iostream>
#include<set>


using namespace std;

class Dice{
public:
  int content[6];

  Dice(){}
  
  bool operator == ( const Dice &d ) const{
    for ( int i = 0; i < 6; i++ ){
      if ( content[i] != d.content[i] ) return false;
    }
    return true;
  }

  void rotate(){
    int tmp;
    tmp = content[1];
    content[1] = content[4];
    content[4] = content[5];
    content[5] = content[2];
    content[2] = tmp;
  }

  void left(){
    int tmp;
    tmp = content[0];
    content[0] = content[2];
    content[2] = content[3];
    content[3] = content[4];
    content[4] = tmp;
  }

  void front(){
    int tmp;
    tmp = content[0];
    content[0] = content[1];
    content[1] = content[3];
    content[3] = content[5];
    content[5] = tmp;
  }

};

int n;
int size;
Dice current;
Dice S[1001];

bool issame( Dice d1, Dice d2){
  for ( int i = 0; i < 6; i++ ){
    if ( d1.content[i] != d2.content[i] ) return false;
  }
  return true;
}

bool isSame(Dice target, Dice source){

  Dice target1 = target;
  Dice target2 = target;
  Dice target3 = target;

  target2.left();
  target3.front();

  for ( int i = 0;i < 4; i++  ){
    for ( int j = 0; j < 4; j++ ){
      for ( int k = 0; k < 4; k++ ){
	if ( issame(target, source) ) return true;
	target.rotate();
      }
      target.left();
    }
    target.front();
  }
  /*
  for ( int i = 0; i < 4; i++ ){
    if ( issame(target1, source)  ) return true;
    target1.rotate();
  }

  for ( int i = 0; i < 4; i++ ){
    if (issame(target2, source) ) return true;
    target2.rotate();
  }

  for ( int i = 0; i < 4; i++ ){
    if (issame(target3, source) ) return true;
    target3.rotate();
  }
  */
  return false;
}



void compute(){
  
  for ( int i = 0; i < size; i++ ){
    Dice target = S[i];
    if ( isSame( target, current )  ) return;
  }
  
  //  cout << "ok" << endl;
  S[size] = current;
  size++;
}

void work(){
  size = 0;
  for ( int j = 0; j < 6; j++ ){
    scanf("%d", &current.content[j]);
  }

  S[size] = current;
  
  size++;

  for ( int i = 1; i < n; i++ ){
    for ( int j = 0; j < 6; j++ ){
      scanf("%d", &current.content[j]);
    }
    compute();
  }

  printf("%d\n", size);
}

bool read(){
  scanf("%d", &n);
  if ( n == 0 ) return false;
  return true;
}

main(){
  while ( read() ) work();
}
