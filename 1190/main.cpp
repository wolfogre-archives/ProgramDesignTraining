#include <iostream>

using namespace std;

int main()
{
	int start, end;
	while(cin >> start >> end)
	{
		int sum2 = 0;
		int sum3 = 0;
		for(int i = start; i <= end; ++i)
		{
			if (i % 2 == 0)
				sum2 += i * i;
			else
				sum3 += i * i * i;
		}
		cout << sum2 << " " << sum3 << endl;
	}
	return 0;
}