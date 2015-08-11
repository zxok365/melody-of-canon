#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int n;
char str1[111], str2[111];
int main(){
	scanf("%d", &n);
	for (int time = 1; time <= n; time++)
	{
		scanf("%s", str1);
		scanf("%s", str2);
		int len = (int)strlen(str1);
		int a = 0, b = 0, c = 0, d = 0, k = 0;
		int ans = 0;
		for (int i = 0; i < len; i++)
		{
			if (str1[i] == '1' && str2[i] == '0') a++;
			if (str1[i] == '?' && str2[i] == '1') b++;
			if (str1[i] == '?' && str2[i] == '0') c++;
			if (str1[i] == '0' && str2[i] == '1') d++;
			//k = b + d - a;
		}
		k = b + d - a;
		if (k < 0) ans = -1; else
		{
			ans = ans + c;
			int e = min(b, k);
			b -= e;
			k -= e;
			ans += e;
			if (b == 0) ans += d; else ans += a + b;
		}
		printf("Case %d: %d\n", time, ans);
	}
}
