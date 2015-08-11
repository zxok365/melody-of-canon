#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define col col234e134e

char s[555][555];
int n;
int sumc[555], sumr[555], ans[1005];
pair<int, int> row[505], col[505];
char ansc[1005];



bool cmp(const pair<int, int> &p,const pair<int ,int> &q){
	if (p.first != q.first) return p.first < q.first;
	return p.second > q.second;
}
bool solve() {
	int times = n * 2;
	int cur1 = 1;
	int cur2 = 1;
	int hang = 0;
	int lie = 0;
	int sum = 0;
	for (int i = 1; i <= n; i ++) row[i] = make_pair(sumr[i], i);
	for (int i = 1; i <= n; i ++) col[i] = make_pair(sumc[i], i);
	sort(row + 1, row + n + 1, cmp);
	sort(col + 1, col + n + 1, cmp);
	while (cur1 != n + 1 && cur2 != n + 1) {
		if (row[cur1].first == lie) {
			ans[++sum] = row[cur1].second;
			ansc[sum] = 'R';
			cur1++;
			hang++;
		} else if (col[cur2].first == hang) {
			ans[++sum] = col[cur2].second;
			ansc[sum] = 'C';
			cur2++;
			lie++;
		} else return false;
	}
	for (int i = sum; i > 1; i --) {
		printf("%c%d ", ansc[i], ans[i]);
	}
	printf("%c%d\n", ansc[1], ans[1]);
	return true;
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%s", s[i]);
		for (int i = 1; i <= n; i ++) sumr[i] = sumc[i] = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 0; j < n; j ++) {
				if (s[i][j] == 'X') sumc[j + 1]++;
					else sumr[i]++;
			}
		if (!solve()) puts("No solution");
	}
	return 0;
}
