#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, W;
	cin >> n >> W;
	int v[n];
	int w[n];
	vector<vector<int>> dp(110, vector<int>(10010));
	REP(i, n)
	{
		cin >> v[i] >> w[i];
	}
	for (int w = 0; w <= W; ++w)
		dp[0][w] = 0;
	REP(i, n)
	{
		REP(weight, W + 1)
		{
			if (weight < w[i])
				dp[i + 1][weight] = dp[i][weight];
			else
				dp[i + 1][weight] = max(dp[i][weight], dp[i][weight - w[i]] + v[i]);
		}
	}
	cout << dp[n][W] << '\n';
	return (0);
}
