#include <iostream> 
#include <algorithm> 
using namespace std;
long long N, M;
long long max1 = 0;
long long geshu(long long i, long long x);
long long fun(long long i, long long j);
long long deng = 0, dengshu = 0;
long long C(long long mid);
long long k;
long long chaxunzhi;
int main()
{
	while (-1 == scanf("%lld%lld%lld", &N, &M, &k)) {
		long long lo = 11ll, hi = fun(N, M);
		while (lo + 1<hi) {
			long long mid = (lo + hi + 1) / 2;
			long long xiao = C(mid);
			if (xiao + deng >= k&&xiao<k) { hi = mid; break; }
			if (xiao <= k)
			{ if (xiao == k) hi = mid - 1;
				else lo = mid; }
			else
			{ hi = mid; }
		}
		printf("%lld\n", hi);
	}

}

long long fun(long long i, long long j) {
	return 2ll * i*j + 3ll * i + 3ll * j + 3ll;
}

long long C(long long mid) {
	deng = 0;
	long long count = 0;
	chaxunzhi = M;
	for (int i = 1; i <= N; i++) {
		if (fun(i, M)<mid) { count += M; continue; }
		if (fun(i, 1)>mid) { break; }
		count += geshu(i, mid);
		if (count >= k) return count;
	}
	return count;
}

long long geshu(long long i, long long x) {
	if (fun(i, M)<x) return M;
	if (fun(i, 1)>x) return 0;
	long long result1 = 0;
	for (int j = chaxunzhi; j >= 1; j--) {
		if (fun(i, j) == x) { deng++; dengshu = x; }
		if (fun(i, j)<x) { chaxunzhi = j; return j; }
	}
	return result1;
}