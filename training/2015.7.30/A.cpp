#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x[11],y[11];
double sqr(double x){
	return x * x;
}
double dis(int p, int q){
	return sqrt(sqr(x[p] - x[q]) + sqr(y[p] - y[q]));
}
int main(){
	while (scanf("%d%d", &x[1],&y[1]) == 2){
		for (int i = 2; i <= 4; i++)
			scanf("%d%d", &x[i], &y[i]);
		double ans = min(dis(1,2) + dis(3,4), dis(1,3) + dis(2,4));
		ans = min(ans, dis(1,4) + dis(2,3));
		printf("%.10f\n", ans);
	}
	

}
