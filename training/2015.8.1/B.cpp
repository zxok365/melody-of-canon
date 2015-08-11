#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int f[511111],now[511111];
int tot3 = 0;
bool bo[511111];
int ans = 0;
int s[8111111];

priority_queue<int> Q;

bool ttry(int p){


//	cout << "~~~~~~" << endl;
//	cout << p << ':' << endl;



	int r = m;
	int tot = tot3;
	while (!Q.empty()) Q.pop();


//	for (int i = 1; i <= n; i++) cout << now[i] << ' ';
//	cout << endl;
//	cout << "tot: " << tot << endl;


	int tnow = p + 1;
	for (int i = 1; i <= n; i++) Q.push(now[i]);
	if (r % 2 == 1)
	{
		for (int i = 1; i <= p; i++)
		{
			if (tot == 0){
				if (Q.top() >= 3 && i < p)
				{
					int k = Q.top();
					Q.pop();
					Q.push(k - 3);
					tot += 2;
				} else if (Q.top() == 0) return true;
				else
				{
					tnow = i;
					break;
				}
			}
			tot--;
		}
		r -= 3;
	}
	for (int i = 1; i <= p; i++) s[i] = r / 2;
	for (int i = tnow; i <= p; i++) s[i]++;
	if (tot > 0)
		for (int i = 1; i <= p; i++)
		{
			int k = min(s[i] / 3, tot / 2);
			tot -= k * 2;
			s[i] -= 3 * k;
			if (tot <= 1) break;
		}
	if (tot > 0)
		for (int i = 1; i <= p; i++)
		{
			int k = min(s[i] / 2, tot);
			tot -= k;
			s[i] -= 2 * k;
			if (tot == 0) break;
		}
	if (tot != 0) return false;


//	cout << "Yes!" << endl;
	
	
	int now_ans = 0;
	while (!Q.empty()){
		now_ans += Q.top();
		Q.pop();
	}
	int max_ans = 0;
	for (int i = 1; i <= p; i++) max_ans += s[i];
	if (now_ans <= max_ans) return true; else return false;

		
		
}
int main(){
	scanf("%d%d", &n, &m);
	int l = 0;
	int r = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &f[i]);
		l = l + f[i];
		r = r + (f[i] + m - 1) / m;
	}
	l = l / m - 1; 
	for (int i = 1; i <= n; i++)
	{
		if (f[i] % 2 == 1) tot3++, f[i] -= 3;
		now[i] = f[i] / 2;
	}
	while (l + 1 < r){
		int mid = (l + r) / 2;
		if (ttry(mid)) r = mid; else l = mid;
	}
	printf("%d\n", r);
}
