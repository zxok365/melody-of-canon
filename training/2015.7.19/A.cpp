#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;

int flag;
LL a,b,k;
int totans;
int anst[11111],ans[11111];
inline void work1(LL x){
	if (!x){
		ans[totans++] = 0;
		return;
	}
	int totanst = 0;
	LL tt = x;
	while(tt){
		anst[totanst++] = tt % k;
		tt /= k;
	}
	for (int i = totanst - 1;i >= 0;i--)
		ans[totanst - i - 1] = anst[i];
	totans = totanst;
}
int pp;
int vis[11111];
int pos[11111];

inline void work2(LL A,LL B){
	if (!A) return;
	for (int i = 0;i <= (int)B;i++) vis[i] = 0;
	int cnt = totans - 1;
	while(1){
		LL ttt = A;
		if (vis[ttt]){
			flag = 1;
			pp = pos[ttt];
			return;
		}else{
			vis[ttt] = 1;
			pos[ttt] = ++cnt;
		}
		LL tt = A * k;
	//	cerr<<tt<<endl;
		if (tt < B){
		/*
			if (vis[ttt]){
				flag = 1;
				pp = pos[ttt];
				return;
			}
			vis[ttt] = 1;
			pos[ttt] = ++cnt;
		*/
			A = tt;
			ans[totans++] = 0;
		}else{
			ans[totans++] = tt / B;
			A = tt % B;
		}
		if (!A) break;
	}
}

int main()
{
	while(1){
		scanf("%lld%lld",&a,&b);
		if (!a && !b) break;
		scanf("%lld",&k);
		flag = 0;
		pp = -1;
		totans = 0;
		if (a == b){
			puts("1");
		}else{
			LL pre = a / b;
			work1(pre);
			int p = totans;
			LL A = a % b,B = b;
			work2(A,B);
			if (flag){
				for (int i = 0;i < totans;i++){
					if (i == p) putchar('.');
					int x = ans[i];
					if (i == pp) putchar('(');
					if (x <= 9) putchar('0' + x);
					else putchar('A' + x - 10);
				}
				puts(")");
			}else{
				for (int i = 0;i < totans;i++){
					if (i == p) putchar('.');
					int x = ans[i];
					if (x <= 9) putchar('0' + x);
					else putchar('A' + x - 10);
				}
				puts("");
			}
		}
	}

	return 0;
}
