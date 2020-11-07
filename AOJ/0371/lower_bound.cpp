#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int N = 7;
  int A[] = {1, 1, 2, 2, 2, 3, 3, 5, 6, 8, 8};
  vector<int> V = {1, 1, 2, 2, 2, 3, 3, 5, 6, 8, 8};

  cout << distance(A, lower_bound(A, A + N, 3)) << endl; // 5
  cout << *lower_bound(A, A + N, 3) << endl;             // 3

  cout << distance(V.begin(), lower_bound(V.begin(), V.end(), 3)) << endl; // 5
  cout << *lower_bound(V.begin(), V.end(), 3) << endl;                     // 3

  return 0;
}
