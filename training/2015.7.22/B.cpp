#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXS=400;

int n, c, sum, new_sum, tmp, tot1, tot2, tot, have, targ, targ_sum;
int a[1005], b[1005], w[1005];
pair<int, int> pack[2000005];
int p;
bool used[1005];

void print(int x) {
	if (x==1) puts("stop");
	if (x==2) puts("accept");
	if (x==3) puts("decline");
	fflush(stdout);
}

int check(int x) {
	int k;
	k=(int)((1.0*x*n/MAXS)+0.5);
	return k;
}

int find(int x) {
	int i;
	for (i=1; i<=n; i++) {
		if (used[i]) continue;
		if (w[i]==x) {
			used[i]=true;
			break;
		}
	}
	return (1<<(i-1));
}

bool in(int x1, int x2) {
	return ((x1&x2)!=0);
}

bool check_throw(int x) {
	int i;
	for (i=n; i>=1; i--) {
		if (used[i]&&w[i]==x&&(!in(1<<(i-1), targ))) {
			used[i]=false;
			sum-=x;
			have^=(1<<(i-1));
			if (sum==targ_sum) {
				print(1);
				return true;
			}
			print(2);
			return false;
		}
	}
	print(3);
	return false;
}

bool check_accept(int x) {
	int i;
	for (i=1; i<=n; i++) {
		if ((!used[i])&&w[i]==x&&(in(1<<(i-1), targ))) {
			used[i]=true;
			sum+=x;
			have^=(1<<(i-1));
			if (sum==targ_sum) {
				print(1);
				return true;
			}
			print(2);
			return false;
		}
	}
	print(3);
	return false;
}

int main() {
	scanf("%d%d%d", &n, &c, &sum);
	print(2);
	for (int i=1; i<=MAXS; i++) {
		scanf("%d", &new_sum);
		print(3);
		if (new_sum-sum<0) a[++tot1]=sum-new_sum;
			else b[++tot2]=new_sum-sum;
	}
	sort(a+1, a+tot1+1);
	sort(b+1, b+tot2+1);
	int last=0;
	for (int i=2; i<=tot1; i++) if (a[i]!=a[i-1]) {
		int tmp=check(i-1-last);
		for (int j=1; j<=tmp; j++) w[++tot]=a[i-1];
		last=i-1;
	}
	int tmp=check(tot1-last);
	for (int j=1; j<=tmp; j++) w[++tot]=a[tot1];
	
	last=0;
	for (int i=2; i<=tot2; i++) if (b[i]!=b[i-1]) {
		int tmp=check(i-1-last);
		for (int j=1; j<=tmp; j++) w[++tot]=b[i-1];
		last=i-1;
	}
	tmp=check(tot2-last);
	for (int j=1; j<=tmp; j++) w[++tot]=b[tot2];
	
	sort(w+1, w+n+1);
	p=0;
	for (int mask=0; mask<(1<<n); mask++) {
		int sum=0;
		for (int i=1; i<=n; i++) if ((mask&(1<<(i-1)))!=0) sum+=w[i];
		pack[++p]=make_pair(sum, mask);
	}
	sort(pack+1, pack+p+1);
	int k;
	for (k=p; k>=1; k--) if (pack[k].first<=c) break;
	targ=pack[k].second;
	targ_sum=pack[k].first;
	have=0;
	last=0;
	for (int i=2; i<=tot1; i++) if (a[i]!=a[i-1]) {
		int tmp=check(i-1-last);
		for (int j=1; j<=tmp; j++) have|=find(a[i-1]);
		last=i-1;
	}
	tmp=check(tot1-last);
	for (int j=1; j<=tmp; j++) have|=find(a[tot1]);	
	for (int step=1; step<=1000-1-MAXS; step++) {
		scanf("%d", &new_sum);		
		if (new_sum-sum<0) {
			if (check_throw(sum-new_sum)) break;
		} else {
			if (check_accept(new_sum-sum)) break;
		}
	}	
	if (sum!=targ_sum) while (1) {sum = sum + 1; sum = sum - 1;}
	return 0;
}
