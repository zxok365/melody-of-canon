#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const long long N = 205;

long long n;

struct Point {
	long long x, y, z;

	Point () {}

	Point (long long x, long long y, long long z) :
		x(x), y(y), z(z) {}

	void read() {
		scanf("%lld %lld %lld", &x, &y, &z);
	}
} p[N];

long long eq(const Point &a, const Point &b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

long long dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point det(const Point &a, const Point &b) {
	return Point(a.y * b.z - a.z * b.y, 
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x);
}

int main() {
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		p[i].read();
	}

	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}

			Point now = det(p[i], p[j]);
			long long s1 = 0, s2 = 0, s3 = 0, s4 = 0, s = 0;
			for (long long k = 1; k <= n; k++) {
				if (eq(p[i], p[k])) {
					s++;
					continue;
				}

				long long x = dot(now, p[k]);
				if (x == 0) {
					Point now2 = det(p[i], p[k]);
					long long z = dot(now, now2);
					if (z > 0) {
						s3++;
					} else if (z < 0) {
						s4++;
					}
				} else if (x > 0) {
					s1++;
				} else {
					s2++;
				}
			}

			ans = max(ans, s + max(s1, s2) + max(s3, s4));
		}
	}

	printf("%lld\n", ans);
	return 0;
}

