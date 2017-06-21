#include<iostream>
using namespace std;

int A[4], B[4], numberOfHit, numberOfBlow;

void compute(){
  numberOfHit = numberOfBlow = 0;
  bool hasA[10];
  for ( int i = 0; i <= 9; i++ ) hasA[i] = false;

  for ( int i = 0; i < 4; i++ ){
    if ( A[i] == B[i] ) numberOfHit++;
    hasA[ A[i] ] = true;
  }

  for ( int i = 0; i < 4; i++ ){
    if ( hasA[ B[i] ] && A[i] != B[i] ) numberOfBlow++;
  }

  cout << numberOfHit << " " << numberOfBlow << endl;
}

main(){
  while ( cin >> A[0] >> A[1] >> A[2] >> A[3] ){
    cin >> B[0] >> B[1] >> B[2] >> B[3];
    compute();
  }
}
