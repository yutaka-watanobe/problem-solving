#include<iostream>
#include<string>
using namespace std;

string itost(int in){string a;for(;in!=0;a="0123456789"[in%10]+a,in/=10); return a;
}

string i(int n){return n?i(n/10)+(char)(n%10+'0'):"";}


main(){
  int n;
  cin >> n;
  cout << i(n) << endl;
  cout << itost(n) << endl;
  
}
