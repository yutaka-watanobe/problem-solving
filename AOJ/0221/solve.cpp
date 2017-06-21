#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<cassert>

using namespace std;

const int MIN_PLAYER = 2;
const int MAX_PLAYER = 1000;
const int MIN_REMARK = 1;
const int MAX_REMARK = 10000;
const int MIN_LENGTH = 1;
const int MAX_LENGTH = 10;

string toString(int num){
  string re;

  if(num == 0)
    return "0";

  while(num != 0){
    re += (char)(num%10+'0');
    num /= 10;
  }
  reverse(re.begin(),re.end());
  return re;
}

bool isAcceptableString(int num,string str){
  if(num % 3 == 0 && num % 5 == 0){
    return str == "FizzBuzz";
  }
  else if(num % 3 == 0){
    return str == "Fizz";
  }
  else if(num % 5 == 0){
    return str == "Buzz";
  }
  else{
    return toString(num) == str;
  }
  return false;
}

main(){
  int m,n;
  while(cin >> m >> n && m){
    list<int> player;

    assert(MIN_PLAYER <= m && m <= MAX_PLAYER);
    assert(MIN_REMARK <= n && n <= MAX_REMARK);

    for(int i = 0;i<m;i++)
      player.push_back(i+1);

    list<int>::iterator it = player.begin();
    int winner;
    for(int i = 1;i<=n;i++){
      string str;
      cin >> str;
      assert(MIN_LENGTH <= str.size() && str.size() <= MAX_LENGTH);

      assert(player.size() != 0);
      if(!isAcceptableString(i,str)){
	winner = *it;
	list<int>::iterator temp = it;
	temp--;
	player.erase(it);
	it = temp;
      }
      it++;
      if(it == player.end())
	it = player.begin();
    }
    
    if(player.size() != 0){
      for(it = player.begin();it != player.end();it++){
	if(it != player.begin())
	  cout << " ";
	cout << *it;
      }
    }
    else
      cout << winner;
    cout << endl;
  }
  return 0;
}
