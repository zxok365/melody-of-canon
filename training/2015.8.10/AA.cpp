#include<iostream>
#include<cstdio>
using namespace std;
const int add_x[4] = {3, 0, 1, 2};
const int add_y[4] = {0, 1, 2, 3};
int dl[5111111];
long long ans[66666];
int now[66666];
bool in_queue[66666];
int w[1111111],s[66666],y[1111111],z[1111111];
int n, m;
int head, tail;
void add_edge(int u, int v, int val){
	w[++tail] = s[u];
	s[u] = tail;
	y[tail] = v;
	z[tail] = val;
}


inline bool update(int p, long long q, int r){
	if (ans[p] > q)
	{
		ans[p] = q;
		now[p] = r;
		return true;
	}
	if (ans[p] == q && now[p] < r)
	{
		now[p] = r;
		return true;
	}
	return false;
}
inline void add(int p){
	in_queue[p] = true;
	tail++;
	if (tail > 1e7) tail = 1;
	dl[tail] = p;
}
int main(){
	int test_case;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d", &n, &m);
		tail = 0;
		for (int i = 1; i <= 4 * n + 4; i++)
			s[i] = 0;
		for (int i = 1; i <= m; i++)
		{
			int p, q, r, t;
			char ch;
			scanf("%d %d %d %c", &p, &q, &r, &ch);
			p = p * 4 - 3;
			q = q * 4 - 3;
			if (ch == 'L') t = 0;
			if (ch == 'O') t = 1;
			if (ch == 'V') t = 2;
			if (ch == 'E') t = 3;
			add_edge(p + add_x[t], q + add_y[t], r);
			add_edge(q + add_x[t], p + add_y[t], r);
		}
		int st = 4;
		int ed = 4 * n;
		for (int i = 1; i <= 4 * n; i++) ans[i] = 1e15, now[i] = 0, in_queue[i] = false;
		update(st, 0, 0);
		head = 1;
		tail = 0;
		add(st);
		bool bo = true;
		while (head != tail + 1){
			int u = dl[head];
			for (int j = s[u]; j != 0; j = w[j]){
				int v = y[j];
				long long dis = z[j];
				if (update(v, ans[u] + dis, now[u] + (v % 4 == 0))){
					if (!in_queue[v]) add(v);
				}
			}
			in_queue[u] = false;
			if (bo){
				bo = false;
				ans[st] = 1e15;
				now[st] = 0;
			}
			head++;
			if (head > 1e7) head = 1;
		}
		printf("Case %d: ", time);
		if (now[ed] == 0)
			puts("Binbin you disappoint Sangsang again, damn it!");
		else
		{
			printf("Cute Sangsang, Binbin will come with a donkey after travelling ");
			cout << ans[ed] << ends;
			printf(" meters and finding ");
			printf("%d", now[ed]);
			printf(" LOVE strings at last.\n");
		}
	}
}


