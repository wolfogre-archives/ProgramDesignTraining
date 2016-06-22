#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

vector<int> value;
vector<pair<int, int>> when_have;
vector<pair<int, int>> when_not_have;
vector<pair<int, int>> min_and_max;

void init()
{
	when_have.push_back(pair<int, int>(1, 1));
	when_not_have.push_back(pair<int, int>(0, 0));
	min_and_max.push_back(pair<int, int>(0, 1));
	value.push_back(1);
	for(int i = 1, if_signed = -1; i <= 15; ++i, if_signed *= -1)
	{
		int v = pow(2, i) * if_signed;
		value.push_back(v);
		when_have.push_back(pair<int, int>(min_and_max[i - 1].first + v, min_and_max[i - 1].second + v));
		when_not_have.push_back(pair<int, int>(min_and_max[i - 1].first, min_and_max[i - 1].second));
		min_and_max.push_back(pair<int, int>(min(when_have[i].first, when_not_have[i].first), max(when_have[i].second, when_not_have[i].second)));
	}
}

int bits_to_int(string bits)
{
	int result = 0;
	for (int i = bits.size() - 1, power = 0, if_signed = 1; i >= 0; --i, ++power, if_signed *= -1)
		result += pow(2, power) * if_signed * (bits[i] - '0');
	return result;
}

string int_to_bits(int n)
{
	string result(16, '0');
	for(int i = 15; i >= 0 && n != 0; --i)
	{
		if(when_have[i].first <= n && when_have[i].second >= n)
		{
			result[15 - i] = '1';
			n -= value[i];
		}
	}
	while (result.front() == '0' && result.length() > 1)
		result.erase(result.begin());
	return result;
}

int main()
{
	init();
	int t;
	cin >> t;
	while(t-- > 0)
	{
		char type;
		cin >> type;
		if(type == 'b')
		{
			string bits;
			cin >> bits;
			cout << "From binary: " << bits << " is " << bits_to_int(bits) << endl;
		}
		else
		{
			int n;
			cin >> n;
			cout << "From decimal: " << n << " is " << int_to_bits(n) << endl;
		}
	}
	return 0;
}