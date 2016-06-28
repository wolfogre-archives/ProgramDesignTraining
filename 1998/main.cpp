#include <iostream>
#include <cmath>

using namespace std;

//对于C(N,K),若N&K == K 则C(N,K)为奇数，否则为偶数
//http://www.cnblogs.com/XMJQVRWSD/p/4049568.html

//进一步推理，n的二进制中有k个1，则结果是2 ^ k

int count_odd(int n)
{
	int one_count = 0;
	while(n != 0)
	{
		one_count += n % 2;
		n /= 2;
	}
	return int(pow(2, one_count));
}

int main()
{
	int t;
	cin >> t;
	while(t-- > 0)
	{
		int n;
		cin >> n;
		cout << count_odd(n) << endl;
	}
	return 0;
}