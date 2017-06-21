#include<iostream>
#include<cassert>
#include<map>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

const int MAX_LIM = 10000;
const int MIN_LIM = 1;
const int MAX_PEOPLE = 100;
const int MIN_PEOPLE = 1;
const int MAX_WAIGHT = 100;
const int MIN_WAIGHT = 1;

class People{
public:
  int start;
  int end;
  int waight;
  
  People(int _waight,int _start,int _end){
    start = _start;
    end = _end;
    waight = _waight;
  }

  People(){}

  bool onBridge(int t){
    return start <= t && t < end;
  }
};

main(){
  int lim,n;
  lim = 150;
  while(cin >>  n && n){
    assert(MIN_LIM <= lim && lim <= MAX_LIM);
    assert(MIN_PEOPLE <= n && n <= MAX_PEOPLE);
    
    vector<People> ve;
    set<int> startPoint;

    for(int i = 0;i<n;i++){
      int w,s,e;
      cin >> w >> s >> e;
      ve.push_back(People(w,s,e));
      startPoint.insert(s);
    }

    bool isOK = true;

    for(set<int>::iterator it = startPoint.begin();it != startPoint.end();it++){
      int sum = 0;
      for(int i = 0;i<ve.size();i++)
	if(ve[i].onBridge(*it))
	  sum += ve[i].waight;
      
      if(sum > lim){
	isOK = false;
	break;
      }
    }

    cout << (string)( isOK ? "OK" : "NG") << endl;
  }
  return 0;
}
	
      
