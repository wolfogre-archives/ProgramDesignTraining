#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double del = b * b - 4 * a * c;
	if(del < 0)
		cout << "none";
	else
		cout << fixed << setprecision(2) << (-b + sqrt(del)) / (2 * a) << " " << (-b - sqrt(del)) / (2 * a);
	return 0;
}