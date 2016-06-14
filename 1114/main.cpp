#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef vector<int> bigint;

bigint make(string str)
{
	bigint result;
	for (int i = str.length() - 1; i >= 0; --i)
	{
		if (str[i] < '0' || str[i] > '9')
			return result;
		result.push_back(str[i] - '0');
	}
	return result;
}

bigint make_by_repeat(int num, size_t repeat)
{
	bigint result;
	stringstream sstr;
	while (repeat-- > 0)
		sstr << num;
	string str;
	sstr >> str;
	result = make(str);
	return result;
}

string get(bigint bi)
{
	stringstream sstr;
	while (!bi.empty())
	{
		sstr << bi.back();
		bi.pop_back();
	}
	string result;
	sstr >> result;
	return result;
}

bigint add(const bigint &a, const bigint &b)
{
	bigint result;
	int carry = 0;
	for (size_t i = 0; i < a.size() || i < b.size() || carry != 0; ++i)
	{
		int sum = (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0) + carry;
		carry = sum / 10;
		sum %= 10;
		result.push_back(sum);
	}
	return result;
}

int main()
{
	int n;
	int a;
	cin >> a >> n;
	bigint sum = make("0");
	for (int i = 1; i <= n; ++i)
	{
		sum = add(sum, make_by_repeat(a, i));
	}
	cout << get(sum);
}