#include<iostream>
#include<cstdio>
using namespace std;
double pp0,qq0, pp1,qq1;
int p0, q0,p1, q1;
int n, a, b;
int x[1111],y[1111];
long long det(long long a, long long b, long long c,long long d){
	return a * d - b * c;
}

bool in(int p, int q, int r){
	if (q < r)
		return p >= q && p <= r;
	else
		return p <= q && p >= r;
}
bool judge(int p, int q){
	int t = 0;
	long long pp = p, qq = q;
	long long now_x = 11001, now_y = 10011;
	for (int i = 1; i <= n; i++){
		long long  d1 = det(x[i + 1] - x[i], y[i + 1] - y[i], pp - x[i], qq - y[i]);
	//	if (p == 3 && q == 3) cout << d1 << endl;
		if (d1 == 0 && in(p, x[i + 1], x[i]) && in(q, y[i], y[i + 1]))
			return true;
		long long d2 = det(x[i + 1] - x[i], y[i + 1] - y[i], now_x - x[i], now_y - y[i]);
		long long d3 = det(now_x - pp, now_y - qq, x[i] - pp, y[i] - qq);
		long long d4 = det(now_x - pp, now_y - qq, x[i + 1] - pp, y[i + 1] - qq);
		if (1LL * d1 * d2 <= 0 && 1LL * d3 * d4 <= 0) t++;
	}
	return (t % 2);
}
int main(){
	while (scanf("%lf%lf%lf%lf", &pp0, &qq0, &pp1, &qq1) == 4){
		p0 = (int)(pp0 + 0.5);
		q0 = (int)(qq0 + 0.5);
		p1 = (int)(pp1 + 0.5);
		q1 = (int)(qq1 + 0.5);
		scanf("%d%d%d", &n, &a, &b);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &x[i], &y[i]);
		x[n + 1] = x[1];
		y[n + 1] = y[1];
		double ans = 0;
		for (int i = p0; i <= p1;i++)
			for (int j = q0; j<= q1; j++)
				if (judge(i , j)){
					double t = i * a + j * b;
					if (i == p0) t = t * (0. + p0 - pp0 + 0.5);
					if (i == p1) t = t * (0. + pp1 - p1 + 0.5);
					if (j == q0) t = t * (0. + q0 - qq0 + 0.5);
					if (j == q1) t = t * (0. + qq1 - q1 + 0.5);		//		cout << i << ' ' << j << endl;
					ans = ans + t;
				}
		printf("%.3f\n", ans / ((pp1 - pp0) * (qq1 - qq0)));
	}
}
