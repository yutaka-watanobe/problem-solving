#include<iostream>
#include<cassert>

using namespace std;

const int MAX_N = 10000;
const int MIN_N = 2;
const int MAX_P = 10000;
const int MIN_P = 1;
const int MAX_DISTANCE = 5000;
const int MIN_DISTANCE = 0;

main(){
  int n;
  while(cin >> n && n){
    assert(MIN_N <= n && n <= MAX_N);

    int id,maxDistance = MIN_DISTANCE-1;
    for(int i = 0;i<n;i++){
      int p,d1,d2;
      cin >> p >> d1 >> d2;
      assert(MIN_P <= p && p <= MAX_P);
      assert(MIN_DISTANCE <= d1 && d1 <= MAX_DISTANCE);
      assert(MIN_DISTANCE <= d2 && d2 <= MAX_DISTANCE);

      if(d1+d2 > maxDistance){
	maxDistance = d1+d2;
	id = p;
      }
    }

    cout << id << " " << maxDistance << endl;
  }
  return 0;
}
