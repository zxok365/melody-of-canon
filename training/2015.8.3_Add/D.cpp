#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n, k;
set<int> s[3];
int a[111];
int tail;
void ttry(int p, int q, int r, int kk){
	s[kk].insert(r);
	if (p > q || r > k) return;
//	s[kk].insert(r);
	ttry(p + 1, q, r,kk);
	ttry(p + 1, q, r + a[p],kk);
	ttry(p + 1, q, r + a[p] * 2,kk);
}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d %d", &n, &k);
		s[1].clear(),s[2].clear();
		for (int i = 1; i <= n ;i++)
			scanf("%d", &a[i]);
		s[1].insert(0), s[2].insert(0);
		ttry(1, n / 2, 0, 1);
		ttry(n / 2 + 1,n, 0, 2);
		bool bo = false;
		for (set<int>::iterator i = s[1].begin(); i != s[1].end(); i++)
		{
		//	cout << (*i) << endl;
			if (s[2].count(k - (*i)))
			{
				bo = true;
				break;
			}
		}
		if (bo)
			printf("Case %d: Yes\n", time);
		else
			printf("Case %d: No\n", time);
	}
}

