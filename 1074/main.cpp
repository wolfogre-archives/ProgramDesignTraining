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

int get(bigint bi)
{
	if (bi.size() > 10)
		return -1;
	stringstream sstr;
	while (!bi.empty())
	{
		sstr << bi.back();
		bi.pop_back();
	}
	int result;
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

bigint sub(const bigint &a, const bigint &b)
{
	bigint result;
	int carry = 0;
	for (size_t i = 0; i < a.size() || i < b.size() || carry != 0; ++i)
	{
		int sum = (i < a.size() ? a[i] : 0) - (i < b.size() ? b[i] : 0) - carry;
		carry = 0;
		if(sum < 0)
		{
			carry = 1;
			sum += 10;
		}
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

bool div_by_17(bigint bi)
{
	if(bi.size() < 5)
		return get(bi) % 17 == 0;
	int temp = bi[0];
	bi.erase(bi.begin());
	return div_by_17(sub(bi, make(temp * 5, 0)));
}

int main()
{
	string n;
	while (cin >> n && get(make(n)) != 0)
		cout << (div_by_17(make(n)) ? 1 : 0) << endl;
	return 0;
}