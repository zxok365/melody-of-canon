#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
const long double eps = 5e-12;
inline int Sign(long double x) {
	return x < -eps ? -1 : x > eps;
}
inline double Sqr(long double a) {
	return a * a;
}
inline double Sqrt(long double a) {
	return a <= 0 ? 0 : sqrt(a);
}
struct Point {
	long double x, y;
	Point() {}
	Point(long double x, long double y):x(x),y(y){}
	long double Length() const {
		return Sqrt(Sqr(x) + Sqr(y));
	}
	Point Rotate() const {
		return Point(x * .5 - y * .5 * Sqrt(3), x * .5 * Sqrt(3) + y * .5);
	}
	Point Unit() const;
	void Input() {
		cin >> x >> y;
	}
}a[3][2];
Point operator + (const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}
Point operator - (const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}
Point operator * (const Point &a, long double b) {
	return Point(a.x * b, a.y * b);
}
Point operator / (const Point &a, long double b) {
	return Point(a.x / b, a.y / b);
}
Point Point::Unit() const {
	return *this / Length();
}
double Det(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}
double Dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}
int main() {
	srand(time(NULL));
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 2; ++j) {
			a[i][j].Input();
		}
	}
	Point st = a[0][0] + (a[0][1] - a[0][0]).Unit() * (10000000 + rand() % 10000000);
	long double l = -5e7, r = 5e7;
	Point vec = (a[1][1] - a[1][0]).Unit();
	int side1 = Sign(Det(a[2][1] - a[2][0],st + (a[1][0] + vec * l - st).Rotate() - a[2][0]));
	int side2 = Sign(Det(a[2][1] - a[2][0],st + (a[1][0] + vec * r - st).Rotate() - a[2][0]));
	for(int i = 1; i <= 500; ++i) {
		long double mid = (l + r) / 2;
		int cur = Sign(Det(a[2][1] - a[2][0],st + (a[1][0] + vec * mid - st).Rotate() - a[2][0]));
		if (side1 != side2){
		if(cur == side1)
			l = mid;
		else
			r = mid;
		} else {
			side1 = cur;
			l = mid;
		}
	}
	Point ed1 = a[1][0] + (vec * l);
	Point ed2 = st + (ed1 - st).Rotate();
	if (fabs(st.x) > 1e8 || fabs(st.y) > 1e8 || fabs(ed1.x) > 1e8 || fabs(ed2.x) > 1e8 || fabs(ed2.y) > 1e8 || fabs(ed1.y) > 1e8)
		while(1);
//cerr <<Det(a[2][1] - a[2][0], ed2- a[2][0]) << endl;
//cerr << (ed1 - st).Length() << " " << (ed2 - st).Length() << " " << (ed2 - ed1).Length() << endl;
	printf("%.12f %.12f\n", (double) st.x, (double) st.y);
	printf("%.12f %.12f\n", (double) ed1.x, (double) ed1.y);
	printf("%.12f %.12f\n", (double) ed2.x, (double) ed2.y);
	return 0;
}
