#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

const int N = 4005*2;


struct Edge
{
	int src, dst;
	int cost;
	char prev;
	Edge(int s, int d, int c, int p)
		: src(s), dst(d), cost(c), prev(p)
	{}
	bool operator<(const Edge &e) const {
		return cost > e.cost;
	}
};

char initial[N];
vector<Edge> edge;

const int UNCONNECTED = -1;

int dijkstra(const int n)
{
	const int s = 0;
	const int t = 1;
	int cost[N]['z'-'a'+1];
	bool used[N];
	fill(&cost[0][0], &cost[N-1]['z'-'a'+1], INT_MAX);

	priority_queue<Edge> que;

	for (int i=0; i < edge.size(); ++i) {
		if (edge[i].src == s) {
			Edge e = edge[i];
			e.prev = initial[i];
			que.push(e);
		}
	}
	fill(cost[s], cost[s]+'z'-'a'+1, 0);

	while (!que.empty()) {
		Edge now = que.top();
		que.pop();

		if (cost[now.dst][now.prev-'a'] < now.cost) continue;
		cost[now.dst][now.prev-'a'] = now.cost;

		if (now.dst==t) {
			return now.cost;
		}
		for (int i=0; i < edge.size(); ++i) {
			if (edge[i].src != now.dst) continue;
			if (initial[i] == now.prev) continue;
			used[i] = true;
			Edge next = edge[i];
			next.cost += now.cost;
			next.prev = initial[i];
			que.push(next);
		}
	}

	return -1;
}

int main()
{
	int n;
	while (cin>>n && n)
	{
		edge.clear();
		

		string s, t;
		cin >> s >> t;

		map<string, int> table;
		int tableLen = 0;
		table[s] = tableLen++;
		table[t] = tableLen++;

		for (int i=0; i < n; ++i) {
			string a, b, c;
			cin >> a >> b >> c;

			if (table.find(a)==table.end()) { table[a] = tableLen++; }
			if (table.find(b)==table.end()) { table[b] = tableLen++; }

			const int noA = table[a];
			const int noB = table[b];
			edge.push_back(Edge(noA, noB, c.length(), '\0'));
			edge.push_back(Edge(noB, noA, c.length(), '\0'));
			initial[i*2] = c[0];
			initial[i*2+1] = c[0];
		}

		const int ans = dijkstra(tableLen);
		if (ans==-1) {
			cout << "impossivel" << endl;
		}
		else {
			cout << ans << endl;
		}
	}

	return 0;
}


