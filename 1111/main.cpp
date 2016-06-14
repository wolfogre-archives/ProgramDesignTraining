#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max = n;
	while (cin >> n && n != -1)
		if (n > max)
			max = n;
	cout << max;
	return 0;
}