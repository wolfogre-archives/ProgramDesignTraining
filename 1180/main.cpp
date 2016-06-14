#include <iostream>
#include <sstream>

using namespace std;

int reverse(int n)
{
	stringstream sstr;
	sstr << n;
	string str;
	sstr >> str;
	sstr.clear();
	for (int i = str.length() - 1; i >= 0; --i)
		sstr << str[i];
	sstr >> n;
	return n;
}

int main()
{
	int n;
	cin >> n;
	while(n-- > 0)
	{
		int num;
		cin >> num;
		int i;
		for(i = 0; i < 9; ++i)
		{
			num += reverse(num);
			if(num == reverse(num))
				break;
		}
		if (i == 9)
			cout << 0 << endl;
		else
			cout << i + 1 << endl;
	}

	
	return 0;
}