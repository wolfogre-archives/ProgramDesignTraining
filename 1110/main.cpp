#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = 1;
	int temp = 1;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	cout << 1 << " " << 1;

	for(int i = 3; i <= n; ++i)
	{
		result = temp + result;
		temp = result - temp;
		cout << " " << result;
	}
	return 0;
}