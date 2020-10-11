#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int N;
	ll sum;
	ll ans = 1000000000000000;
	cin >> N;
	vector<vector<int>> item(N, vector<int>(2));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> item.at(i).at(j);
		}
	}
	REP(i, N)
	{
		sort(item[i].begin(), item[i].end());
	}
	REP(i, N)
	{
		REP(j, N)
		{
			if (item[i][1] - item[j][0] < 0)
			{
				continue;
			}
			sum = 0;
			REP(k, N)
			{
				sum += item[i][1] - item[j][0] + max(0, (item[j][0] - item[k][0]) * 2) + max(0, (item[k][1] - item[i][1]) * 2);
			}
			ans = min(ans, sum);
		}
	}
	cout << ans << '\n';
	return (0);
}
