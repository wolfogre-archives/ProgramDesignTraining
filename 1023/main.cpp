#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<bool> numbers;
	int n;
	cin >> n;
	for(int i = 0; i <= n; ++i)
		numbers.push_back(true);
	numbers[0] = false;
	numbers[1] = false;
	for(size_t i = 0; i < numbers.size(); ++i)
	{
		if(numbers[i])
		{
			size_t j = 2;
			while(i * j < numbers.size())
			{
				numbers[i * j] = false;
				++j;
			}
		}
	}
	for (size_t i = 0; i < numbers.size(); ++i)
		if(numbers[i])
			cout << i << endl;
	return 0;
}