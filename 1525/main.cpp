#include <iostream>

using namespace std;

//Z =[N/5] + [N/52] + [N/53] + …
//http://www.acmerblog.com/factorial-zero-number-5683.html

int count_zero(int n)
{
	int result = 0;
	while ((n /= 5) != 0)
		result += n;
	return result;
}

int main()
{
	int n;
	cin >> n;
	while(n-- > 0)
	{
		int m;
		cin >> m;
		cout << count_zero(m) << endl;
	}
	return 0;
}