//波利亚计数定理，我不懂

#include<iostream>
#include<iomanip>
#include<cmath>

int main()
{
	int c;
	while (std::cin >> c)
		std::cout << std::fixed << std::setprecision(0) 
		<< 1.0 / 10 * (pow(c, 2) * 4 + pow(c, 6) * 5 + pow(c, 10)) 
		<< std::endl;
	return 0;
}