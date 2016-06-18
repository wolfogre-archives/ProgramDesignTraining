#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>

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

bigint mul(bigint a, bigint b)
{
	clock_t start = clock();
	bigint result;
	for (size_t i = 0; i < a.size(); ++i)
		for (size_t j = 0; j < b.size(); ++j)
		{
			bigint temp = make(a[i] * b[j], i + j);
			result = add(result, temp);
			while (result.size() > 100)
				result.pop_back();
		}
	clock_t end = clock();
	cout << double(end - start) / CLOCKS_PER_SEC << " to " << a.size() << "*" << b.size() << endl;
	return result;
}

int main()
{
	
/*
	int n, m;
	cin >> n >> m;
	int s = n + m;
	vector<int> numerator;

	for(int i = 1; i <= s; ++i)
		numerator.push_back(i);
	for (int i = 1; i <= n; ++i)
	{
		for (size_t j = 0; j < numerator.size(); ++j)
			if (numerator[j] % i == 0)
			{
				numerator[j] = numerator[j] / i;
				break;
			}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (size_t j = 0; j < numerator.size(); ++j)
			if (numerator[j] % i == 0)
			{
				numerator[j] = numerator[j] / i;
				break;
			}
	}
		

	bigint result = make("1");

	for(auto i : numerator)
	{
		if (i != 1)
			result = mul(result, make(i, 0));
	}


		

	string output = get(result);

	while(output.length() < 100)
		output = "0" + output;

	for(int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
			cout << output[i * 10 + j];
		cout << endl;
	}
*/

	string num1, num2;
	while(cin >> num1 >> num2)
	{
		cout << get(mul(make(num2), make(num2))) << endl;
	}
	return 0;
}