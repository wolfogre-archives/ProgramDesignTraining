﻿#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double r;
	while (cin >> r)
		cout << fixed << setprecision(3) << 4.0 / 3 * M_PI * r * r * r << endl;
	return 0;
}