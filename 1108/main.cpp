#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> numbers;
	for (int i = 0; i < 10; ++i)
	{
		int num;
		cin >> num;
		auto it = numbers.begin();
		for (; it != numbers.end(); ++it)
		{
			if (*it < num)
			{
				numbers.insert(it, num);
				break;
			}
		}
		if (it == numbers.end())
			numbers.insert(it, num);
	}

	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		if (it == numbers.begin())
			cout << *it;
		else
			cout << " " << *it;
	}

	return 0;
}