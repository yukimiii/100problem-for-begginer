#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, x, count;

	while (1)
	{
		cin >> n >> x;
		if (n == 0 && x == 0)
		{
			break;
		}
		else
		{
			count = 0;
			FOR(a, 1, n)
			{
				FOR(b, a + 1, n)
				{
					FOR(c, b + 1, n + 1)
					if (a + b + c == x)
					{
						// cout << a << " " << b << " " << c << " ";
						count++;
					}
				}
			}
		}
		cout << count << '\n';
	}
	return (0);
}
