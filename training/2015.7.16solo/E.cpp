#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define x first
#define y second
pair<int, int> p[111111];
pair<pair<int, int>, int> line[111111];

int c[1111111];
int tot;
int n, m;
int maxx, maxy;
int ans;
bool cmp1(const pair<int, int> &pp,const pair<int, int> &qq){
	if (pp.y != qq.y) return pp.y < qq.y;
	return pp.x < qq.x;
}


int find(int u){
	int t = 0;
	for (int i = u; i >= 1; i -= i & (-i)) t = t + c[i];
	if (t > 0) ans = ans + t;
	return t;
}

void insert(int u, int v){
	for (int i = u; i<= maxy;i += i & (-i)) c[i] += v;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1);
	maxx = 1;
	for (int i = 2; i <= n; i++)
	{
		if (p[i].x != p[i - 1].x)
		{
			p[i - 1].x = maxx;
			maxx++;
		}
		else p[i - 1].x = maxx;
	}
	p[n].x = maxx;	
	sort(p + 1, p + n + 1, cmp1);
	maxy = 1;
	for (int i = 2; i <= n; i++)
	{
		if (p[i].y != p[i - 1].y)
		{
			p[i - 1].y = maxy;
			maxy++;
		}
		else p[i - 1].y = maxy;
	}
	p[n].x = maxy;
	maxx += 10;
	maxy += 10;
	
	sort(p + 1, p + n + 1);
	insert(1, -10000000);
	p[0].x = 0, p[0].y = 0;
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (p[i].x == p[i - 1].x){
			insert(p[i - 1].y , 1);
			insert(p[i].y + 1, -1);
		} else
		{
			insert(p[i].y, 1);
			insert(p[i].y + 1, -1);
		}
		int t = find(p[i].y + 1);
		insert(p[i].y, t);
		insert(p[i].y + 1, -t);
	}
	printf("%d\n", ans);
/*	line[1].y = p[1].y;
	line[1].x.x = p[1].x;
	int now_r = p[1].x;
	tot = 1;
	for (int i = 2; i <= n; i++)
	{
		if (p[i].y != p[i - 1].y){
			line[tot].x.y = now_r;
			line[++tot].y = p[i].y;
			line[tot].x.x = p[i].x;
			//now_r = p[i].x;
		}
		now_r = p[i].x;
	}
	line[tot].x.y = now_r;
	for (int i = 1; i <= tot;i++)
	{
		insert(line[tot].x.x, line[tot].y + 1, 1);
		insert(line[tot].x.y + 1, line[tot].y + 1, -1);
	}
	sort(p + 1, p + n + 1);
	int now_x = p[1].x;
	int now_down = p[1].y;
	int now_up = p[1].y;
	for (int i = 2; i <= n; i++)
	{
		if (p[i].x != p[i - 1].x)
		{
			ans = ans + find(now_x, now_up + 1) - find(now_x, now_down);
			now_x = p[i].x;
			now_down = p[i].y;
			now_up = p[i].y;
		}
		else{
			now_up = p[i].y;
		}		
	}*/
	
	
	printf("%d\n", ans);
}
