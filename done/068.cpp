#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	int num = n;
	vector<int> factors;

	for (int i = 2; i <= sqrt(n); i++)
	{
		while (n % i == 0)
		{
			factors.push_back(i);
			n /= i;
		}
		if (n == 1)
			break;
	}
	if (n != 1)
		factors.push_back(n);
	cout << num << ":";

	for (int i = 0; i < factors.size(); i++)
	{
		cout << " " << factors[i];
	}
	cout << endl;
	return (0);
}
