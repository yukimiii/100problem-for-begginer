#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
// 入力例2が合わない
int main()
{
	int n, k;
	cin >> n >> k;
	// 決まってる日、種類
	map<int, int> pasta;
	ll dp[110][4] = {};

	REP(i, k)
	{
		int key, value;
		cin >> key >> value;
		pasta[key] = value;
	}
	if (pasta.count(1))
	{
		dp[1][pasta.at(1)] = 1;
	}
	else
	{
		dp[1][1] = 1;
		dp[1][2] = 1;
		dp[1][3] = 1;
	}
	FOR(i, 1, n)
	{
		FOR(j, 1, 4)
		{
			if (pasta.count(i + 1))
			{
				dp[i + 1][pasta.at(i + 1)] += dp[i][j];
			}
			else
			{
				dp[i + 1][3] += dp[i][j];
				dp[i + 1][1] += dp[i][j];
				dp[i + 1][2] += dp[i][j];
			}
		}
		if (i + 1 >= 3)
		{
			FOR(j, 1, 4)
			{
				if (dp[i + 1][j] && dp[i][j] && dp[i - 1][j])
				{
					dp[i + 1][j] =(dp[i+1][j]- dp[i - 1][j])%10000;
				}
			}
		}
	}
	ll ans = 0;
	FOR(i, 1, 4)
	{
		ans += dp[n][i];
	}
	cout << dp[4][1] << dp[4][2] << dp[4][3] << endl;
	cout << ans % 10000 << '\n';
	return (0);
}
