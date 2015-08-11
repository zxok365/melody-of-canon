#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int> Q;
int n, x, y, h1, h2;
long long now;
int s;
int ans;
int main(){
	scanf("%d%d%d%d%d", &n, &x, &y, &h1, &h2);
	int times = (h2 + x - 1)/ x;
	now = h1;
	bool bo = false;
	int s_max = 0;
	//cout << '!' << endl;
	for (int i = 1; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		Q.push(p);
		s++;
		s_max = max(s, s_max);
		now = now - p;
		if (s >= times){
			bo = true;
			ans = i;
			break;
		}
		while(now <= 0)
		{
			int t = Q.top();
			now = now + t + max(0, y - t);
			Q.pop();
			s--;
		}
	}
	if (bo == true)
	{
		printf("Win\n");
		printf("%d\n", ans);
	}
	else
	{
		printf("Lose\n");
		cout << x * s_max << endl;
	}
}
