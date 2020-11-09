#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

// int 型を vector 型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えているか
int main()
{
	int N, M, k;
	cin >> N >> M;
	vector<vector<int>> swi(M);
	REP(i, M)
	{
		cin >> k;
		REP(j, k)
		{
			int a;
			cin >> a;
			a--;
			swi[i].push_back(a);
		}
	}
	vector<int> light(M);
	REP(i, M)
	{
		cin >> light[i];
	}

	int count = 0;
	for (int bit = 0; bit < (1 << N); ++bit)
	{
		bool ok = true;
		// どれを選ぶか
		for (int i = 0; i < M; i++)
		{
			int con = 0;
			for (auto v : swi[i])
			{
				if (bit & (1 << v))
					con++;
			}
			if (con % 2 != light[i])
				ok = false;
		}
		if (ok)
			count++;
	}
	cout << count << '\n';
	return (0);
}
