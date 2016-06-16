#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	const double g = 9.81;
	double w, l, s, k;
	while(cin >> w >> l >> s >> k)
	{

		double K = 0.5 * k * max(s - l, 0.0) * max(s - l, 0.0);
		double G = g * s * w;
		double E = 0.5 * 10 * 10 * w;
		if(K > G)
			cout << "S" << endl;
		else
			if(G - K > E)
				cout << "D" << endl;
			else
				cout << "Y" << endl;
	}
	return 0;
}