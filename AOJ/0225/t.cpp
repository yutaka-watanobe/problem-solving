#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)



main(){
	int n;
	while(cin>>n,n){
		string ss;
		map<char,map<char,int> > dic;
		map<char,int> sentou,saigo;
		
		rep(i,n){
			cin>>ss;
			dic[ss[0]][ss[ss.size()-1]]++;
			sentou[ss[0]]++;
			saigo[ss[ss.size()-1]]++;
		}
		
		if(sentou!=saigo){
			puts("NG");
			continue;
		}

		char cc=ss[ss.size()-1];
		int roop=0;
		while(true){
			map<char,int>::iterator mcip;
			for(mcip=dic[cc].begin();mcip!=dic[cc].end();mcip++){
				if(mcip->second>0){
					mcip->second--;
					break;
				}
			}
			if(mcip==dic[cc].end()){
				break;
			}
			++roop;
			cc=mcip->first;
		}
		
		
		if(roop==n )cout<<"OK"<<endl;
		else cout<<"NG"<<endl;
	}
}

