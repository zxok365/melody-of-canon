#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<string>
#include<cstring>
using namespace std;
char a[1111],b[1111];
int Hidden[33],Declared[33];
int Total[33];
string p,q;
int ans;

int fix(int x){
	return (x - 1) % 9 + 1;
}
int Analyize_Trans(int p[], string &q){
	for (int i = 1; i <= 27; i++)
		p[i] = 0;
	if (q == "NONE")
		return 0;
	int k = (int)q.size();
	for (int i = 0; i < k; i += 2)
	{
		int v = q[i] - '0';
		if (q[i + 1] == 'B') v += 9;
		if (q[i + 1] == 'M') v += 18;
		p[v]++;
	}
	return k / 2;
}

int Suit(int p[]){
	int now = 0;
	for (int i = 1; i <= 27; i++)
		if (p[i])
			now |= 1 << ((i - 1) / 9);
	//	cout << now << endl;
	if (now == 7) return 3;
	if (now == 1 || now == 2 || now == 4) return 1;
	return 2;
}

int Gang(int p[]){
	int now = 0;
	for (int i = 1; i <= 27; i++)
		if (p[i] == 4) now++;
	return now;
}
int SevenCouple(int p[]){
	int bo = 2;
	for (int i = 1; i <= 27; i++)
	{
		if (p[i] == 1 || p[i] == 3) return 0;
		if (p[i] > 0 && i % 9 != 1 && i % 9 != 0)
			bo = 1;
	}
	return bo;
}
int Min(pair< bool, pair<int, int> > p, pair< bool, pair<int, int> > q){
	if (!p.first || !q.first) return 0;
	return 1 + min(p.second.first, q.second.first) + min(p.second.second, q.second.second);
}
pair< bool, pair<int, int> > Normal1(int q[],int r){
	int Pengpengho = 3;
	if (r % 9 != 2 && r % 9 != 5 && r % 9 != 8) Pengpengho = 1;
	int Qingyaojiu = 2;
	if (r % 9 != 1 && r % 9 != 0) Qingyaojiu = 0;
	int p[33];
	bool bo = true;
	for (int i = 1; i <= 27; i++)
		p[i] = q[i];
	for (int i = 1; i <= 27; i++)
		if (p[i] > 0){
			if (p[i] < 3)
			{
				Pengpengho = 0;
				if (fix(i) > 7 || !(p[i] && p[i + 1] && p[i + 2]))
				{
					bo = false;
					break;
				}
				p[i]--;
				p[i + 1]--;
				p[i + 2]--;
				if (i % 9 != 1 && i % 9 != 7)
					Qingyaojiu = 0;
				i--;
			}
			else
			{
				if (i % 9 != 2 && i % 9 != 5 && i % 9 != 8) Pengpengho = min(Pengpengho, 1);
				if (i % 9 != 1 && i % 9 != 0) Qingyaojiu = 0;
				p[i] -= 3;
				i--;
				continue;
			}
		}
	return make_pair(bo, make_pair(Pengpengho, Qingyaojiu));
}


pair< bool, pair<int, int> > Normal2(int q[],int r){
	int Pengpengho = 3;
	if (r % 9 != 2 && r % 9 != 5 && r % 9 != 8) Pengpengho = 1;
	int Qingyaojiu = 2;
	if (r % 9 != 1 && r % 9 != 0) Qingyaojiu = 0;
	int p[33];
	bool bo = true;

	for (int i = 1; i <= 27; i++)
		p[i] = q[i];
	for (int i = 1; i <= 27; i++)
		if (p[i] > 0){
			if (fix(i) <= 7 && p[i] && p[i + 1] && p[i + 2])
			{
				//		cout << i << ' ' << i + 1 << ' ' << i + 2 << endl;
				Pengpengho = 0;
				p[i]--;
				p[i + 1]--;
				p[i + 2]--;
				if (i % 9 != 1 && i % 9 != 7)
					Qingyaojiu = 0;
				i--;
				//		cout << i << endl;
			}
			else
			{
				if (p[i] < 3)
				{	
					bo = false;
					break;
				}
				else
				{
					if (i % 9 != 2 && i % 9 != 5 && i % 9 != 8) Pengpengho = min(Pengpengho, 1);
					if (i % 9 != 1 && i % 9 != 0) Qingyaojiu = 0;
					p[i] -= 3;
					i--;
					continue;
				}
			}
		}
	//	cout << Pengpengho << ' '<< Qingyaojiu << endl;
	return make_pair(bo, make_pair(Pengpengho, Qingyaojiu));
}
void outp(int x, int tot_ans){
	printf("%d%c: %d\n", fix(x), (x <= 9) ? ('D') : ((x > 18) ? ('M') : ('B')), tot_ans);
}
void ttry(){
	scanf("%s %s", a, b);
	p = a;
	q = b;
	//	cout<< q << endl;
	int tot = 0;
	tot += Analyize_Trans(Hidden, p);
	tot += Analyize_Trans(Declared, q);
	for (int i = 1; i <= 27; i++)
		Total[i] = Hidden[i] + Declared[i];
	bool bo = false;
	for (int i = 1; i <= 27; i++)
		if (Declared[i] == 4)
		{
			Declared[i]--;
			tot--;
		}
	//cout << tot << endl;
	if (tot == 13)
	{
		for (int i = 1; i <= 27; i++)
			if(Total[i] < 4)
			{
				Total[i]++;
				Hidden[i]++;
				ans = 0;
				if (Suit(Total) != 3)
				{
					int addition = Gang(Total) + (Suit(Total) == 1) * 2;
					//	cout << addition << endl;
					//	cout << addition << endl;
					if (q == "NONE") ans = SevenCouple(Hidden) * 2;
					if (ans > 0) ans++;
					//		cout << ans << endl;
					for (int j = 1; j <= 27; j++)
						if (Hidden[j] >= 2)
						{
							Hidden[j] -= 2;
							ans = max(ans, Min(Normal1(Hidden, j % 9), Normal1(Declared,j % 9)));
							ans = max(ans, Min(Normal2(Hidden, j % 9), Normal1(Declared,j % 9)));
							Hidden[j] += 2;
						}
					if (ans != 0)
					{
						bo = true;
						outp(i, ans + addition);
					}
				}
				Total[i]--;
				Hidden[i]--;
			}
	}
	if (bo == false)
		printf("NONE\n");
}
int main(){
	int test_case = 0;
	scanf("%d", &test_case);
	for (int time = 1; time <= test_case; time++)
	{
		printf("Case #%d:\n", time);
		ttry();
	}
}

