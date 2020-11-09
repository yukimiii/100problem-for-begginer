#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> price(m);
	REP(i, m)
	{
		cin >> price[i];
	}
	int dp[n + 1];
	REP(i, n + 1)
	{
		dp[i] = 10000;
	}
	dp[0] = 0;
	dp[1] = 1;
	REP(i, n)
	{
		REP(j, m)
		{
			int tmp;
			if (price[j] <= i + 1)
				tmp = min(dp[i] + 1, dp[i + 1 - price[j]] + 1);
			dp[i + 1] = min(dp[i + 1], tmp);
		}
	}
	cout << dp[n] << '\n';

	return (0);
}
