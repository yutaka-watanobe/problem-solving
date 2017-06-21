#include<iostream>
#include<cassert>

using namespace std;

const int MAX_AMOUNT_WATER = 100;
const int paidLastMonth = 4280;
const int numOfPlacement = 4;
const int term[] = {0,10,20,30};
const int payment[] = {0,125,140,160};
const int basePayment = 1150;

main(){
  int num;
  while(cin >> num && num != -1){
    assert( 0 <= num && num <= MAX_AMOUNT_WATER );
    
    int ans = basePayment;

    for(int i = 0;i<numOfPlacement;i++)
      if(term[i] < num){
	int temp = num-term[i];

	if(i+1 != numOfPlacement && num >= term[i+1])
	  ans += (term[i+1] - term[i])*payment[i];
	
	else
	  ans += temp*payment[i];
      }
    cout << paidLastMonth - ans << endl;
  }
  return 0;
}
    
