#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, A, B;
int a[100005];
void Work()
{
	scanf("%d %d %d", &n, &A, &B);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	ll sum = A + B;
	for (int i = 2; i <= n; i ++)
		sum += min(1LL * (a[i] - a[i - 1] - 1) * B, 2LL * A) + B;
	sum += A;
	printf("%I64d\n", sum);
}
int main( )
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++)
	{
		printf("Case #%d: ", i);
		Work();
	}
	return 0;
}
