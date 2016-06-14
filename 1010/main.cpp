#include <iostream>
using namespace std;
int main()
{
	double sum = 0;
	int answer = 0;
	int k;
	cin >> k;
	while ((sum += 1.0 / ++answer) <= k)
		;
	cout << answer;
	return 0;
}