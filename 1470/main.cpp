#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

map<int, string> dictionary;
string temp(15,'0');

map<int, int> two_pow;

int get_two_pow(int n)
{
	return two_pow.find(n)->second;
}

int bits_to_int(string bits)
{
	int result = 0;
	int if_signed = 1;
	for(int i = bits.size() - 1, power = 0; i >= 0; --i, ++power)
	{
		result += get_two_pow(power) * if_signed * (bits[i] - '0');
		if_signed *= -1;
	}
	return result;
}


void init_dictionary(int index)
{
	if (index > 14)
	{
		int value = bits_to_int(temp);
		dictionary.insert(pair<int, string>(value, temp));
		return;
	}
	temp[index] = '0';
	init_dictionary(index + 1);
	temp[index] = '1';
	init_dictionary(index + 1);
}

void init_two_pow()
{
	for (int i = 0; i <= 15; ++i)
		two_pow.insert(pair<int, int>(i, pow(2, i)));
}

void init()
{
	init_two_pow();
	init_dictionary(0);
}

string int_to_bits(int n)
{
	string result = dictionary.find(n)->second;
	while (result[0] == '0')
		result.erase(result.begin());
	return result;
	
}

int main()
{
	init();
	cout << "Finished" << endl;
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