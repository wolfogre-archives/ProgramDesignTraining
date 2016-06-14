#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

int main()
{
	int r;
	while (cin >> r)
	{
		unsigned v = r < 0 ? -r : r;
		bitset<32> bit(v);
		string bit_str;
		stringstream sstr;
		sstr << bit;
		sstr >> bit_str;
		while (bit_str[0] == '0' && bit_str.length() > 1)
			bit_str.erase(0 , 1);
		if (r < 0)
			bit_str = "-" + bit_str;
		cout << setw(11) << r << setw(0) << "-->" << bit_str << endl;
	}
		
	return 0;
}