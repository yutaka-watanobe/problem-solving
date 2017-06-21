#include<iostream>
#include<algorithm>
using namespace std;

main(){
  int A[3] = {1, 2, 3};

  for ( int i = 0; i < 3; i++ ){

    for ( int j = 0; j < 3; j++ ){
      cout << A[j] << " ";
    }
    cout << endl;
    rotate(A, A+1, A+3);
  }
}
