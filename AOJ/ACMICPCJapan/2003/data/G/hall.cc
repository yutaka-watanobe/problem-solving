#include <vector>
#include <iostream>

using namespace std;

class Req{
public:
	int start, end, price;

	bool operator<(const Req& r)const{
		return end < r.end;
	}
};

int ans[366][366];

void init(){
	for(int i=0;i<=365;i++){
		for(int j=0;j<=365;j++){
			ans[i][j] = -1;
		}
	}
}

vector<Req> read(){
	int n;
	cin >> n;
	vector<Req> ret;
	for(int i=0;i<n;i++){
		Req r;
		cin >> r.start >> r.end >> r.price;
		ret.push_back(r);
	}
	return ret;
}

int get_ans(int x, int y){
	if(x > y){
		int tmp = x; x = y; y = tmp;
	}

	if(x < 0)return 0;
	return ans[x][y];
}

void set_ans(int x, int y, int n){
	if(x > y) 
		ans[y][x] = n;
	else
		ans[x][y] = n;
}

void fill(int from, int to){
	for(int d=from;d<=to;d++){
		for(int j=0;j<=d;j++){
			int m = max(get_ans(j-1,d), get_ans(j,d-1));
			set_ans(j,d,m);
		}
	}
}

int solve(vector<Req>& req){
	init();
	
	sort(req.begin(), req.end());
	int last_e = 0;
	for(int i=0;i<req.size();i++){
		int e = req[i].end;
		int s = req[i].start;
		int p = req[i].price;

		if(last_e < e)
			fill(last_e+1, e);
		for(int d=e;d>=0;d--){
			int new_ans = get_ans(d, s-1) + p;
			int cur_ans = get_ans(d, e);
				
			if( new_ans > cur_ans )
				set_ans(d, e, new_ans);
		}
		last_e = e;
	}
	return get_ans(last_e, last_e);
}

int main(){
	while(true){
		vector<Req> reqs;
		reqs = read();
		if( reqs.size() == 0 )break;
		cout << solve(reqs) << endl;
	}
}
