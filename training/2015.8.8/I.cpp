#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

#define SIZE(x) ((int)(x).size())

using namespace std;

const int N = 200000;
int M;

int n;
int nodes_count, fail[N];
bool isword[N];
int children[N][26], father[N], value[N];
vector<int> queue;
char buf[N];

inline int new_node(int x)
{
	memset(children[nodes_count], -1, sizeof(children[nodes_count]));
	isword[nodes_count] = false;
	value[nodes_count] = x;
	return nodes_count ++;
}
void bfs()
{
	queue.clear();
	queue.push_back(0);
	fail[0] = father[0] = -1;
	for (int front = 0; front < SIZE(queue); ++ front)
	{
		int x = queue[front];
		for (int itr = 0; itr < M; ++ itr)
		{
			int y = children[x][itr];
			if (y != -1)
			{
				queue.push_back(y);
				father[y] = x;
			}
		}
		if (x > 0)
		{
			int y = fail[father[x]];
			fail[x] = 0;
			while (y > -1)
			{
				if (children[y][value[x]] != -1)
				{
					fail[x] = children[y][value[x]];
					break;
				}
				y = fail[y];
			}
			if (isword[fail[x]])
			{
				isword[x] = true;
			}
		}
	}
}

int next_pos(int x, int itr)
{
	if (children[x][itr] != -1) return children[x][itr];
	int new_x = 0;
	for (int p = fail[x]; p > -1; p = fail[p])
	{
		if (children[p][itr] != -1)
		{
			new_x = children[p][itr];
			break;
		}
	}
	return new_x;
}
vector<int> G[N + 5], rG[N + 5], list;
bool v[N + 5];
int group[N + 5], group_sz[N + 5], new_node_cnt, to_new[N + 5];
void my_new_node(int x)
{
	if (to_new[x]) return;
	new_node_cnt ++;
	to_new[x] = new_node_cnt;
	G[new_node_cnt].clear();
	rG[new_node_cnt].clear();
}
void ae(int x, int y)
{
	G[x].push_back(y);
	rG[y].push_back(x);
}
void my_bfs()
{
	queue.clear();
	queue.push_back(0);
	memset(to_new, 0, sizeof(to_new));
	my_new_node(0);
	memset(v, 0, sizeof(v));
	v[0] = true;
	for (int front = 0; front < SIZE(queue); ++ front)
	{
		int x = queue[front];
		my_new_node(x);
		if (isword[x]) continue;
		for (int i = 0; i < M; ++ i)
		{
			int y = next_pos(x, i);
			my_new_node(y);
			if (!isword[y])
			{
				ae(to_new[x], to_new[y]);
				if (!v[y])
				{
					v[y] = true;
					queue.push_back(y);
				}
			}
		}
	}
}
void dfs1(int x)
{
	v[x] = true;
	for (int i = 0; i < SIZE(G[x]); ++ i)
	{
		if (!v[G[x][i]])
		{
			dfs1(G[x][i]);
		}
	}
	list.push_back(x);
}
void dfs2(int x, int id)
{
	v[x] = true;
	group[x] = id;
	group_sz[id] ++;
	for (int i = 0; i < SIZE(rG[x]); ++ i)
	{
		if (!v[G[x][i]])
		{
			dfs2(G[x][i], id);
		}
	}
}
int inside[N + 5];
int main()
{
	int test_cnt;
	scanf("%d", &test_cnt);
	while (test_cnt --)
	{
		nodes_count = 0;
		new_node(0);
		scanf("%d%d", &n, &M);
		for (int i = 0; i < n; ++ i)
		{
			scanf("%s", buf);
			int l = strlen(buf), j = 0, idx = 0;
			for (; j < l; ++ j)
			{
				if (children[idx][buf[j] - 'a'] == -1)
				{
					children[idx][buf[j] - 'a'] = new_node(buf[j] - 'a');
				}
				idx = children[idx][buf[j] - 'a'];
				if (isword[idx]) break;
			}
			isword[idx] = true;
			memset(children[idx], -1, sizeof(children[idx]));
		}
		for (int i = 0; i < M; ++ i) if (children[0][i] == -1) children[0][i] = new_node(i);
/*		for (int i = 0; i < nodes_count; ++ i)
		{
			printf("%d : ", i);
			for (int j = 0; j < M; ++ j) printf("%d ", next_pos(i, j));
			puts("");
		}*/
		bfs();
		new_node_cnt = 0;
		my_bfs();
		for (int i = 1; i <= new_node_cnt; ++ i) v[i] = false;
		list.clear();
		for (int i = 1; i <= new_node_cnt; ++ i) if (!v[i]) dfs1(i);
		for (int i = 1; i <= new_node_cnt; ++ i) v[i] = false;
	//	printf("sz = %d\n", new_node_cnt);
	/*	for (int i = 1; i <= new_node_cnt; ++ i)
		{
			printf("%d :", i);
			for (int j = 0; j < G[i].size(); ++ j)
			{
				printf(" %d", G[i][j]);
			}
			puts("");
		}*/
		int tot_group = 0;
		for (int i = SIZE(list) - 1; i >= 0; -- i) if (!v[i]) dfs2(i, ++ tot_group);
		for (int i = 1; i <= tot_group; ++ i) inside[i] = 0;
		for (int i = 1; i <= new_node_cnt; ++ i)
		{
			for (int j = 0; j < SIZE(G[i]); ++ j)
			{
				if (group[i] == group[G[i][j]])
				{
					inside[group[i]] ++;
				}
			}
		}
		bool flag = 0;
		for (int i = 1; i <= tot_group; ++ i)
		{
			if (inside[i] > group_sz[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag) puts("Yes"); else puts("No");
	}
}


/*
0 : 1 3 
1 : 2 
2 : 
3 : 4 
4 : 
sz = 5
1 : 2 3
2 : 3
3 : 2
4 :
5 :
No
0 : 1 3 
1 : 2 
2 : 
3 : 
sz = 0
No

   */
