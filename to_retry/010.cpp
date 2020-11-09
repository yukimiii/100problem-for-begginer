#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

vector<int> IntegerToVector(int bit, int N)
{
	vector<int> S;
	for (int i = 0; i < N; ++i)
	{
		if (bit & (1 << i))
		{
			S.push_back(i);
		}
	}
	return S;
}
int main()
{
	int n, q, flag;
	cin >> n;
	vector<int> elm(n);
	REP(i, n)
	{
		cin >> elm[i];
	}
	cin >> q;
	vector<int> num(q);
	REP(i, q)
	{
		cin >> num[i];
	}
	vector<int> sums(pow(2, n));
	for (int bit = 0; bit < (1 << n); ++bit)
	{
		// どれを選ぶか
		vector<int> S = IntegerToVector(bit, n);

		// 部分集合に対応する総和
		int sum = 0;
		for (int i : S)
		{
			sum += elm[i];
		}
		sums[bit] = sum;
	}
	REP(i, q)
	{
		flag = 0;
		REP(j, pow(2, n))
		{
			if (num[i] == sums[j])
			{
				flag = 1;
			}
		}
		if (flag)
			cout << "yes" << '\n';
		else
		{
			cout << "no" << '\n';
		}
	}
	return (0);
}
