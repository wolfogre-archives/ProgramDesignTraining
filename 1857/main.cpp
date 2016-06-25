#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <functional>
using namespace std;

bool useless(vector<int> &input)
{
	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	return true;
}


const int maxN = 105;
const int MOD = 1000007;
int n, s[maxN];

#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef pair<int, int> PII;
typedef priority_queue<int, vector<int>, greater<int> > PQI;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second

#define MOD 10007

typedef struct
{
	int data[4][4];
} M;

M I = { 1,0,0,0,         //单位矩阵 
0,1,0,0,
0,0,1,0,
0,0,0,1 };

M juzhengcheng(M a, M b);
int kuaisumi(M a, int n);

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, y;
		cin >> n >> x >> y;
		x = x%MOD; y = y%MOD;
		M a = { 1,(x*x) % MOD,(y*y) % MOD,(2 * x*y) % MOD,
			0,(x*x) % MOD,(y*y) % MOD,(2 * x*y) % MOD,
			0,1,0,0,
			0,x,0,y };
		cout << kuaisumi(a, n - 1) << endl;
	}
	return 0;
}

M juzhengcheng(M a, M b)
{
	M xres = I;
	REP(i, 4)
	{
		REP(j, 4)
		{
			int tmp = 0;
			REP(k, 4)
				tmp = (tmp + (a.data[i][k] * b.data[k][j]) % MOD) % MOD;
			xres.data[i][j] = tmp;
		}
	}
	return xres;
}


int kuaisumi(M a, int n)    //快速幂 
{
	M xres = I;
	while (n>0)
	{
		if (n & 1)
			xres = juzhengcheng(xres, a);
		a = juzhengcheng(a, a);
		n >>= 1;
	}
	int xans = 0;
	REP(j, 4)
		xans = (xans + xres.data[0][j]) % MOD;   //将最终解结果的第一行相加 
	return xans;
}