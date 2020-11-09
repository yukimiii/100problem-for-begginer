#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int dp[1010][1010];
	int n, xlen, ylen;
	string x, y;
	cin >> n;

	REP(i, n)
	{
		cin >> x >> y;
		xlen = x.size();
		ylen = y.size();
		int dp[xlen + 1][ylen + 1];
		REP(i, xlen + 1)
		{
			dp[i][0] = 0;
		}
		REP(i, ylen + 1)
		{
			dp[0][i] = 0;
		}
		REP(i, xlen)
		{
			REP(j, ylen)
			{
				if (x[i] == y[j])
				{
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				else
				{
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
				}
			}
		}
		cout << dp[xlen][ylen] << '\n';
	}
	return (0);
}
