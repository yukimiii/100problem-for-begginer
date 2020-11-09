#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<char>> table(h, vector<char>(w));
	int cheese_x[10];
	int cheese_y[10];
	int ans = 0;
	int dist[1000][1000] = {10000000};
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;
			table.at(i).at(j) = c;
			if (c == 'S')
			{
				cheese_x[0] = j;
				cheese_y[0] = i;
			}
			if (c >= '1' && c <= '9')
			{
				cheese_x[c - '0'] = j;
				cheese_y[c - '0'] = i;
			}
		}
	}
	queue<pair<int, int>> que;
	REP(k, n)
	{
		REP(i, h)
		{
			REP(j, w)
			{
				dist[i][j] = 10000000;
			}
		}
		dist[cheese_y[k]][cheese_x[k]] = 0;
		que.push(pair<int, int>(cheese_y[k], cheese_x[k]));
		while (que.size())
		{
			pair<int, int> coordinate = que.front();
			que.pop();
			// // 探索はゴール見つかるまで
			// if (gy == coordinate.first && gx == coordinate.second)
			// {
			// 	break;
			// }

			REP(i, 4)
			{
				int nx = coordinate.second + dx[i];
				int ny = coordinate.first + dy[i];
				// 地図の外、行けないところ、すでに行ってるならなし
				if (nx >= w || nx < 0 || ny >= h || ny < 0 || table[ny][nx] == 'X' || dist[ny][nx] != 10000000)
					continue;
				// 問題なければキューに入れて距離をdistに入れる
				que.push(pair<int, int>(ny, nx));
				dist[ny][nx] = dist[coordinate.first][coordinate.second] + 1;
			}
		}
		ans += dist[cheese_y[k + 1]][cheese_x[k + 1]];
		// cout << ans << '\n';
	}
	cout << ans << '\n';
	return (0);
}
