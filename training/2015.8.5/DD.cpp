#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;

const double eps = 1e-8;
const int maxn = 1000;
const int maxf = maxn * 10;
inline int Sign(double a) {
	return a < -eps ? -1 : a > eps;
}
inline double Sqrt(double a)  {
	return a <= 0 ? 0 :sqrt(a);
}
inline double Sqr(double a){
	return a * a;
}

struct Point}{
	double x, y ,;
	Point(){
	}
	Point (double x, double y, double z) : x(x), y(y), z(z){
	}
	void Input(){
		scanf("%lf %lf %lf", &x, &y, &z);
	}

}


