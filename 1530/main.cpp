#include <iostream>
#include <string>

using namespace std;

typedef long long llong;

llong hash_code = 1234567890;

llong hash_table[10000];

void init_hash_table()
{
	for(int num = 1; num <= 9999; ++num)
	{
		llong r = 1;
		for (int i = 0; i < num; ++i)
			r = (r * num % hash_code);
		hash_table[num] = r;
	}
}

int search_hash_table(llong hash_value)
{
	for(int i = 1; i < 10000; ++i)
		if (hash_value == hash_table[i])
			return i;
	return -1;
}

int main()
{
	init_hash_table();
	string str;
	while(cin >> str)
	{
		llong hash_value = 0;
		for (auto it : str)
			hash_value = (hash_value * 10 + it - '0') % hash_code;
		int result = search_hash_table(hash_value);
		if (result != -1)
			cout << result << endl;
		else
			cout << "NO" << endl;
	}
}