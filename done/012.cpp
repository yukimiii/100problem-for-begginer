#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, m;
	cin >> n >> m;
	int size;
	size = 0;
	vector<vector<int>> relation(n, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		relation[x][y] = 1;
	}
	for (int bit = 0; bit < (1 << n; bit++)
	{
	}

	return (0);
}
