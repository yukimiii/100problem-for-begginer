#include <bits/stdc++.h>
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define REP(w, n) FOR(w, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	int count = 0;
	int i;
	REP(j, 1000)
	{
		int tmp = j;
		i = 0;
		while (i < N - 2 && S[i] != '0' + (tmp % 10))
		{
			i++;
		}
		i++;
		tmp /= 10;
		while (i < N - 1 && S[i] != '0' + (tmp % 10))
		{
			i++;
		}
		i++;
		tmp /= 10;
		// cout << tmp << endl;
		while (i < N)
		{

			if (S[i] == '0' + tmp)
			{
				count++;
				break;
			}
			i++;
		}
	}
	cout << count << '\n';
	return (0);
}
