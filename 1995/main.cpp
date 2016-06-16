#include <iostream>
#include <vector>

using namespace std;

bool sort_by_candy(vector<int> &input)
{
	for(size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for(size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}
	return true;;
}

int main()
{
	int n;
	cin >> n;
	while(n-- > 0)
	{
		int count;
		cin >> count;
		vector<int> input;
		while(count-- > 0)
		{
			int num;
			cin >> num;
			input.push_back(num);
		}
		if (sort_by_candy(input))
		{
			cout << input[0];
			for (size_t i = 0 + 1; i < input.size(); ++i)
				cout << " " << input[i];
			cout << endl;
		}
		else
			cout << "Impossible" << endl;
	}
	return 0;
}