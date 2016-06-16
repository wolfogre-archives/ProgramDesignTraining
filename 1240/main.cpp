#include <iostream>
#include <string>

using namespace std;

bool cal(int a, int b, int op, int &result)
{
	switch (op)
	{
	case 0:
		result = a + b;
		return true;
	case 1:
		if (a - b < 0)
			return false;
		result = a - b;
		return true;
	case 2:
		result = a * b;
		return true;
	case 3:
		if(a % b != 0)
			return false;
		result = a / b;
		return true;
	}
	return false;
}

int get_int(string str)
{
	if (str.length() == 2)
		return 10;
	if (str[0] == 'A')
		return 1;
	if (str[0] == 'J')
		return 11;
	if (str[0] == 'Q')
		return 12;
	if (str[0] == 'K')
		return 13;
	return str[0] - '0';
}

int main()
{
	string input[4];
	while(cin >> input[0] >> input[1] >> input[2] >> input[3])
	{
		int num[4];
	}
	//      1
	//  1      1
	//1   1   1  1
	
	return 0;
}