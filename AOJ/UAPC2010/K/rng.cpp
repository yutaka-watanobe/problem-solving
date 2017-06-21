
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

struct point {double x,y;};
#define PI acos(-1.0)
#define _abs(x) ((x)>0?(x):-(x))
#define eps 1.0E-9

int N;
point O;
point center[110];
double r[110];

double dist(point P, point Q){
	return hypot(P.x - Q.x, P.y - Q.y);
}

bool check(int id, point P){
	int i;
	
	REP(i,N) if(i != id){
		bool flag1 = (dist(O,center[i]) < r[i]);
		bool flag2 = (dist(P,center[i]) < r[i]);
		if(flag1 != flag2) return false;
	}
	
	return true;
}

double normalize(double theta){
	while(theta > 0.0) theta -= 2.0 * PI;
	while(theta < 0.0) theta += 2.0 * PI;
	return theta;
}

double func(void){
	int i,j;
	double ans = 0.0;
	
	REP(i,N){
		int cnt = 0;
		vector <pair <double, int> > v;
		v.push_back(make_pair(0.0,0)); v.push_back(make_pair(2.0*PI,0));
		
		REP(j,N) if(j != i && _abs(r[i]-r[j]) < dist(center[i],center[j]) - eps){
			double tmp = atan2(center[j].y-center[i].y,center[j].x-center[i].x);
			double a = dist(center[i],center[j]), b = r[i], c = r[j];
			double _cos = (a*a + b*b - c*c) / (2*a*b);
			double theta = acos(_cos);
			double t1 = normalize(tmp-theta), t2 = normalize(tmp+theta);
			if(dist(O,center[j]) > r[j]) swap(t1,t2);
			cnt++;
			v.push_back(make_pair(t1,1)); v.push_back(make_pair(t2,-1));
			if(t1 > t2) {v.push_back(make_pair(0.0,1)); v.push_back(make_pair(2.0*PI,-1));}
		}
		
		sort(v.begin(),v.end());
	//	cout << i << endl;
	//	REP(j,v.size()) cout << v[j].first << ' ' << v[j].second << endl;
	//	cout << endl;
		
		int sum = 0;
		double ans2 = 0.0;
		bool flag = true, checked = false;
		REP(j,v.size()-1){
			sum += v[j].second;
			if(sum == cnt) ans2 += (v[j+1].first - v[j].first);
			if(!checked && sum == cnt && v[j+1].first - v[j].first > eps){
				double theta = (v[j].first + v[j+1].first) / 2.0;
				point P = {center[i].x + r[i] * cos(theta), center[i].y + r[i] * sin(theta)};
				if(!check(i,P)) flag = false;
				checked = true;
			}
		}
		
		if(flag) ans += ans2 * r[i];
	}
	
	return ans;
}

int main(void){
	int i;
	double x,y;
	
	O.x = O.y = 0.0;
	
	while(cin >> N){
		if(N == 0) break;
		REP(i,N) cin >> center[i].x >> center[i].y >> r[i];
		cin >> x >> y;
		REP(i,N) {center[i].x -= x; center[i].y -= y;}
		double ans = func();
		printf("%.9f\n",ans);
	}
	
	return 0;
}


