#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define PII pair<int, int>
using namespace std;
struct que
{
	PII a[100010];
	int head, tail;
	que() {head = tail = 0; memset(a, 0, sizeof(a));}
	bool empty() {return head == tail;}
	PII back() {return a[tail - 1];}
	PII front() {return a[head];}
	void push_back(PII x) {a[tail ++] = x;}
	void pop_back() {tail --;}
	void pop_front() {head ++;}
	void clear() {head = tail = 0;}
};
int a[100005];
que qmin, qmax;
int get_min()
{
	if (qmin.empty()) return 0x3f3f3f3f;
	return qmin.front().second;
}
int get_max()
{
	if (qmax.empty()) return -0x3f3f3f3f;
	return qmax.front().second;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int n, i, j, k, l, m;
		scanf("%d%d", &n, &m);
		m --;
		for (i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		qmin.clear(); qmax.clear();
		int RIGHT = 1;
		long long ans = 0;
		for (int LEFT = 1; LEFT <= n; ++ LEFT)
		{
			while (!qmin.empty() && qmin.front().first < LEFT) qmin.pop_front();
			while (!qmax.empty() && qmax.front().first < LEFT) qmax.pop_front();
			int cur_min = get_min(), cur_max = get_max();
			while (RIGHT <= n && max(cur_max, a[RIGHT]) - min(cur_min, a[RIGHT]) <= m)
			{
				while (!qmin.empty() && qmin.back().second >= a[RIGHT]) qmin.pop_back();
				qmin.push_back(PII(RIGHT, a[RIGHT]));
				while (!qmax.empty() && qmax.back().second <= a[RIGHT]) qmax.pop_back();
				qmax.push_back(PII(RIGHT, a[RIGHT]));
				cur_min = get_min(), cur_max = get_max();
				//printf("*** %d %d\n", cur_min, cur_max);
				RIGHT ++;
			}
			//printf("%d : %d\n", LEFT, RIGHT);
			ans += RIGHT - LEFT;
		}
		cout << ans << endl;
	}
}

