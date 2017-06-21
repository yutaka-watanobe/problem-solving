#include<iostream>

using namespace std;

class NegativeDecimal{
public:
  int num;
  int out[32];
  int outSize;

  void compute(){
    trance();
    output();
  }

  void trance(){
    int c = 0;
    int rank = 1;
    
    outSize = 0;
    while(true){
      int temp = num%10;
      
      num /= 10;
      
      if( (temp < 0 && rank > 0) ||
	  (temp > 0 && rank < 0) ){
	out[outSize++] = 10-abs(temp);
	c++;
      }
      else{
	out[outSize++] = abs(temp);
      }
      
      if(rank < 0)
	num += c;
      else
	num -= c;
      c = 0;
      rank *= -10;
      if(num == 0)
	break;
    }
  }
  
  int abs(int nm){
    if(nm < 0)
      return -nm;
    else
      return nm;
  }

  void output(){
    for(int i = outSize-1;i >= 0;i--)
      cout << out[i];
    cout << endl;
  }
};

int main(){
  NegativeDecimal nd;
  while(1){
    cin >> nd.num;
    if ( nd.num == 0 ) break;
    nd.compute();
  }
  return 0;
}
    
