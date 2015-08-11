#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-7;

inline int sign(double x) { return x < -eps ? -1 : x > eps; }
inline double sqr(double x) { return x * x; }

struct point{
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
} p[505], tmp[505];

inline bool operator== (const point &a, const point &b) {
	return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
}
inline bool operator!= (const point &a, const point &b) {
	return fabs(a.x - b.x) > eps || fabs(a.y - b.y) > eps;
}
inline bool operator< (const point &a, const point &b) {
	if (fabs(a.x - b.x) > eps) 
		return a.x < b.x;
	return a.y + eps < b.y;
}
inline point operator+ (const point &a, const point &b) {
	return point(a.x + b.x, a.y + b.y);
}
inline point operator- (const point &a, const point &b) {
	return point(a.x - b.x, a.y - b.y);
}
inline point operator* (const point &a, const double &b) {
	return point(a.x * b, a.y * b);
}
inline point operator/ (const point &a, const double &b) {
	return point(a.x / b, a.y / b);
}
inline double det(const point &a, const point &b) {
	return a.x * b.y - b.x * a.y;
}
inline double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;	
}
struct line {
	point s, t;
	line(point s = point(), point t = point()) : s(s), t(t) {}
} l[505];
inline bool point_on_line(const point &a, const line &b) {
	return sign(det(a - b.s, b.t - b.s)) == 0 && dot(b.s - a, b.t - a) < eps;
}
inline bool two_side(const point &a, const point &b, const line &c) {
	return sign(det(a - c.s, c.t - c.s)) * sign(det(b - c.s, c.t - c.s)) < 0;
}
inline point line_intersect(const line &a, const line &b) {
	double s1 = det(a.t - a.s, b.s - a.s);
	double s2 = det(a.t - a.s, b.t - a.s);
	return (b.s * s2 - b.t * s1) / (s2 - s1);
}

int n;
double u, v;

int main() {
	int test = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= n; i ++) {
			scanf("%lf%lf", &u, &v);
			p[i] = point(u, v);
		}
		int ans = 0;
		test ++;
		for (int i = 1; i < n; i ++) l[i] = line(p[i], p[i + 1]);
		for (int i = 2; i <= n - 1; i ++) {
			int sum = 0;
			for (int j = 1; j < i; j ++) {
				if (point_on_line(p[i + 1], l[j])) tmp[++sum] = p[i + 1];
				else
				if (point_on_line(p[j],l[i]) && p[j] != p[i]) tmp[ ++sum] = p[j];
				else {
						if (two_side(p[i], p[i + 1], l[j]) && two_side(p[j], p[j + 1], l[i])) tmp[++sum] = line_intersect(l[i], l[j]);
					}
	//			cout << sum << ' ' << tmp[sum].x << ' ' << tmp[sum].y << endl;
			}
			if (sum == 0) continue;
	//		cout << ans << endl;
			sort(tmp + 1, tmp + sum + 1);
			ans ++;
			for (int t = 2; t <= sum; t ++) if (tmp[t] != tmp[t - 1]) ans++;
	//		cout << i << ' ' << ans << endl;
		}
		printf("Case %d: There are %d pieces.\n", test, ans + 1);
	}
	return 0;
}
