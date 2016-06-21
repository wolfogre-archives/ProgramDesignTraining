#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	if (a < 0)
		return gcd(-a, b);
	if (b < 0)
		return gcd(a, -b);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return abs(a * b / gcd(a, b));
}

int main()
{
	int a, b;
	int count = 0;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
		{
			cout << "Case " << ++count << ":" << endl
				<< "no GCD" << endl
				<< "no LCM" << endl << endl;
			continue;
		}
		if (a == 0 || b == 0)
		{
			cout << "Case " << ++count << ":" << endl
				<< "GCD(" << a << "," << b << ") = " << (a == 0 ? b : a) << endl
				<< "no LCM" << endl << endl;
			continue;
		}
		cout << "Case " << ++count << ":" << endl
			<< "GCD(" << a << "," << b << ") = " << gcd(a, b) << endl
			<< "LCM(" << a << "," << b << ") = " << lcm(a, b) << endl << endl;
	}
	return 0;
}