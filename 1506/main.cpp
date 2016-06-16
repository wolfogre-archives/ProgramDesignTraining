#include <iostream>
#include <string>
using namespace std;

bool SubString(string str1, string str2)
{
	if (str1 == str2)
		return true;
	if (str1.length() >= str2.length())
		return false;
	for (size_t i = 0; i < str2.length(); ++i)
	{
		string temp = str2;
		temp.erase(i, 1);
		if (SubString(str1, temp))
			return true;
	}
	return false;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		while (str2.find_first_not_of(str1) != string::npos)
			str2.erase(str2.find_first_not_of(str1), 1);
		if (SubString(str1, str2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
