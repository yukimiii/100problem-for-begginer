#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	REP(i, n)
	{
		int a, skip;
		cin >> skip;
		cin >> a;
		REP(j, a)
		{
			int b;
			cin >> b;
			g[i].push_back(b - 1);
		}
	}

	vector<int> dist(n, -1);
	queue<int> que;
	dist[0] = 0;
	que.push(0);
	// BFS 開始 (キューが空になるまで探索を行う)
	while (!que.empty())
	{
		int v = que.front(); // キューから先頭頂点を取り出す
		que.pop();

		// v から辿れる頂点をすべて調べる
		for (int nv : g[v])
		{
			if (dist[nv] != -1)
				continue; // すでに発見済みの頂点は探索しない

			// 新たな白色頂点 nv について距離情報を更新してキューに追加する
			dist[nv] = dist[v] + 1;
			que.push(nv);
		}
	}
	REP(i, n)
	cout << i + 1 << " " << dist[i] << '\n';
	return (0);
}
