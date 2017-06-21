#include<iostream>
#include<algorithm>
#include<cassert>

using namespace std;

const int MAX_SIZE = 1000;
const int MIN_SIZE = 1;
const int MAX_PRICE = 10000;
const int MIN_PRICE = 1;

main(){
  int n,m;

  while(cin >> n >> m && n){
    int price[n];

    assert(MIN_SIZE <= n && n <= MAX_SIZE);
    assert(MIN_SIZE <= m && m <= MAX_SIZE);

    for(int i = 0;i<n;i++){
      cin >> price[i];
      
      assert(MIN_PRICE <= price[i] && price[i] <= MAX_PRICE);
    }

    sort(price,price+n,greater<int>());
    
    int sum = 0;
    for(int i = 0;i<n;i++)
      if((i+1)%m != 0) 
	sum += price[i];
    
    cout << sum << endl;
  }

  return 0;
}
