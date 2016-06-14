#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n;
	list<int> numbers;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		auto it = numbers.begin();
		for (; it != numbers.end(); ++it)
		{
			if (*it == num)
				break;
			if (*it > num)
			{
				numbers.insert(it, num);
				break;
			}
		}
		if(it == numbers.end())
			numbers.insert(it, num);
	}
	cout << numbers.size() << endl;
	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		if(it == numbers.begin())
			cout << *it;
		else
			cout << " " << *it;
	}
		
	return 0;
}