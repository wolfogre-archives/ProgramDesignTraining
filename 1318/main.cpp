#include <iostream>

using namespace std;

int record[20][20][20];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	if (record[a - 1][b - 1][c - 1] != INT32_MAX)
		return record[a - 1][b - 1][c - 1];

	int result;
	if (a < b && b < c)
		result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	record[a - 1][b - 1][c - 1] = result;
	return result;
}

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c && (a != -1 || b != -1 || c != -1))
	{
		for (int i = 0; i < 20; ++i)
			for (int j = 0; j < 20; ++j)
				for (int k = 0; k < 20; ++k)
					record[i][j][k] = INT32_MAX;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}
		
	return 0;
}