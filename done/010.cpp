#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, q;
	cin >> n;
	int nums[n];
	REP(i, n)
	{
		cin >> nums[i];
	}
	cin >> q;
	int m[q];
	REP(i, q)
	{
		cin >> m[i];
	}
	set<int> sums;
	// tleだから苦し紛れに1から⇐結局無理で一旦和をsetに入れてそこから探すことに
	for (int bit = 1; bit < (1 << n); ++bit)
	{
		// 部分集合に対応する総和
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (bit & (1 << i))
				sum += nums[i];
		}
		sums.insert(sum);
	}
	REP(i, q)
	{

		if (sums.count(m[i]))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return (0);
}
