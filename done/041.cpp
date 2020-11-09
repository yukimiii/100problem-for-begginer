#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int d, n;
	cin >> d >> n;
	int temp[d];
	int min[n];
	int hot[n];
	int c[n];
	REP(i, d)
	{
		cin >> temp[i];
	}
	REP(i, n)
	{
		cin >> min[i] >> hot[i] >> c[i];
	}
	// dp[day][cloth]
	int dp[210][210] = {0};
	REP(i, d)
	{
		// j i+1日の服
		REP(j, n)
		if (temp[i + 1] >= min[j] && temp[i + 1] <= hot[j])
		{
			// k i日目日の服
			REP(k, n)
			{
				if (temp[i] >= min[k] && temp[i] <= hot[k])
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + abs(c[j] - c[k]));
			}
		}
	}
	int ans = 0;
	REP(i, n)
	{
		ans = max(dp[d - 1][i], ans);
	}
	cout << ans << '\n';
	return (0);
}
