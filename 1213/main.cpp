#include <iostream>

using namespace std;

bool is_prime(int n)
{
	for(int i = 2; i < n / 2; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	cout << (is_prime(n) ? "Y" : "N" ) << endl;
	return 0;
}