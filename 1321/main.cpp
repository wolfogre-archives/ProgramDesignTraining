#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

typedef vector<int> bigint;

#define BILLION 1000000000

bigint make(string str)
{
	bigint result;
	string temp = "";
	for (int i = str.length() - 1; i >= 0; --i)
	{
		if (str[i] < '0' || str[i] > '9')
			throw exception("error");
		temp = str[i] + temp;
		if(temp.length() == 9)
		{
			stringstream sstr;
			sstr << temp;
			temp = "";
			int num;
			sstr >> num;
			result.push_back(num);
		}
	}
	if (temp.length() != 0)
	{
		stringstream sstr;
		sstr << temp;
		int num;
		sstr >> num;
		result.push_back(num);
	}
	return result;
}

bigint make(long long num, size_t zero_num)
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
	sstr << bi.back();
	bi.pop_back();
	while (!bi.empty())
	{
		sstr << setw(9) << setfill('0') << bi.back();
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
		carry = sum / BILLION;
		sum %= BILLION;
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
			if((i + j) * 9 > 100)
				continue;
			bigint temp = make(long long(a[i]) * long long(b[j]), (i + j) * 9);
			result = add(result, temp);
		}
	clock_t end = clock();
	cout << double(end - start) / CLOCKS_PER_SEC << " to " << a.size() << "*" << b.size() << endl;
	return result;
}

int main()
{
	
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

//	string num1, num2;
//	while(cin >> num1 >> num2)
//	{
//		cout << get(mul(make(num1), make(num2))) << endl;
//	}
//	return 0;
}