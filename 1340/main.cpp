#include <iostream>

using namespace std;

int main()
{
	long long n, m;
	long long a[107];
	for (int i = 0; i < 107; ++i)
		a[i] = 0;
	cin >> n >> m;
	a[0 + 6] = 1;
	a[-1 + 6] = 1;
	for (long long j = 1; j <= n; ++j)
		a[j + 6] = 2 * a[j - 1 + 6] - a[j - m - 1 + 6];
	cout << a[n + 6] << endl;
	return 0;
}


/*program p1232;
var n,m,j:longint;
a:array[-6..100]of int64;
begin
readln(n,m);
a[0]:=1; a[-1]:=1;
for j:=1 to n do a[j]:=2*a[j-1]-a[j-m-1];
writeln(a[n]);
end.*/