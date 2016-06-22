#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int main()
{
	long long f[100000];
	int n, m;
	long long g[100000];
	while (cin >> m >>n)
	{
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		f[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (i < m)
			{
				f[i] = 2 * f[i - 1] % MOD;
				g[i] = 0;
				continue;
			}
			if (i == m)
			{
				f[i] = 2 * f[i - 1] - 1 % MOD;
				g[i] = 1;
				continue;
			}
			f[i] = (2 * f[i - 1] - f[i - m - 1] + MOD) % MOD;
			g[i] = (2 * g[i - 1] + f[i - m - 1] + MOD) % MOD;
		}
		cout << g[n] << endl;
	}

	return 0;
}