#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[105][105], f[105][105];
int dx[5], dy[5];

pair<int, pair<int, int> > p[10005];

bool finall(int x, int y) {
	for (int k=1; k<=4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]>a[x][y]) return false;
	}
	return true;
}

bool start(int x, int y) {
	for (int k=1; k<=4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]<a[x][y]) return false;
	}
	return true;
}

int main() {
	dx[1]=1;dx[2]=0;dx[3]=-1;dx[4]=0;
	dy[1]=0;dy[2]=1;dy[3]=0;dy[4]=-1;
	int test;
	scanf("%d", &test);
	int tot=0;
	while (test--) {
		tot++;
		scanf("%d%d", &n, &m);
		int sum=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++) {
				scanf("%d", &a[i][j]);
				f[i][j]=0;
				p[++sum]=make_pair(a[i][j], make_pair(i, j));
			}
		sort(p+1, p+sum+1);
		for (int i=1; i<=sum; i++) {
			pair<int, int> cur=p[i].second;
			if (start(cur.first, cur.second)) f[cur.first][cur.second]=1;
			for (int k=1; k<=4; k++) {
				int nx=cur.first+dx[k];
				int ny=cur.second+dy[k];
				if (nx>=1&&nx<=n&&ny>=1&&ny<=m) 
					if (a[nx][ny]<a[cur.first][cur.second]) 
						f[cur.first][cur.second]+=f[nx][ny];				
			}
		}
		int ans=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++) if (finall(i, j)) ans+=f[i][j];
		printf("Case #%d: %d\n", tot, ans);
	}
	return 0;
}
