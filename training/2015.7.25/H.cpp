#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cassert>
#include<cstdlib>
using namespace std;
double a, b, c, d, e, aaa;
const double pi = acos(-1.);
const double eps = 1e-6;
__inline double sqr(const double &x){
	return x * x;
}

struct point{
	double x, y;
	point(){}
	point(double X,double Y)
	{
	 x = X;
	 y = Y;
	}
	__inline point rotate(const double &theta){
		double c = cos(theta), s = sin(theta);
		return point (x * c - y * s, x * s + y * c);
	}
	double len(){
		return sqrt(max(0.,sqr(x) + sqr(y)));
	}
	point unit(){
		double dis = len();
		return point(x / dis,y / dis);
	}
	void outp(){
		printf("%.6f %.6f\n", x, y);
	}
};

__inline point operator+(const point &p, const point &q){
	return point(p.x + q.x,p.y + q.y);
}
__inline point operator-(const point &p, const point &q){
	return point(p.x - q.x, p.y - q.y);
}
__inline point operator*(const point &p, const double &q){
	return point(p.x * q, p.y * q);
}
__inline point operator/(const point &p, const double &q){
	return point(p.x / q, p.y / q);
}
__inline double dis(const point &p, const point &q){
	return sqrt(max(0., sqr(p.x - q.x) + sqr(p.y - q.y)));
}
point A,B,C,D,E,F;
point AA, BB, CC ,DD ,EE ,FF;

__inline double ttry(const double &p,const  double &q){
		if (fabs(p) < eps) return 0;
		double t = (sqr(p) + aaa)/(2 * p * q);
		t = max(t, -1.);
		t = min(t, 1.);
		return acos(t);
}
__inline double check(const double &mid){
	A = point(a, 0.).rotate(mid);
	double theta = ttry(dis(A,F), c);
	D = A - F;
	D = D.rotate(theta);
	D = D.unit() * (c / 2) + F;
	C = F + F - D;
	B = A * (-1);
	return dis(B, C);
}

int main(){
	int test_case;
	scanf("%d", &test_case);
//	assert(test_case <= 50000);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%lf%lf%lf%lf%lf",&a, &b, &c, &d, &e);
		a /= 2;
		c /= 2;
		aaa = c * c - d * d;
		F = point(e, 0);
		E = point(0, 0);
		double tot_ans = 1e7;
		double l = 0;
		double r = pi * 2;
		double now_ans = 1e7;
		int now = 0;
		while (now < 50){
			now++;
			double mid = (r - l) * 0.33;
			double p = check(l + mid);
			double q = check(r - mid);
			if (fabs(p - b)< fabs(q - b))
				r = r - mid;
			else
				l = l + mid;
		}
		now_ans =fabs(check((l + r) / 2) - b);
		if (tot_ans - eps > now_ans){
			tot_ans = now_ans;
		}
		printf("Case #%d:\n", time);
		AA.outp();
		BB.outp();
		CC.outp();
		DD.outp();
	}
}
