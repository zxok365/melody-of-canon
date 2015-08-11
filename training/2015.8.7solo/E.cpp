#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


long long sqr(long long x){
	return x * x;
}
struct point{
	int x, y, z;
	point(){};
	point(int x, int y, int z) : x(x), y(y), z(z){}
	long long len(){
		return 1LL * x * x + 1LL * y * y + 1LL * z * z;
	}
} po[111111];

const double eps = 1e-10;
int now;
bool cmp(const int &p, const int &q){
	if (p == now) return true; 
	if (q == now) return false;
	int t1, t2, t3, t4 ,t5, t6;
	t1 = po[p].x - po[now].x;
	t2 = po[p].y - po[now].y;
	t3 = po[p].z - po[now].z;
	if (t1 == 0 && t2 == 0 && t3 == 0) return true;
//	if (t4 == 0 && t5 == 0 && t6 == 0) return false;
	t4 = po[q].x - po[now].x;
	t5 = po[q].y - po[now].y;
	t6 = po[q].z - po[now].z;
	if (t4 == 0 && t5 == 0 && t6 == 0) return false;
	if (t1 == 0 && t4 == 0)
	{
		if (t2 == 0) return true;
		if (t5 == 0) return false;
		return 1. * t3 / t2 < 1. * t6 / t5;
	}
	if (t1 == 0) return true;
	if (t4 == 0) return false;
	if (fabs(1. * t2 / t1 - 1. * t5 / t4) > eps) return 1. * t2 / t1 < 1. * t5 / t4;
	return 1. * t3 / t1 < 1. * t6 / t4;
}



long long dot(const point &p, const point &q){
	return 1LL * p.x * q.x + 1LL * p.y * q.y + 1LL * p.z * q.z;
}

point operator-(const point &p, const point &q){
	return point(p.x - q.x, p.y - q.y, p.z - q.z);
}
bool on_the_same_line(const point &p, const point &q, const point &r){
	point a = q - p, b = r - p;
	if (a.x == 0 && b.x == 0){
		return 1LL * a.y * b.z == 1LL * a.z * b.y;
	}
	if (a.x == 0 || b.x == 0) return false;
	return 1LL * a.x * b.y == 1LL * b.x * a.y && 1LL * a.x * b.z == 1LL * b.x * a.z;
}

int sign[111111];
int n;
int main(){
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	for (int i = 1;i <= n; i++)
		scanf("%d%d%d", &po[i].x, &po[i].y, &po[i].z);
	for (int i = 1;i <= n; i++)
		sign[i] = i;
	int tot_ans = 0;
	for (int i = 1; i <= n;i++)
	{
		now = i;
		sort(sign + 1, sign + n + 1, cmp);
		int num = 1;
		while (num < n && po[sign[1 + num]].x == po[now].x &&
						  po[sign[1 + num]].y == po[now].y &&
						  po[sign[1 + num]].z == po[now].z)
			num++;
		int cnt = min(1 + num, n);
		tot_ans = max(tot_ans, cnt);
		for (int j = num + 2; j <= n;j++)
		{
			if (on_the_same_line(po[now], po[sign[j]],po[sign[j - 1]]))
				cnt++;
			else
				cnt = min(1 + num, n);
			tot_ans = max(tot_ans, cnt);
		}
	}
	printf("%d\n", tot_ans);
}
