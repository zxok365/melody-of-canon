#include<iostream>
#include<cstdio>
using namespace std;
int n, m,ans;
int f[11111];
void ttry(int x){
	if (x == n + 1){
		int now = 0, tot = 0;
		for (int i = 1; i <= n; i++)
		{
			if (f[i] == 1)
				now = now + 1;
			else
				now = 0;
			tot = max(tot, now);
		}
		if (tot >= m)
		{
	//		for (int i = 1; i <= n; i++) cout << f[i] << ' ';
	//		cout << endl;
			ans++;
		}
		return;
	}
	f[x] = 1;
	ttry(x + 1);
	f[x] = 0;
	ttry(x + 1);
}
int main(){
	for (n = 1; n <= 10; n++)
	{
		for (m = 1; m <= n; m++)
		{
			ans = 0;
			ttry(1);
			printf("%d ", ans);
		}
		cout << endl;
	}
}
