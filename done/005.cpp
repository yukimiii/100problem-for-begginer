#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int A, B, C, X, Y, price;
	cin >> A >> B >> C >> X >> Y;
	price = A * X + B * Y;
	REP(i, 2 * max(X, Y))
	{
		price = min(price, max(X - i, 0) * A + max(Y - i, 0) * B + 2 * i * C);
	}
	cout << price << '\n';
	return (0);
}
