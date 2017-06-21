#include<iostream>
#include<cassert>
#include<string>

using namespace std;

bool canRepresentNumber(double num){
  int temp = (int)(num * 16);

  return (double)(temp / 16.) == num;
}

main(){
  double num;
  while(cin >> num && num > 0.){
    if(canRepresentNumber(num)){
      int temp = (int)(num * 16);
      int ans[12];
      int idx = 0;
      
      while(idx < 12){
	ans[idx++] = temp%2;
	temp /= 2;
      }
	
      if(temp != 0)
	cout << "NA" << endl;
      else{
	for(int i = 0;i<12;i++){
	  cout << ans[11-i]; 
	  if(i == 7)
	    cout << ".";
	}
	cout << endl;
      }
    }
    else
      cout << "NA" << endl;
  }
  return 0;
}
