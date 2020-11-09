#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int N, M;
	cin >> N >> M;
	ll ans = 0;
	ll sum;
	vector<vector<ll>> score(N, vector<ll>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> score.at(i).at(j);
		}
	}

	REP(j, M - 1)
	{
		FOR(k, j + 1, M)
		{
			sum = 0;
			REP(i, N)
			{
				sum += max(score[i][j], score[i][k]);
			}
			ans = max(sum, ans);
		}
	}
	cout << ans << '\n';
	return (0);
}
