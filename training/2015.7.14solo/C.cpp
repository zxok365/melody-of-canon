#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
char str[1111111];
int f[1111111];
int nxt[1111111];
int c[1111111];
int beg[1111];
bool used[1111111];
int len;
long long ans;
bool bo;

void add(int x){
	for (int i = x; i > 0; i -= i & (-i)) c[i]++;
}
int find(int x){
	int now = 0;
	for (int i = x; i <= len; i += i & (-i)) now = now + c[i];
	return now;
}
void check(){
	int mid = len / 2, pp  = 0;
	for (int i = len, j = 0; i >= 1; i--)
	if (!used[i])
	{
		int x = beg[f[i]];
		if (x == i){
			//cout << '!' << endl;
			if (!bo){ans = -1; return;}
			bo = false;
			pp = i;
		} else
		{
			j++;
			ans = ans + x + find(x) - j;
			add(x);
			beg[f[i]] = nxt[x];
		}
		used[x] = 1;
		used[i] = 1;
	}
	if (pp) ans = ans + abs(pp + find(pp) - mid - 1);
}	
int main(){
	scanf("%s", str + 1);
	len = strlen(str + 1);
	for (int i = 1; i <= len; i++) f[i] = str[i] - 'A' + 1, used[i] = 0;
	for (int i = 1; i <= len; i++) nxt[i] = 0;
	for (int i = len; i >= 1; i--){
		int x = f[i];
		nxt[i] = beg[x];
		beg[x] = i;
	}
	//for (int i = 1; i <= len; i++) cout << nxt[i] << ' ';
	//cout << endl;
	bo = len % 2;
	//cout << bo << endl;
	ans = 0;
	check();
	cout << ans << endl;
}
