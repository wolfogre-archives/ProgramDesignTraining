#include <iostream>

using namespace std;

int main()
{
	int a1, a2, b1, b2, c1, c2;
	while ((cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2) && a1 + a2 + b1 + b2 + c1 + c2 > 0)
	{
		int sum = a1 + a2;
		int sub = a1 - a2 + b1 - b2 + c1 - c2;
		int d1 = (sum - sub) / 2;
		int d2 = sub + d1;
		cout << "Anna's won-loss record is " << d1 << "-" << d2 << "." << endl;
	}
	return 0;
}