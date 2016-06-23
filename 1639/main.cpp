//http://www.acmerblog.com/hdu-4445-crazy-tank-7458.html

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef double db;

const db g = 9.8;
const db pi = acos(-1.0);
const db eps = 1e-8;

db distance(db ang, db v, db h)
{
	db s = sin(ang);
	db c = cos(ang);
	return v * s * (v * c + sqrt(v * v * c * c + 2.0 * g * h)) / g;
}

db tris(db v ,db h)
{
	db l = 0, r = pi / 2.0;
	int t = 30;
	while (t-- > 0)
	{
		db mid = (l + r) / 2.0;
		db midd = (l + mid) / 2.0;
		if (distance(midd, v, h) > distance(mid, v, h))
			r = mid;
		else
			l = midd;
	}
	return l;
}

db bis_left(db l, db r, db d, db v, db h)
{
	int t = 30;
	while (t-- > 0)
	{
		db mid = (l + r) / 2.0;
		if (distance(mid, v, h) <= d)
			l = mid;
		else
			r = mid;
	}
	return l;
}

db bis_right(db l, db r, db d, db v, db h)
{
	return bis_left(r, l, d, v, h);
}


int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		db h;
		vector<db> v;
		db pos[4];
		cin >> h >> pos[0] >> pos[1] >> pos[2] >> pos[3];
		for (int i = 0; i < n; i++)
		{
			db t;
			cin >> t;
			v.push_back(t);
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)

			{
				db farest = tris(v[i], h);
				if (distance(farest, v[i], h) < pos[j])
					continue;
				db w = pos[j];
				if (j == 0)
					w += eps;
				if (j == 1)
					w -= eps;
				if (j == 2)
					w -= eps;
				if (j == 3)
					w += eps;
				db ang = bis_left(0.0, farest, w, v[i], h);
				bool flag = true;
				int c = 0;
				for (int k = 0; k < n; k++)
				{
					db here = distance(ang, v[k], h);
					if (here >= pos[2] && here <= pos[3])
					{
						flag = false;
						break;
					}
					if (here >= pos[0] && here <= pos[1])
						++c;
				}
				if (flag) res = max(res, c);
				if (res == n) break;

				ang = bis_right(farest, pi, w, v[i], h);
				flag = true;

				c = 0;
				for (int k = 0; k < n; k++)
				{
					db here = distance(ang, v[k], h);
					if (here >= pos[2] && here <= pos[3])
					{
						flag = false;
						break;
					}
					if (here >= pos[0] && here <= pos[1])
						++c;
				}
				if (flag) res = max(res, c);
				if (res == n)
					break;
			}
		}
		cout << res << endl;
	}
	return 0;
}