#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-7;

int n;
int x[40005], y[40005];
long double leftr, rightr, leftx, rightx, lefty, righty;

long double sqr(long double a) {
	return a * a;
}

long double check(long double xx,long double yy,long  double r) {
	long double sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += sqr(sqr(xx - x[i]) + sqr(yy - y[i]) - r * r);
	}
	return sum;
}

long double checkx(long double r,long double x) {
	lefty = -1000000;
	righty = 1000000;
	while (righty > lefty + eps) {
		long double mid1 = lefty + (righty - lefty) * 0.45;
		long double mid2 = lefty + (righty - lefty) * 0.55;
		if (check(x, mid1, r) < check(x, mid2, r)) 
			righty = mid2;
		else lefty = mid1;
	}
	return check(x, lefty, r);
}

long double checkr(long double r) {
	leftx = -1000000;
	rightx = 1000000;
	while (rightx > leftx + eps) {
		long double mid1 = leftx + (rightx - leftx) * 0.45;
		long double mid2 = leftx + (rightx - leftx) * 0.55;
		if (checkx(r, mid1) < checkx(r, mid2)) 
			rightx = mid2;
		else leftx = mid1;
	}
	return checkx(r, leftx);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	leftr = 0;
	rightr = 1000000;
	while (rightr > leftr + eps) {
		long double mid1 = leftr + (rightr - leftr) * 0.45;
		long double mid2 = leftr + (rightr - leftr) * 0.55;
		if (checkr(mid1) < checkr(mid2)) {
			rightr = mid2;
		} else leftr = mid1;
	}
	long double a, b, c;
	a = - 2.0 * leftx;
	b = - 2.0 * lefty;
	c = sqr(leftx) + sqr(lefty) - sqr(leftr);
	printf("%.5f %.5f %.5f\n", (double)a, (double)b, (double)c);
	return 0;
}
