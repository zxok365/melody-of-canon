#include<iostream>
#include<cstdio>
#define x first
#define y second
using namespace std;
pair<long long , long long > p[21111];
bool bo[21111];
long long minx, miny, maxx, maxy;
pair<long long, long long> num[10];
int n;



bool judge(long long d, long long x1, long long y1, long long x2, long long y2){
	for (int i = 1; i <= n; i++)
	if (!bo[i]){
		if (p[i].x >= x1 && p[i].x <= x1 + d && p[i].y >= y1 && p[i].y <= y1 + d) continue;
		if (p[i].x >= x2 && p[i].x <= x2 + d && p[i].y >= y2 && p[i].y <= y2 + d) continue;
		return false;
	}
	return true;
}
bool check(long long d){
	num[1] = make_pair(minx, miny);
	num[2] = make_pair(maxx - d, miny);
	num[3] = make_pair(minx, maxy - d);
	num[4] = make_pair(maxx - d, maxy - d);
	for (int times = 1; times <= 4; times++)
	{
		for (int i = 1; i <= n; i++) bo[i] = false;
		long long lt = num[times].x, rt = num[times].x + d;
		long long up = num[times].y + d, down = num[times].y;
		for (int i = 1; i <= n; i++)
			if (p[i].x >= lt && p[i].x <= rt &&
				p[i].y >= down && p[i].y <= up)
			bo[i] = true;
		long long ix = 1e10, iy = 1e10, ax = -1e10 - 10, ay = -1e10;
		for (int i = 1; i <= n; i++)
		if (!bo[i]){
			ix = min(ix, p[i].x);
			iy = min(iy, p[i].y);
			ax = max(ax, p[i].x);
			ay = max(ay, p[i].y);
		}
		if (judge(d, ix, iy, ax - d, ay - d) ||	judge(d, ix, ay - d, ax - d, iy)) return true;
	}
	return false;
}
int main(){
	scanf("%d", &n);
	minx = miny = 1e10;
	maxx = maxy = -1e10;
	for (int i = 1; i <= n; i++)
	{
		int pp, qq;
		scanf("%d%d", &pp, &qq);
		p[i].x = pp, p[i].y = qq;
		minx = min(minx, p[i].x);
		miny = min(miny, p[i].y);
		maxx = max(maxx, p[i].x);
		maxy = max(maxy, p[i].y);
	}
	long long l = 0, r = max(maxx - minx, maxy - miny);
	while (l + 1 < r){
		long long mid = (l + r) >> 1LL;
		if (!check(mid)) l = mid; else r = mid;
	}
	cout << r << endl;
}
