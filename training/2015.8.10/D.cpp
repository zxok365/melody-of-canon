#include<iostream>
#include<cstdio>
using namespace std;
int n, m;
const long long Mo = 1000000007;
int f[41][41][5][5][5][5][3];

int judge2(int a, int b, int c, int d){
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		if (a != i && b != i && c != i && d != i) ans++;
	return ans;
}

bool judge(int a, int b, int c, int d){
	return a != b && a != c && a != d;
}
int ttry(int x, int y, int a1, int a2, int a3, int a4, int z){
	int& now = f[x][y][a1][a2][a3][a4][z];
	long long ans = 0;
	if (now != -1) return now;
	if (z == 1){
		if (x == 1)
		{
			now = judge2(a1, a2, a3, a4);
			return now;
		}
		ans = judge2(a1, a2, a3, a4);
		for (int i = 1; i <= x - 1; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				if (judge(j, a1, a2, a4))
				{
					ans += ttry(x - i, y, j, a2, a3, a4, 2);
					ans = ans - judge2(j, a2, a3, a4);
				}
				if (judge(j, a2, a3, a4))
					ans += ttry(i, y, a1, a2, j, a4, 2);
			}
		}
		ans = (ans + Mo) % Mo;
		now = ans;
		return ans;
	} else
	{
		if (y == 1){
			now = judge2(a1, a2, a3, a4);
			return now;
		}
		ans = judge2(a1, a2, a3, a4);
		for (int i = 1; i <= y - 1; i++)
		{
			for (int j = 1; j <= 4;j ++)
			{
				if (judge(j, a1, a2, a3))
				{
					ans += ttry(x, y - i, a1, j, a3, a4, 1);
					ans = ans - judge2(j, a1, a3, a4);
				}
				if (judge(j, a1, a3, a4))
					ans += ttry(x, i, a1, a2, a3, j, 1);
			}
		}
		ans = (ans + Mo) % Mo;
		now = ans;
		return ans;
	}
}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int i = 1; i <= 40; i++)
		for (int j = 1; j <= 40; j++)
			for (int a1 = 0; a1 <= 4; a1++)
				for (int a2 = 0; a2 <= 4; a2++)
					for (int a3 = 0; a3 <= 4; a3++)
						for (int a4 = 0; a4 <= 4; a4++)
							f[i][j][a1][a2][a3][a4][1] = f[i][j][a1][a2][a3][a4][2] = -1;
	for (int time = 1; time <=test_case; time++)
	{
		scanf("%d%d", &n, &m);
		cout << ttry(n, m, 0, 0, 0, 0, 1) << endl;
	}

}
