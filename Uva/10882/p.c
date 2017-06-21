#include<iostream>
#include<algorithm>


bool check(int X, int Y, int Z){
  if ( X < 0 || 100 < X ||
       Y < 0 || 100 < Y ||
       Z < 0 || 100 < Z ){
    cout << "The records are faulty." << endl;
    return true;
  }
  /*
  if ( X == 0 && Y > 0 && Z > 0 ||
       X > 0 && Y == 0 && Z > 0 ||
       X > 0 && Y > 0 && Z == 0  ){
    cout << "The records are faulty." << endl;
    return true;
    }*/
  
  return false;
}

void work(){
int X, Y, Z;

  cin >> X >> Y >> Z;

  if ( check(X, Y, Z) ) return;

  int sum = X + Y + Z;

  int minValue = INT_MAX;
  int maxValue = INT_MIN;

  //  int lim = max ( 100-X, max( 100-Y, 100-Z) );
  int lim = min ( 100-X, min( 100-Y, 100-Z) );

  int minXYZ = min( X, min( Y, Z ) );

  for ( int e = 0; e <= lim; e++ ){
    int num = sum + e - 100;
    if ( num % 2 == 0 ){
      int A = num / 2;
      if ( 0 <= A && A <= 100 && minXYZ >= A ){

	if ( minValue > A ) minValue = A;
	if ( maxValue < A ) maxValue = A;
      } 
    }
  }

  if ( minValue == INT_MAX || maxValue == INT_MIN ){
    cout << "The records are faulty." << endl;
  } else {
    cout << "Between " << minValue << " and " << maxValue << " times." << endl;
  }

}


main(){
  int tcase; cin >> tcase;
  for ( int i = 1; i <= tcase; i++ ){
    cout << "Case #" << i << ": ";
    work();
  }
}
