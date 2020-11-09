#include <bits/stdc++.h>
#define FOR(i, a, n) for (i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int count = 0;
	int ans = 0;
	string s;
	int i = 0;

	cin >> s;
	while (s[i])
	{
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
		{
			count++;
		}
		else
		{
			ans = max(ans, count);
			count = 0;
		}
		i++;
	}
	ans = max(ans, count);
	cout << ans << '\n';
	return (0);
}
