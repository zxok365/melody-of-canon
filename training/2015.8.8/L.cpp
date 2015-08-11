#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define PII pair<int, int>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		vector<PII> student;
		int n, L;
		scanf("%d%d", &n, &L);
		for (int i = 0; i < n; ++ i)
		{
			int a, b, c;
			scanf("%d:%d:%d", &a, &b, &c);
			student.push_back(PII(a * 3600 + b * 60 + c, i));
		}
		sort(student.begin(), student.end());
		int cur = -100000000;
		vector<int> ans;
		for (int i = 0; i < n; ++ i)
		{
			if (student[i].first >= cur + L)
			{
				ans.push_back(student[i].second + 1);
				cur = student[i].first;
			}
		}
		printf("%d\n", ans.size());
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++ i) printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
	}
}

