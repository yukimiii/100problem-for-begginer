#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{

	int n;
	cin >> n;
	int num[n];
	ll sum;
	sum = 0;
	REP(i, n)
	{
		cin >> num[i];
	}
	ll dp[110][25] = {};

	dp[0][num[0]] = 1;
	REP(i, n - 1)
	{
		cout << dp[0][2];

		REP(j, 20)
		{
			if (j + num[i + 1] < 21)
			{
				dp[i + 1][j + num[i + 1]] += dp[i][j];
			}
			if (j - num[i + 1] >= 0)
			{
				dp[i + 1][j - num[i + 1]] = dp[i][j];
			}
		}
	}
	// cout << dp[10][0] << '\n';

	REP(i, 20)
	{
		sum += dp[n - 1][i];
	}
	cout << sum << '\n';
	return (0);
}
