#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char, int> input;
	string str;
	getline(cin, str);
	getline(cin, str);
	for(auto ch : str)
	{
		if (input.find(ch) != input.end())
			++input.find(ch)->second;
		else
			input.insert(pair<char, int>(ch, 1));
	}
	vector<int> numerator, denominator;
	for (size_t i = 1; i <= str.length(); ++i)
		numerator.push_back(i);
	for (auto p : input)
		for (int i = 1; i <= p.second; ++i)
			denominator.push_back(i);
	for(auto it : denominator)
	{
		for(size_t i = 0; i < numerator.size(); ++i)
		{
			if (numerator[i] % it == 0)
			{
				numerator[i] = numerator[i] / it;
				break;
			}
				
		}
	}

	int result = 1;
	for (auto it : numerator)
		result *= it;

	cout << result;
	return 0;
}