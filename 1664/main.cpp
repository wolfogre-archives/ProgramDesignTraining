#define  _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main()
{
	int n;
	char str[20];
	while (scanf("%d", &n) != EOF)
	{
		int length = 0;
		while(n != 0)
		{
			str[length++] = (n % 3) + '0';
			n /= 3;
		}
		if (length == 0)
		{
			putchar('0');
			putchar('\n');
		}
		else
		{
			for(int i = length - 1; i >= 0; --i)
				putchar(str[i]);
			putchar('\n');
		}
	}
	return 0;
}