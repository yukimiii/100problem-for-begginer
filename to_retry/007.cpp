#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int sq;
	sq = 0;
	int n;
	cin >> n;
	vector<vector<int>> poll(n, vector<int>(2));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> poll.at(i).at(j);
		}
	}
	REP(i, n)
	{
		FOR(j, i + 1, n)
		{
			int dx = poll[i][0] - poll[j][0];
			int dy = poll[i][1] - poll[j][1];
			if (dx * dx + dy * dy > sq)
			{
				FOR(k, i + 1, n)
				{
					if (poll[k][0] == poll[i][0] + dy && poll[k][1] == poll[i][1] - dx)
					{
						FOR(l, i + 1, n)
						{
							if (poll[l][0] == poll[i][0] + dx - dy && poll[l][1] == poll[i][1] - dx + dy)
							{
								sq = dx * dx + dy * dy;
							}
						}
					}
					if (poll[k][0] == poll[i][0] - dy && poll[k][1] == poll[i][1] + dx)
					{
						FOR(l, i + 1, n)
						{
							if (poll[l][0] == poll[i][0] - dx + dy && poll[l][1] == poll[i][1] + dx - dy)
							{
								sq = dx * dx + dy * dy;
							}
						}
					}
				}
			}
		}
	}
	cout << sq << '\n';
	return (0);
}
