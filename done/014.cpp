#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	REP(i, n)
	{
		cin >> a[i];
	}
	ll ans = 100000000000;
	int cnt;
	int pre;
	ll tmp;
	for (int bit = 0; bit < (1 << n); bit++)
	{
		pre = 0;
		cnt = 0;
		tmp = 0;
		for (int i = 0; i < n; i++)
		{
			if (i > 0)
				pre = max(pre, a[i - 1]);
			if (bit & (1 << i)) //
			{
				// フラグ立っているものへの処理書く　例   和はsum+=a[i]
				if (a[i] <= pre)
				{
					tmp += pre + 1 - a[i];
					pre = pre + 1;
				}

				cnt++;
			}
			if (cnt == k)
			{
				// cout << tmp << " " << pre << endl;
				if (ans > tmp)
					ans = tmp;
				// break;
			}
		}
	}
	cout << ans << endl;
	return (0);
}
