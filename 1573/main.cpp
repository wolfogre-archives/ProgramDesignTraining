#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
typedef long long llong;

int array1[1024], array2[1024];
int number1, number2;

int check()
{
	//He he
	return 0;
}

void init_gcd(int n) {
	number1 = 0;
	check();
	for (int i = 1; i <= sqrt(n); ++i) {
		if ((n % i) == 0) {
			check();
			array1[number1++] = i;
			check();
			array1[number1++] = n / i;
			check();
			if (n / i == i)
				number1--;
		}
	}
	sort(array1, array1 + number1);
	check();
	number2 = n;
	check();
	for (int i = number1 - 1; i >= 0; --i) {
		check();
		array2[i] = n / array1[i];
		check();
		for (int j = number1 - 1; j > i; --j) {
			check();
			if (array1[j] % array1[i] == 0)
				array2[i] -= array2[j];
			check();
		}
		number2 -= array2[i];
		check();
	}
}

llong test(llong m, int gcd) {
	llong sum = 1;
	check();
	while (gcd) {
		if (gcd % 2 == 1)
			sum = (sum * m) % MOD;
		check();
		m = (m * m) % MOD;
		check();
		gcd >>= 1;
		check();
	}
	sum = sum % MOD;
	check();
	return sum;
}

int main()
{
	int t, n;
	check();
	llong s, m;
	check();
	cin >> t;
	check();
	while (t--) {
		cin >> n >> m;
		check();
		if (n == 1) {
			cout << m << endl;
			check();
			continue;
		}
		s = 0;
		check();
		number2 = 1;
		check();
		memset(array1, 0, sizeof(array1));
		check();
		memset(array2, 0, sizeof(array2));
		check();
		init_gcd(n);
		check();
		for (int i = 0; i < number1; ++i) {
			s = (s + array2[i] * test(m, array1[i])) % MOD;
			check();
		}
		s = (s + m * (number2)) % MOD;
		check();
		s = s % MOD;
		check();
		cout << s << endl;
	}
	return 0;
}