#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;
// 何故か3つ目のテストが答えより10小さい
int main()
{
	int r, c;
	cin >> r >> c;
	vector<vector<int>> status(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> status.at(i).at(j);
		}
	}
	int ans = 0;
	int sum;
	int omote;
	// 全パターンの
	for (int bit = 0; bit < (1 << r); bit++)
	{
		sum = 0;
		//各パターンのフラグ建てる処理
		for (int i = 0; i < r; i++)
		{
			if (bit & (1 << i)) //
			{
				// フラグ立っているものへの処理書く　例   和はsum+=a[i]
				REP(j, c)
				{
					status[i][j] = 1 - status[i][j];
				}
			}
		}
		REP(j, c)
		{
			omote = 0;
			REP(i, r)
			{
				omote += status[i][j];
			}
			sum += max(omote, r - omote);
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;

	return (0);
}
