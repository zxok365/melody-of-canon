#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define x1 XXX1
#define x2 XXX2
#define y1 YYY1
#define y2 YYY2

using namespace std;

const int N = 50005;

int n, xNow;
int x1[N], y1[N], x2[N], y2[N];
vector <pair <pair <int, int>, int> > v;

struct Point {
	int x, y;

	Point (int x = 0, int y = 0):
		x(x), y(y) {}
	
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
};

int cmp(double x, double y) {
	return x < y - 1e-8 ? -1 : x > y + 1e-8;
}

struct SET {
	int first, second;

	SET (int first = 0, int second = 0) :
		first(first), second(second) {}

	friend bool operator < (const SET &a, const SET &b) {
		double y1 = (double)x1[a.second] + (double)(xNow - x1[a.second]) * (double)(y2[a.second] - y1[a.second]) / (double)(x2[a.second] - x1[a.second]);
		double y2 = (double)x1[b.second] + (double)(xNow - x1[b.second]) * (double)(y2[b.second] - y1[b.second]) / (double)(x2[b.second] - x1[b.second]);
		return cmp(y1, y2) < 0 || (cmp(y1, y2) == 0 && a.second < b.second);
	}
};

set <SET> s;

int sign(int x) {
	return x < 0 ? -1 : x > 0;
}

int det(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

int dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

int inRange(int a, int p1, int p2) {
	return a >= p1 && a <= p2;
}

int inLine(const Point &x, const Point &p1, const Point &p2) {
	int k = det(x - p1, p2 - p1);
	return k == 0 && inRange(x.x, p1.x, p2.x) && inRange(x.y, p1.y, p2.y);
}

int isIntersect(const Point &p1, const Point &p2, const Point &q1, const Point &q2) {
	int k1 = det(p2 - p1, q1 - p1), k2 = det(p2 - p1, q2 - p1);
	int k3 = det(q2 - q1, p1 - q1), k4 = det(q2 - q1, p2 - q1);
	if (k1 * k2 == -1 && k3 * k4 == -1) {
		return 1;
	}

	if (inLine(p1, q1, q2) || inLine(p2, q1, q2) || inLine(q1, p1, p2) || inLine(q2, p1, p2)) {
		return 1;
	}

	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if (x1[i] > x2[i]) {
			swap(x1[i], x2[i]);
			swap(y1[i], y2[i]);
		}

		v.push_back(make_pair(make_pair(x1[i], 0), i));
		v.push_back(make_pair(make_pair(x2[i], 1), i));
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); i++) {
		xNow = v[i].first.first;
		Point p1 = Point(x1[v[i].second], y1[v[i].second]), p2 = Point(x2[v[i].second], y2[v[i].second]);
		if (v[i].first.second == 0) {
			set <SET> :: iterator it = s.lower_bound(SET(p1.y, v[i].second));
			if (it != s.end()) {
				int now = it->second;
				if (isIntersect(p1, p2, Point(x1[v[now].second], y1[v[now].second]), Point(x2[v[now].second], y2[v[now].second]))) {
					printf("YES\n");
					printf("%d %d\n", v[i].second, now);
					return 0;
				}

				if (it != s.begin()) {
					--it;
					int no2 = it->second;
					if (isIntersect(Point(x1[v[now].second], y1[v[now].second]), Point(x2[v[now].second], y2[v[now].second]), 
									Point(x1[v[no2].second], y1[v[no2].second]), Point(x2[v[no2].second], y2[v[no2].seocnd])) {
						printf("YES\n");
						return 0;
					}

					++it;
				}
			}

			if (it != s.begin()) {
				--it;
				int now = it->second;
				if (isIntersect(p1, p2, Point(x1[v[now].second], y1[v[now].second]), Point(x2[v[now].second], y2[v[now].second]))) {
					printf("YES\n");
					printf("%d %d\n", v[i].second, now);
					return 0;
				}
			}
			
			s.insert(make_pair(p1.y, v[i].second));
		} else {
			s.erase(make_pair(p1.y, v[i].second));
			set <SET> :: iterator it = s.lower_bound(SET(p1.y, v[i].second));
			if (it != s.end()) {
				int now = it->second;
				if (isIntersect(p1, p2, Point(x1[v[now].second], y1[v[now].second]), Point(x2[v[now].second], y2[v[now].second]))) {
					printf("YES\n");
					printf("%d %d\n", v[i].second, now);
					return 0;
				}

				if (it != s.begin()) {
					--it;
					int no2 = it->second;
					if (isIntersect(Point(x1[v[now].second], y1[v[now].second]), Point(x2[v[now].second], y2[v[now].second]), 
									Point(x1[v[no2].second], y1[v[no2].second]), Point(x2[v[no2].second], y2[v[no2].seocnd])) {
						printf("YES\n");
						return 0;
					}

					++it;
				}
			}

			if (it != s.begin()) {
				--it;
				int now = it->second;
				if (isIntersect(p1, p2, Point(x1[v[now].second], y1[v[now].second]), Point(x2[v[now].second], y2[v[now].second]))) {
					printf("YES\n");
					printf("%d %d\n", v[i].second, now);
					return 0;
				}
			}
		}
	}

	
	printf("NO\n");
	return 0;
}

