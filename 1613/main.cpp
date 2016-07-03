#include <iostream>

using namespace std;

int min_times(int n)
{
	if (n <= 3)
		return 1;
	return 1 + min_times((n + 2) / 3);//尾递归不爆栈
}

int main()
{
	int n;
	while(cin >> n && n != 0)
		cout << n << endl
			<< "Times:" << min_times(n) << endl;
	return 0;
}