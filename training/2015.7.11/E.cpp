#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 22;
const int mod = (int)(1e9) + 7;
ll m1[N][N],m2[N][N],b[N][N],c[N][N],org[N][N];
ll a[N],s[N],fir[N];
void initb(int r){
	for (int i = 1;i <= r + 1;i ++)
		for (int j = 1;j <= r + 1;j ++) b[i][j] = 0;
}
void getmatrix(int r,int tk){
	for (int j = 1;j < r;j ++){
		for (int i = 1;i <= r + 1;i ++) m1[i][j] = 0;
		m1[j + 1][j] = 1;
	}
	for (int i = 1;i <= r;i ++) m1[i][r] = a[r - i + 1];
	m1[r + 1][r] = 0;
	for (int i = 1;i <= r + 1;i ++) m1[i][r + 1] = 0;
	m1[r + 1][r + 1] = m1[r][r + 1] = 1;
	for (int i = 1;i <= r + 1;i ++)
		for (int j = 1; j <= r + 1;j ++) m2[i][j] = m1[i][j];
	m2[r][r + 1] = 0;
	for (int i = 1;i <= r + 1;i ++)
		for (int j = 1;j <= r + 1;j ++) org[i][j] = m1[i][j];
	for (int p = 1;p < tk;p ++){
		initb(r);
		for (int i = 1;i <= r + 1;i ++)
			for (int j = 1;j <= r + 1;j ++)
				for (int k = 1;k <= r + 1;k ++) b[i][j] = (b[i][j] + org[i][k] * m2[k][j] % mod) % mod;
		for (int i = 1;i <= r + 1;i ++)
			for (int j = 1;j <= r + 1;j ++) org[i][j] = b[i][j];
	}
}
void fast(int r,int n){
	if (n == 1){
		for (int i = 1;i <= r + 1;i ++)
			for (int j = 1;j <= r + 1;j ++)
				c[i][j] = org[i][j];
		return;
	}
	fast(r,n / 2);
	initb(r);
	for (int i = 1;i <= r + 1;i ++)
		for (int j = 1;j <= r + 1;j ++)
			for (int k = 1;k <= r + 1;k ++) b[i][j] = (b[i][j] + c[i][k] * c[k][j] % mod) % mod;
	for (int i = 1;i <= r + 1;i ++)
		for (int j = 1;j <= r + 1;j ++) c[i][j] = b[i][j];
	if (n & 1){
		initb(r);
		for (int i = 1;i <= r + 1;i ++)
			for (int j = 1;j <= r + 1;j ++)
				for (int k = 1;k <= r + 1;k ++) b[i][j] = (b[i][j] + c[i][k] * org[k][j] % mod) % mod;
		for (int i = 1;i <= r + 1;i ++)
			for (int j = 1;j <= r + 1;j ++) c[i][j] = b[i][j];
	}
}
int main(){
	int task;
	scanf("%d",&task);
	while (task --){
		int n,r,k;
		scanf("%d%d%d",&n,&r,&k);
		for (int i = 1;i <= r;i ++) scanf("%lld",&s[i]);
		for (int i = 1;i <= r;i ++) scanf("%lld",&a[i]);
		if (n <= r && n * k <= r){
			ll ans = 0;
			for (int i = 1;i <= r;i ++)
				if (i % k == 0) ans = (ans + s[i]) % mod;
			printf("%lld\n",ans);
		}else{
			getmatrix(r,k);
			int idx = 1;
			while (idx * k < r) idx ++;
			for (int i = r + 1;i <= idx * k;i ++){
				s[i] = 0;
				for (int j = i - 1,k = 1;k <= r;k ++,j --) s[i] = (s[i] + a[k] * s[j]) % mod;
			}
			for (int i = 1;i <= r;i ++) fir[i] = s[idx * k - (r - i)];
			fir[r + 1] = 0;
			for (int i = 1;i < idx;i ++) fir[r + 1] = (fir[r + 1] + s[i * k]) % mod;
			fast(r,n - idx + 1);
			ll ans = 0;
			for (int i = 1;i <= r + 1;i ++)
				ans = (ans + fir[i] * c[i][r + 1] % mod) % mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
