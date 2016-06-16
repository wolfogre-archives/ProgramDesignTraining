#include <iostream>
#include <sstream>
#include <vector>

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

bigint make(int num, size_t zero_num)
{
	bigint result;
	stringstream sstr;
	sstr << num;
	while (zero_num-- > 0)
		sstr << "0";
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

bigint mul(const bigint &a, const bigint &b)
{
	bigint result;
	for (size_t i = 0; i < a.size(); ++i)
		for (size_t j = 0; j < b.size(); ++j)
		{
			bigint temp = make(a[i] * b[j], i + j);
			result = add(result, temp);
		}
	return result;
}

int main()
{
	string num1, num2;
	while(cin >> num1 >> num2)
	{
		bigint b1 = make(num1);
		bigint b2 = make(num2);
		cout << num1 << "*" << num2 << "=" << get(mul(b1, b2)) << endl;
	}
	return 0;
}