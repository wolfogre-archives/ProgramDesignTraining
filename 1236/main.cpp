#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> fib;
	fib.push_back(1);
	fib.push_back(1);
	for (int i = 2; i < 40; ++i)
		fib.push_back(fib[i - 1] + fib[i - 2]);
	while(n-- > 0)
	{
		int m;
		cin >> m;
		cout << fib[m - 1] << endl;
	}
	return 0;
}