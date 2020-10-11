#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int m, n;
	cin >> m;
	int dx, dy, count;

	vector<vector<int>> member(m, vector<int>(2));
	REP(i, m)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> member[i][j];
		}
	}
	// cout << member[1][1];
	cin >> n;
	vector<vector<int>> star(n, vector<int>(2));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> star[i][j];
		}
	}
	REP(i, n)
	{
		dx = star[i][0] - member[0][0];
		dy = star[i][1] - member[0][1];
		count = 1;
		REP(k, n)
		{
			if (member[count][0] + dx == star[k][0] && member[count][1] + dy == star[k][1])
			{
				count++;
				k = 0;
			}
			if (count == m)
			{
				cout << dx << " " << dy << '\n';
				return (0);
			}
		}
	}
	cout << dx << " " << dy << '\n';
	return (0);
}
