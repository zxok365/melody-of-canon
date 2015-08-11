#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main( )
{
	int T, n, k;
	scanf("%d", &T);
	for (int j = 1; j <= T; j ++)
	{
	scanf("%d %d", &n, &k);
	printf("Case #%d: %.8f\n", j, 1.0 / (n * k + k + 1));
	}
	return 0;
}
