#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
	int x, y, c;
	point(){}
	point(int x, int y, int c): x(x), y(y), c(c){}
	void outp(){
		cout << x << ' ' << y << ' ' << c << endl;
	}
} p[111111];


inline point operator+(const point &a, const point &b){
	return point(a.x + b.x, a.y + b.y, 0);
}

inline point operator-(const point &a, const point &b){
	return point(a.x - b.x, a.y - b.y, 0);
}

inline long long det(const point &a, const point &b){
	return 1LL * a.x * b.y -1LL * a.y * b.x;
}

inline int dot(const point &a, const point &b){
	return a.x * b.x + a.y * b.y;
}

int current[1111111];
int n, m, now;
int now_ans,tot_ans, now_0;
const double eps = 1e-4;

inline bool cmp(const int &a, const int &b){
	if (p[a].x == p[now].x && p[a].y == p[now].y) return true;
	if (p[b].x == p[now].x && p[b].y == p[now].y) return false;
	double a1 = atan2(p[a].y - p[now].y, p[a].x - p[now].x);
	double a2 = atan2(p[b].y - p[now].y, p[b].x - p[now].x);
	if (fabs(a1 - a2) > eps) return a1 < a2;
	return p[a].c > p[b].c;
}
int main(){
	while (1){
		scanf("%d", &n);
		if (n == 0) return 0;
		now_0 = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
			if (p[i].c == 0) now_0++;
		}
		now = 0;
		tot_ans = 0;
		for (int i = 1; i <= n; i++)
			current[i] = i;
		for (int i = 1; i <= n; i++)
		{
			now = i;
			sort(current + 1, current + n + 1, cmp);
			for (int j = 2;j <= n; j++)
				current[j + n - 1] = current[j];
			int nnow = 1;
			now_ans = now_0 + p[now].c;
			int fnow = 0;
			for (int j = 2;j <= n; j++)
			{
				point t1 = p[current[nnow + 1]] - p[now];
				point t2 = p[current[j]] - p[now];
				long long pp = det(t1,t2);
				while (nnow < n + j - 2 && pp <= 0)
				{
					nnow++;
					if (p[current[nnow]].c == 1) now_ans = now_ans + 1; else now_ans = now_ans - 1;
					if (pp == 0 && p[current[nnow]].c == 0) fnow++;
					t1 = p[current[nnow + 1]] - p[now];
					t2 = p[current[j]] - p[now];
					pp = det(t1,t2);
				}
	//			cout << j << ' ' << nnow << ' ' << now_ans << ' ' << fnow<< endl;
				if (tot_ans < fnow + now_ans) tot_ans = fnow + now_ans;
				if (det(p[current[j + 1]] - p[now], p[current[j]] - p[now]) != 0) fnow = 0;
				if (p[current[j]].c == 1) now_ans = now_ans - 1; else now_ans = now_ans + 1;
			}
		}
		printf("%d\n", tot_ans);
	}
}
