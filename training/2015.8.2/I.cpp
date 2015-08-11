#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long n;
int m, a, b, s, t;
unsigned long long f[1111], p[1111];
bool ttry(int a, int s){
	int now = s - a;
	for (int i = 1; i <= now; i++)
		f[i] = i;
	for (int j = 1; j <= a; j++)
	{
		p[1] = 1;
		for (int k = 2; k <= now + j; k++)
			p[k] = p[k - 1] + f[k - 1];
		for (int k = 2; k <= now + j; k++)
		{
			if (p[k] > n || p[k] <= p[k - 1] || f[k - 1] >= p[k])
				return false;
		}
		for (int k = 1; k <= now + j; k++)
			f[k] = p[k];
	}
	for (int i = 1; i <= s;i++) if (f[i] > n) return false;
	return true;
}
int main(){
	//	cout << ((1ULL << 63LL) - 1 +  (1ULL << 63LL)) << endl;
	int times = 0;
	while (cin >> n){
			times ++;
			if (times != 1) printf("\n");
			scanf("%d%d%d%d", &a, &b, &s, &t);
			bool bo = ((unsigned long long)s <= n);
			if (bo) bo = ttry(a, s);
			if (bo == false)
				printf("-1\n");
			else
			{
				for (int i = 1; i < s; i++)
					cout << f[i] << ' ';
				cout << f[s] << endl;
			}


			bo = ((unsigned long long ) t <= n);
			if (bo) bo = ttry(b, t);
			if (bo){
				for (int i = 1; i <= t; i++)
					f[i] = n - f[i] + 1;
			}

			if (bo == false)
				printf("-1\n");
			else
			{
				unsigned long long tmp = n - f[1];
				for (int i = 1; i < t; i++)
					cout << f[i] + tmp << ' ';
				cout << f[t] + tmp << endl;
			}

		}
}
