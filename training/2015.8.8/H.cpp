#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define y1 y123412
#define x1 asdads

const double eps = 1e-8;
const double pi = acos(-1.);
double x[1005], y[1005], r[1005];
double x1, y1, r1, ans;
int n;
vector<pair<double, int> > g[1005];

double sqr(double x) {
	return x * x;
}

double calc(int u, int v) {
	double a = r1 + r[u];
	double b = sqrt(sqr(x[u] - x[v]) + sqr(y[u] - y[v]));
	double c = r1 + r[v];
	return acos((sqr(a) + sqr(b) - sqr(c))/ (2.0 * a *b));
}

double myatan2(double p, double q){
	double t = atan2(p, q);
	if (t < -eps) t = 2 * pi - t;
	return t;
}
pair<double, int> find(int num, double ang) {
	vector<pair<double, int> > :: iterator it = lower_bound(g[num].begin(), g[num].end(), make_pair(ang + eps, -5));
	if (it == g[num].end()) {
		return g[num][0];
	}
	return (*it);
}

double calc2(double ang1, double ang2) {
	if (fabs(ang1 - ang2) < eps) return 2 * pi;
	if (ang1 > ang2) return ang1 - ang2;
		else return 2 * pi - (ang2 - ang1);
}

void walk_on(int x, double now_ang) {
	pair<double, int> next = find(x, now_ang);
	ans += calc2(-next.first, -now_ang) * (r[x] + r1);
	if (next.second == -1) return;
	double nowx = (r[x] + r1) * cos(-next.first);
	double nowy = (r[x] + r1) * sin(-next.first);
	double newang = -(myatan2(nowy - y[next.second], nowx - y[next.second]));
	walk_on(next.second, newang);
}

double check(double x) {
	if (x < -eps) x += 2 * pi;
	if (x > 2 * pi + eps) x -= 2 * pi;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%lf%lf%lf", &x[i], &y[i], &r[i]), sum[i] = 0;
		scanf("%lf%lf%lf", &x1, &y1, &r1);
		int init_num;
		double init_ang;
		for (int i = 1; i <= n; i ++) if (fabs(sqrt(sqr(x[i] - x1) + sqr(y[i] - y1)) - (r1 + r[i])) < eps) {
			++sum[i];
			g[i][sum[i]] = make_pair(-(myatan2(y1 - y[i], x1 - x[i])), -1);
			init_num = i;
			init_ang = -(myatan2(y1 - y[i], x1 - x[i]));
			break;
		}
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) if (j != i) {
				if (sqrt(sqr(x[j] - x[i]) + sqr(y[j] - y[i])) - r[i] - r[j] > r1 - eps) continue;
				double ang = -calc(i, j);
				double ang2 = -(myatan2(y[j] - y[i], x[j] - x[i]));
				++sum[i];
				g[i][sum[i]] = make_pair(check(ang2 + ang), 2 * j);
				g[i][sum[i]] = make_pair(check(ang2 - ang), 2 * j + 1);
			}
		ans = 0;
		for (int i = 1; i <= n; i ++)
			sort(g[i] + 1, g[i] + sum[i] + 1);
		walk_on(init_num, init_ang);
		ans /= pi * r1;
		ans *= 180;
		printf("%.8f\n", ans);
	}
}
