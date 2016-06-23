//http://blog.csdn.net/sunnylinner/article/details/51730894

#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1000000007;
typedef long long llong;
const int n = 5;


struct modatrix
{
	llong data[6][6];
}origin, res, tmp, A, ans;

modatrix mul(modatrix x, modatrix y)
{
	int i, j, k;
	memset(tmp.data, 0, sizeof(tmp.data));
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= n; k++)
			{
				tmp.data[i][j] += (x.data[i][k] * y.data[k][j]) % mod;
				tmp.data[i][j] %= mod;
			}
	return tmp;
}



void quickpow(llong k)
{
	int i;
	memset(res.data, 0, sizeof(res.data));
	for (i = 1; i <= n; i++)
		res.data[i][i] = 1;
	while (k)
	{
		if (k & 1)
			res = mul(res, A);
		A = mul(A, A);
		k >>= 1;
	}
}

void check()
{
	return;
}

int main()
{
	llong n;
	
	while (cin >> n) {
		check();
		llong a0, ax, ay, b0, bx, by;
		check();
		cin >> a0 >> ax >> ay;
		check();
		cin >> b0 >> bx >> by; check();

		llong f1, a1, b1, s0; check();
		a1 = (a0*ax + ay) % mod; check();
		b1 = (b0*bx + by) % mod; check();
		f1 = (a1*b1) % mod;
		s0 = 0;
		memset(origin.data, 0, sizeof(origin.data)); check();
		origin.data[1][1] = f1; check();
		origin.data[1][2] = a1; check();
		origin.data[1][3] = b1; check();
		origin.data[1][4] = 1; check();
		origin.data[1][5] = s0; check();
		memset(A.data, 0, sizeof(A.data)); check();
		A.data[1][1] = (ax*bx) % mod; check();
		A.data[1][5] = 1; check();
		A.data[2][1] = (ax*by) % mod; check();
		A.data[2][2] = ax%mod; check(); check();
		A.data[3][1] = (ay*bx) % mod; check();
		A.data[3][3] = bx%mod; check();
		A.data[4][1] = (ay*by) % mod; check();
		A.data[4][2] = ay%mod; check();
		A.data[4][3] = by%mod; check();
		A.data[4][4] = 1; check();
		A.data[5][5] = 1; check();

		quickpow(n); check();
		ans = mul(origin, res); check();
		cout << ans.data[1][5] << endl;
	}
	return 0;
}