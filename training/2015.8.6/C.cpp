#include<iostream>
#include<cstdio>
using namespace std;
int ans[111111];
int c_10[10];
int num[10];
int up, down;
void calc(int p, int q){
	if (p == 0) return;
	int tot = 0;
	int up = p, down = 0;
	while (p > 0){
		num[++tot] = p % 10;
		p /= 10;
	}
	for (int i = 1; i <= tot; i++){
		up /= 10;
		for (int j = 1; j <= 9; j++)
			if (j < num[i]) ans[j] += c_10[i - 1] * (up + 1) * q;
			else if (j > num[i]) ans[j] += c_10[i - 1] * up * q;
			else{
				ans[j] += c_10[i - 1] * up * q + (down + 1)* q;
			}
		if (num[i] != 0)
			ans[0] += c_10[i - 1] * up * q;
		else
		{
			if (up != 0)
				ans[0] += c_10[i - 1] * (up - 1) * q + (down + 1) * q;
		}
		down = down + c_10[i - 1] * num[i];
	}
}
int main(){
	c_10[0] = 1;
	for (int i = 1; i <= 9; i++) c_10[i] = c_10[i - 1] * 10;
	while (1){
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b)swap(a, b);
		for (int i = 0; i <= 9; i++) ans[i] = 0;
		if (a == 0 || b == 0) break;
		calc(b, 1);
		calc(a - 1, -1);
		for (int i = 0; i < 9; i++) printf("%d ", ans[i]);
		printf("%d\n",ans[9]);
	}

}
