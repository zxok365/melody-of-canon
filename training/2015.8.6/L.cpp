#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const double eps = 1e-7;

inline int sign(double x) { return x < -eps ? -1 : x > eps; }
inline double sqr(double x) { return x * x; }

struct point{
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
	inline double norm2() const {
		return x * x + y * y;
	}
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
vector<point> a, conv;

double area(point a, point b, point c) {
	return fabs(det(b - a, c - a)) / 2.0;
}

inline bool turn_left(const point &a, const point &b, const point &c) {
	return det(b - a, c - a) > eps;
}

inline bool turn_right(const point &a, const point &b, const point &c) {
	return det(b - a, c - a) < -eps;
}

inline vector<point> convex_hull(vector<point> a) {
	int n = (int)a.size(), cnt = 0;
	sort(a.begin(), a.end());
	vector<point> ret;
	for (int i = 0; i < n; i ++) {
		while (cnt > 1 && turn_left(ret[cnt - 2], a[i], ret[cnt - 1])) {
			--cnt;
			ret.pop_back();
		}
		ret.push_back(a[i]);
		++cnt;
	}
	int fixed = cnt;
	for (int i = n - 1; i >= 0; i --) {
		while (cnt > fixed && turn_left(ret[cnt -2], a[i], ret[cnt - 1])) {
			--cnt;
			ret.pop_back();
		}
		ret.push_back(a[i]);
		cnt ++;
	}
	return ret;
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == -1) break;
		a.clear();
		for (int i = 0; i < n; i ++) {
			scanf("%lf%lf", &u, &v);
			a.push_back(point(u, v));
		}
		conv = convex_hull(a);
		n = (int)conv.size();
		int first = 0;
		int second = 1;
		int third = 2;
		int time = n;
		double ans = 0;
		while (time --) {
			while ((first + 1) % n != second && area(conv[(first + 1) % n], conv[second], conv[third]) > area(conv[first], conv[second], conv[third]))  
				first = (first + 1) % n;
			while ((third + 1) % n != first && area(conv[(third + 1) % n], conv[first], conv[second]) > area(conv[first], conv[second], conv[third]))
				third = (third + 1) % n;
			ans = max(ans, area(conv[first], conv[second], conv[third]));
			second = (second + 1) % n;
		}
		printf("%.2f\n", ans);
	}
	return 0;
}
