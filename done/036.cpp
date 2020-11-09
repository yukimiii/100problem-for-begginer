#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

// コメントアウトしたのは重さ1が大量に来るコーナーケースでタイムアウト
int main()
{
	int N, W;
	cin >> N >> W;
	// int dp[110][10010];
	int v[100];
	int w[100];
	int dp[10100];
	REP(i, N)
	{
		cin >> v[i] >> w[i];
	}
	REP(i, W + 1)
	dp[i] = 0;
	REP(weight, W + 1)
	{
		REP(i, N)
		{
			if (weight >= w[i])
			{
				dp[weight] = max(dp[weight], dp[weight - w[i]] + v[i]);
			}
		}
	}
	// REP(i, W)
	// {
	// 	dp[0][i] = 0;
	// }
	// REP(i, N)
	// {
	// 	REP(weight, W + 1)
	// 	{
	// 		dp[i + 1][weight] == dp[i][weight];
	// 		int count;
	// 		count = 0;
	// 		while (weight >= w[i] * count)
	// 		{
	// 			dp[i + 1][weight] = max(dp[i][weight - w[i] * count] + v[i] * count, dp[i + 1][weight]);
	// 			count++;
	// 		}
	// 	}
	// }
	// cout << dp[N][W] << '\n';
	cout << dp[W] << '\n';
	return (0);
}
