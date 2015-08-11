#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int x[10], y[10];
double now_x[10], now_y[10];
double p_x[10],p_y[10], p_z[10];
double t[10];
const double eps = 1e-10;
const double eps2 = 2e-8;

inline double sqr(double x){ return x * x;}
double dis(double p, double q){
	double ans = 0, max_ans = 0;
	for (int i = 1; i <= 3; i++)
	{
		double t = sqrt(sqr(x[i] - p) + sqr(y[i] - q));
		ans = ans + t * 2;
		max_ans = max(max_ans, t);
	}
	return ans - max_ans;
}
double dis2(int i, int j){
	return sqr(now_x[i] - now_x[j]) + sqr(now_y[i] - now_y[j]);
}
bool check(){
	return dis2(1, 2) < eps2 * eps2 && dis2(2, 3) < eps2 * eps2 && dis2(1,3) < eps2 * eps2;
}

int main(){
	int test_case = 0;
	bool bo;
	while (1){
		bo = true;
		for (int i = 1; i <= 3; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			now_x[i] = x[i];
			now_y[i] = y[i];
			if (now_x[i] > 0 || now_y[i] > 0) bo = false;
		}
		if (bo) break;
		while (!check()){
			double mid_x = (now_x[1] + now_x[2] + now_x[3]) / 3;
			double mid_y = (now_y[1] + now_y[2] + now_y[3]) / 3;
			double tot_ans = 0;
			int now = 1;
			for (int i = 1; i <= 3; i++)
			{
				p_x[i] = (mid_x + now_x[i]) / 2;
				p_y[i] = (mid_y + now_y[i]) / 2;
				p_z[i] = dis(p_x[i], p_y[i]);
				if (tot_ans + eps < p_z[i])
				{
					tot_ans = p_z[i];
					now = i;
				}
			}
	//		cout << mid_x << ' ' << mid_y << endl;
			now_x[now] = p_x[now];
			now_y[now] = p_y[now];
		}
		printf("Case %d: %.9f\n",++test_case, dis(now_x[1], now_y[1]));
	}
}
