#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n;
	list<int> numbers;
	while(cin >> n)
	{
		numbers.clear();
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			auto it = numbers.begin();
			for (; it != numbers.end(); ++it)
			{
				if (*it > num)
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
		cout << endl;
	}
	
	return 0;
}