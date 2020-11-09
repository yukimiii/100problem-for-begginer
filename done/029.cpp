#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
	int r, c, sy, sx, gy, gx;
	cin >> r >> c >> sy >> sx >> gy >> gx;
	vector<vector<char>> map(r, vector<char>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map.at(i).at(j);
		}
	}
	sy--;
	sx--;
	gy--;
	gx--;
	// 発見したら移動距離にする
	int dist[50][50] = {10000000};

	pair<int, int> coordinate;
	queue<pair<int, int>> que;
	REP(i, r)
	{
		REP(j, c)
		{
			dist[i][j] = 10000000;
		}
	}
	dist[sy][sx] = 0;
	que.push(pair<int, int>(sy, sx));
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
			if (nx >= c || nx < 0 || ny >= r || ny < 0 || map[ny][nx] == '#' || dist[ny][nx] != 10000000)
				continue;
			// 問題なければキューに入れて距離をdistに入れる
			que.push(pair<int, int>(ny, nx));
			dist[ny][nx] = dist[coordinate.first][coordinate.second] + 1;
		}
	}
	cout << dist[gy][gx] << endl;

	return (0);
}
