#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct event
{
	int a[2], type, id;
	event(int L = 0, int R = 0, int tt = 0, int ii = 0)
	{
		a[0] = L; a[1] = R;
		type = tt; id = ii;
	}
};
event G[3][100005];
int L[50005], R[50005], ans[50005], cur_VC, Last[50005];
bool cmp(const event &a, const event &b)
{
	if (a.a[cur_VC] != b.a[cur_VC]) return a.a[cur_VC] < b.a[cur_VC];
	if (a.type != b.type) return a.type < b.type;
	return a.id < b.id;
}
void cdq(int L, int R, int VC)
{
	if (L >= R) return;
	//printf("%d %d    %d\n", L, R, VC);
	if (VC == 2)
	{
		int cnt = 0, la = 0, lala = 0;
		for (int i = L; i <= R; ++ i) printf("%d(%d) ", G[VC][i].id, G[VC][i].type);
		for (int i = L; i <= R; ++ i)
		{
			int id = G[VC][i].id;
			if (G[VC][i].type == 1)
			{
				if (ans[id] <= cnt)
				{
					ans[id] = cnt;
					Last[id] = lala;
					printf("ans[%d] = %d   lala = %d\n", id, cnt, lala);
				}
			}
			else
			{
				if (cnt < ans[id])
				{
					cnt = ans[id];
					lala = Last[id];
					la = id;
				}
				else
				{
					lala = la;
					la = id;
				}
				cnt ++;
			}
		}
		return;
	}
	int mid = (L + R) / 2;
	cdq(L, mid, VC);
	int len = 0;
	for (int i = L; i <= mid; ++ i) if (G[VC][i].type == 0) G[VC + 1][++ len] = G[VC][i];
	for (int i = mid + 1; i <= R; ++ i) if (G[VC][i].type == 1) G[VC + 1][++ len] = G[VC][i];
	cur_VC = VC;
	sort(G[VC + 1] + 1, G[VC + 1] + len + 1, cmp);
	cdq(1, len, VC + 1);
	cdq(mid + 1, R, VC);
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 1; i <= n; ++ i) scanf("%d", &L[i]);
		for (int i = 1; i <= n; ++ i) scanf("%d", &R[i]);
		int len = 0;
		reverse(L + 1, L + 1 + n);
		reverse(R + 1, R + 1 + n);
		for (int i = 1; i <= n; ++ i)
		{
			G[0][++ len] = event(L[i], -R[i], 0, i);
			G[0][++ len] = event(L[i], -R[i], 1, i);
		}
		for (int i = 1; i <= n; ++ i)
		{
			ans[i] = 0;
			Last[i] = 0;
		}
		cdq(1, len, 0);
		int A = 0, ind = 0;
		for (int i = 1; i <= n; ++ i)
		{
			if (ans[i] >= A)
			{
				A = ans[i];
				ind = i;
			}
		}
		printf("***%d\n", A);
		for (int i = ind; i; i = Last[i]) printf("%d%c", i, " \n"[Last[i] == 0]);
	}
}


/*
   1 10    0
   1 5    0
   1 3    0
   1 2    0
   1 2    1
   1 2    2
   1 3    1
   1 2    1
   1 3    2
   4 5    0
   1 6    1
   1 3    1
   1 2    1
   1 2    2
   1 6    2
   4 6    1
   4 5    1
   6 10    0
   6 8    0
   6 7    0
   1 2    1
   1 2    2
   1 2    1
   1 2    2
   9 10    0
   1 2    1
   1 2    2
   ***3
   5 2 1
   1 4    0
   1 2    0
   1 2    1
   1 2    2
   1 2    1
   3 4    0
   1 2    1
   1 2    2
   ***1
   2
   1 8    0
   1 4    0
   1 2    0
   1 2    1
   1 2    2
   1 2    1
   1 2    2
   3 4    0
   1 2    1
   1 2    2
   1 4    1
   1 2    1
   3 4    1
   5 8    0
   5 6    0
   1 2    1
   1 2    2
   1 2    1
   1 2    2
   7 8    0
   1 2    1
   1 2    2
   ***1
   4

   */
