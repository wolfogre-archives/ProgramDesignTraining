// Thank Jin Yu
#include <iostream> 
#include <algorithm> 
using namespace std;

typedef long long llong;

llong N, M;
llong max1 = 0;
llong deng = 0, dengshu = 0;
llong k;
llong chaxunzhi;

llong fun(llong i, llong j) {
	return 2ll * i*j + 3ll * i + 3ll * j + 3ll;
}

llong geshu(llong i, llong x) {
	if (fun(i, M)<x) return M;
	if (fun(i, 1)>x) return 0;
	llong result1 = 0;
	for (int j = chaxunzhi; j >= 1; j--) {
		if (fun(i, j) == x) { deng++; dengshu = x; }
		if (fun(i, j)<x) { chaxunzhi = j; return j; }
	}
	return result1;
}

llong C(llong mid) {
	deng = 0;
	llong count = 0;
	chaxunzhi = M;
	for (int i = 1; i <= N; i++) {
		if (fun(i, M)<mid) { count += M; continue; }
		if (fun(i, 1)>mid) { break; }
		//printf("%d%d\n",i,N);
		count += geshu(i, mid);
		if (count >= k) return count;
	}
	return count;
}



int main(int argc, char *argv[])
{
	cin >> N >> M >> k;
	llong lo = 11ll, hi = fun(N, M);
	while (lo < hi) {
		llong mid = (lo + hi + 1) / 2;

		llong xiao = C(mid);
		if (xiao + deng >= k&&xiao<k) { hi = mid; break; }
		else if (xiao>k) hi = mid;
		else if (xiao == k) hi = mid - 1;
		else lo = mid;
	}
	cout << hi << endl;
	return 0;
}

