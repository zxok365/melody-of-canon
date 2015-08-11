#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1111111;
int ck[N],p[N];
int tot;
int main(){
	memset(ck,0,sizeof ck);
	tot = 0;
	for (int i = 2;i <= 1000000;i ++){
		if (!ck[i]) p[tot ++]  = i;
		for (int j = 0;j < tot;j ++){
			if (i * p[j] > 1000000) break;
			ck[i * p[j]] = 1;
			if (i % p[j] == 0 ) break;
		}
	}
	int task;
	scanf("%d",&task);
	while (task --){
		int n;
		scanf("%d",&n);
		int ans = 1;
		for (int i = 0;i < tot;i ++){
			if (p[i] * p[i] > n) break;
			if (n % p[i] == 0){
				int x = n,cnt = 0;
				while (x % p[i] == 0){
					x /= p[i];
					++ cnt;
				}
				ans = max(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
