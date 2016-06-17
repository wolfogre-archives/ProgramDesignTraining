#include <iostream>
#include <map>

using namespace std;

typedef long long llong;

map<llong, llong> dir;

llong gcb(llong a, llong b)
{
	if (b == 0)
		return a;
	return gcb(b, a % b);
}

llong pow(llong a, llong n)//I dont believe the pow() in cmath
{
	auto p = dir.find(n);
	if (p != dir.end())
		return p->second;
	llong result = 1;
	while (n-- > 0)
		result *= a;
	dir.insert(pair<llong, llong>(n, result));
	return result;
}

int main()
{
	int t;
	cin >> t;

	while(t-- > 0)
	{
		llong n, m;
		cin >> n >> m;
		llong sum = 0;
		dir.clear();
		for(int k = 1; k <= n; ++k)
		{
			cout << k << " " << gcb(n, k) << endl;
			//sum += pow(m, gcb(n, k)) % 1000000007;
		}
			
		cout << sum << endl;
	}
	return 0;
}