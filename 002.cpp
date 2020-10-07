#include <bits/stdc++.h>
#define FOR(i, a, n) for (i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int count_div(int n)
{
	vector<int> x(n + 1);
	int num = n;
	int ans = 1;

	for (int i = 2; i <= n; i++)
	{
		while (num % i == 0)
		{
			x.at(i)++;
			num /= i;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		ans *= x.at(i) + 1;
	}
	return ans;
}
int main()
{
	int N;
	int count = 0;
	cin >> N;
	N -= (N + 1) % 2;
	while (N > 0)
	{
		if (count_div(N) == 8)
		{
			count++;
		}
		N -= 2;
	}
	cout << count << '\n';
	return (0);
}
