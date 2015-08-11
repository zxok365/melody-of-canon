#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-7;

int n;
int x[40005], y[40005];
long long a, b, aa, bb, ab, ac, bc, c, cc;
long double num[10][10], ans1, ans2, ans3;

void Gauss() {
	for (int i = 1; i <= 2; i ++) {
		for (int k = i + 1; k <= 3; k ++) {
			long double bei = num[k][i] / num[i][i];
			for (int j = i; j <= 4; j ++) num[k][j] -= num[i][j] * bei;
		}
		
	}
	for (int i = 3; i >= 2; i --) {
		for (int k = i - 1; k >= 1; k --) {
			long double bei = num[k][i] / num[i][i];
			for (int j = i; j <= 4; j ++) num[k][j] -= num[i][j] * bei;
		}
	}
	ans1 = num[1][4] / num[1][1];
	ans2 = num[2][4] / num[2][2];
	ans3 = num[3][4] / num[3][3];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int x, y;
		scanf("%d%d", &x, &y);
		num[1][1] += 2 * x * x;
		num[1][2] += 2 * x * y;
		num[1][3] += 2 * x;
		num[1][4] += - x * x * x - x * y * y;
		
		num[2][1] += 2 * x * y;
		num[2][2] += 2 * y * y;
		num[2][3] += 2 * y;
		num[2][4] += - x * x * y - y * y * y;

		num[3][1] += 2 * x;
		num[3][2] += 2 * y;
		num[3][3] += 2;
		num[3][4] += - x * x - y * y;
	}
	num[1][4] *= 2.0;
	num[2][4] *= 2.0;
	num[3][4] *= 2.0;
	/*
	num[1][1] = 2.0 * aa;
	num[1][2] = ab;
	num[1][3] = ac;
	num[1][4] = -a;

	num[2][1] = ab;
	num[2][2] = 2.0 * bb;
	num[2][3] = bc;
	num[2][4] = -b;

	num[3][1] = ac;
	num[3][2] = bc;
	num[3][3] = 2.0 * cc;
	num[3][4] = -c;*/

//	for (int i = 1; i <= 3; i ++) {
//		for (int j = 1; j <= 4; j ++) printf("%.3f ", (double)num[i][j]);
//		cout << endl;
//	}

	Gauss();

	printf("%.6f %.6f %.6f\n", (double)ans1, (double)ans2, (double)ans3);

	return 0;
}
