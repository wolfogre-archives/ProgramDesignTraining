#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

struct Point
{
	Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	double x;
	double y;
	double z;
};

double distance(const Point &a, const Point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main()
{
	int n;
	cin >> n;
	vector<Point> input;
	double x, y, z;

	while(n-- > 0)
	{
		cin >> x >> y >> z;
		input.push_back(Point(x, y, z));
	}

	cin >> x >> y >> z;
	Point acm(x, y, z);
	cin >> x >> y >> z;
	Point future(x, y, z);

	Point mid = Point((acm.x + future.x) / 2, (acm.y + future.y) / 2, (acm.z + future.z) / 2);

	double min = distance(mid, input[0]);
	size_t min_index = 0;
	for(size_t i = 0 + 1; i < input.size(); ++i)
	{
		double temp = distance(mid, input[i]);
		if(temp < min)
		{
			min = temp;
			min_index = i;
		}
	}

	cout << fixed << setprecision(3) << input[min_index].x << " " << input[min_index].y << " " << input[min_index].z;

	return 0;
}